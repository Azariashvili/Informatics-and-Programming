#pragma once
#include <string>
#include <vector>

class ProcCenter
{
public:
	class ClientData {
	private:
		short cardNumber = 0;
		std::string fio;
		int amount = 0;
		short pin = 0;
	public:
		ClientData() {};

		short getCardNumber() {
			return cardNumber;
		}

		void setCardNumber(short value) {
			if (value > 0 && value < 10000)
			{
				cardNumber = value;
			}
		}

		std::string getFio() {
			return fio;
		}

		void setFio(std::string value) {
			fio = value;
		}

		int getAmount() {
			return amount;
		}

		void setAmount(int value) {
			amount = value;
		}

		short getPin() {
			return pin;
		}

		void setPin(short value) {
			if (value >= 0 && value < 10000) {
				pin = value;
			}
		}
	};
	ProcCenter() {
		this->clients = new std::vector<ProcCenter::ClientData>();
	};

	std::vector<ClientData>* getClientData() {
		return clients;
	}

	void setClientData(std::vector<ClientData> *clients) {
		this->clients = clients;
	}

private:
	std::vector<ProcCenter::ClientData> *clients;
};
