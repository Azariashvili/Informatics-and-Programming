#pragma once
#include "ProcCenter.h"


class Bankomat
{
private:
	ProcCenter* procCenter;
	int currentClient = -1;
	short cassette100;
	short cassette200;
	short cassette500;
	short cassette1000;
	short cassette2000;
	short cassette5000;
	const short initCount = 2000;
	const short capacity = 80;
	const short countBanknotePerOperation = 40;
	bool Busy = false;
	bool Check = false;
	short badPinInput = 0;
public:
	Bankomat(ProcCenter* procCenter);

	short getCassette100() {
		return cassette100;
	}

	void setCassette100(short value) {
		if (value <= initCount)
			cassette100 = value;
	}

	short getCassette200() {
		return cassette200;
	}

	void setCassette200(short value) {
		if (value <= initCount)
			cassette200 = value;
	}

	short getCassette500() {
		return cassette500;
	}

	void setCassette500(short value) {
		if (value <= initCount)
			cassette500 = value;
	}

	short getCassette1000() {
		return cassette1000;
	}

	void setCassette1000(short value) {
		if (value <= initCount)
			cassette1000 = value;
	}

	short getCassette2000() {
		return cassette2000;
	}

	void setCassette2000(short value) {
		if (value <= initCount)
			cassette2000 = value;
	}

	short getCassette5000() {
		return cassette5000;
	}

	void setCassette5000(short value) {
		if (value <= initCount)
			cassette5000 = value;
	}

	bool takeCard();

	bool returnCard();

	void findClientByCardNumber(short cardNumber);

	bool ckeckPin(short Pin);

	void printClientStatus();

	bool giveCash(int amount);

	bool takeCash(int banknotes[6]);
};
