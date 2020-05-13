#include <iostream>
#include <clocale>
#include "ProcCenter.h"
#include "Bankomat.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	ProcCenter* procCenter = new ProcCenter();

	ProcCenter::ClientData clientData;
	clientData.setAmount(50000);
	clientData.setCardNumber(235);
	clientData.setPin(1234);
	clientData.setFio("������ � �");
	procCenter->getClientData()->push_back(clientData);

	ProcCenter::ClientData clientData2;
	clientData2.setAmount(150000);
	clientData2.setPin(4321);
	clientData2.setCardNumber(3421);
	clientData2.setFio("������ � �");
	procCenter->getClientData()->push_back(clientData2);

	Bankomat bankomat(procCenter);

	bankomat.takeCard();
	bankomat.findClientByCardNumber(235);
	bankomat.ckeckPin(1234);
	bankomat.giveCash(17400);
	bankomat.printClientStatus();
	bankomat.returnCard();

	system("pause");
}