#include "Bankomat.h"
#include <clocale>
#include <iostream>

Bankomat::Bankomat(ProcCenter *procCenter) {
	cassette100 = initCount * capacity / 100;
	cassette200 = cassette100;
	cassette500 = cassette100;
	cassette1000 = cassette100;
	cassette2000 = cassette100;
	cassette5000 = cassette100;
	this->procCenter = procCenter;
}

bool Bankomat::takeCard() {
	if (Busy) {
		std::cout << "Банкомат занят другой картой" << std::endl;
		return false;
	}
	std::cout << "Карта уже взята" << std::endl;
	Busy = true;
	return true;
}

bool Bankomat::returnCard() {
	if (Busy && badPinInput < 3) {
		Check = false;
		Busy = false;
		currentClient = -1;
		std::cout << "Заберите карту" << std::endl;
		return true;;
	}
	std::cout << "Ошибка выдачи карты" << std::endl;
	return false;
}

void Bankomat::findClientByCardNumber(short cardNumber) {
	if (!Check && !Busy)
	{
		std::cout << "Не разрешено" << std::endl;
		return;
	}
	for (int i = 0; i < procCenter->getClientData()->size(); i++) {
		if (procCenter->getClientData()->at(i).getCardNumber() == cardNumber)
		{
			std::cout << "Клиент найден" << std::endl;
			currentClient = i;
			return;
		}
	}
	std::cout << "Ошибка, клиент не найден" << std::endl;
}

bool Bankomat::ckeckPin(short Pin)
{
	if (currentClient == -1 && !Busy)
	{
		std::cout << "Ошибка, проверьте пин-код" << std::endl;
		return false;
	}
	Check = procCenter->getClientData()->at(currentClient).getPin() == Pin;
	if (!Check) {
		badPinInput++;
		if (badPinInput >= 3) {
			std::cout << "Вы ввели три раза пин-код не верно. Карта заблокирована." << std::endl;
			Busy = false;
			badPinInput = 0;
		}
		std::cout << "Неверный пин-код" << std::endl;
	}
	else {
		std::cout << "Пин-код верный" << std::endl;
		badPinInput = 0;
	}
	return Check;
}

void Bankomat::printClientStatus()
{
	if (currentClient == -1 && !Check && !Busy)
	{
		std::cout << "Ошибка поиска информации о клиенте" << std::endl;
		return;
	}
	if (Check)
	{
		std::cout << "Информация о клиенте" << std::endl;
		std::cout << "ФИО : " << procCenter->getClientData()->at(currentClient).getFio() << std::endl;
		std::cout << "Номер карты : " << procCenter->getClientData()->at(currentClient).getCardNumber() << std::endl;
		std::cout << "Сумма : " << procCenter->getClientData()->at(currentClient).getAmount() << std::endl;
		std::cout << "================================================" << std::endl;
	}
	else {
		std::cout << "Введите пин-код" << std::endl;
	}
}

bool Bankomat::giveCash(int amount)
{
	if (currentClient == -1 && !Check && !Busy)
	{
		std::cout << "Ошибка выдачи наличных" << std::endl;
		return false;
	}
	if (Check)
	{
		if (procCenter->getClientData()->at(currentClient).getAmount() >= amount) {
			int banknotes[6]{ 0,0,0,0,0,0 };
			int amountTemp = amount;
			banknotes[0] = amountTemp / 5000;
			if (banknotes[0] > cassette5000) {
				banknotes[0] = cassette5000;
			}
			amountTemp -= banknotes[0] * 5000;
			banknotes[1] = amountTemp / 2000;
			if (banknotes[1] > cassette2000) {
				banknotes[1] = cassette2000;
			}
			amountTemp -= banknotes[1] * 2000;
			banknotes[2] = amountTemp / 1000;
			if (banknotes[2] > cassette1000) {
				banknotes[2] = cassette1000;
			}
			amountTemp -= banknotes[2] * 1000;
			banknotes[3] = amountTemp / 500;
			if (banknotes[3] > cassette500) {
				banknotes[3] = cassette500;
			}
			amountTemp -= banknotes[3] * 500;
			banknotes[4] = amountTemp / 200;
			if (banknotes[4] > cassette200) {
				banknotes[4] = cassette200;
			}
			amountTemp -= banknotes[4] * 200;
			banknotes[5] = amountTemp / 100;
			if (banknotes[5] > cassette100) {
				banknotes[5] = cassette100;
			}
			amountTemp -= banknotes[5] * 100;
			if (amountTemp != 0)
			{
				std::cout << "Банкомат не может выдать эту сумму. Введите другую" << std::endl;
				return false;
			}
			else
			{
				procCenter->getClientData()->at(currentClient)
					.setAmount(procCenter->getClientData()->at(currentClient).getAmount() - amount);
				cassette5000 -= banknotes[0];
				cassette2000 -= banknotes[1];
				cassette1000 -= banknotes[2];
				cassette500 -= banknotes[3];
				cassette200 -= banknotes[4];
				cassette100 -= banknotes[5];
				std::cout << "5000 - " << banknotes[0] << std::endl
					<< "2000 - " << banknotes[1] << std::endl
					<< "1000 - " << banknotes[2] << std::endl
					<< "500 - " << banknotes[3] << std::endl
					<< "200 - " << banknotes[4] << std::endl
					<< "100 - " << banknotes[5] << std::endl
					<< "Операция успешно проведена." << std::endl;
				return true;
			}
		}
		else
		{
			std::cout << "Недостаточно средств" << std::endl;
			return false;
		}
	}
	else {
		std::cout << "Введите пин-код" << std::endl;
		return false;
	}
}

bool Bankomat::takeCash(int banknotes[6])
{
	if (currentClient == -1 && !Check && !Busy)
	{
		std::cout << "Ошибка, заберите наличные" << std::endl;
		return false;
	}
	if (cassette5000 + banknotes[0] > initCount || cassette2000 + banknotes[1] > initCount ||
		cassette1000 + banknotes[2] > initCount || cassette500 + banknotes[3] > initCount ||
		cassette200 + banknotes[4] > initCount || cassette100 + banknotes[5] > initCount)
	{
		std::cout << "Кассета полная. Ошибка" << std::endl;
		return false;
	}
	int amount = banknotes[0] * 5000 + banknotes[1] * 2000 + banknotes[2] * 1000 + banknotes[3] * 500 +
		banknotes[4] * 200 + banknotes[5] * 100;
	procCenter->getClientData()->at(currentClient)
		.setAmount(procCenter->getClientData()->at(currentClient).getAmount() + amount);
	cassette5000 += banknotes[0];
	cassette2000 += banknotes[1];
	cassette1000 += banknotes[2];
	cassette500 += banknotes[3];
	cassette200 += banknotes[4];
	cassette100 += banknotes[5];
	std::cout << "Наличные сняты успешно" << std::endl;
	return true;
}
