#include <iostream>
#include <fstream>
#include <clocale>
#include "Header.h"

using namespace std;

int main() {
	setlocale(LC_CTYPE, "Russian");

	Vector3D c1(5, 2, 4);
	Vector3D c2(3, 6, 1);

	c1.output();
	c2.output();


	Vector3D c4;
	c4 = c2 + c1;

	Vector3D c5;
	c5 = c2 - c1;

	Vector3D c6;
	c6 = c2.scalar(c1);

	Vector3D c7;
	c7 = c1 * c2;



	if (c1 == c2) { cout << " Они не равны " << endl; }
	if (c1 != c2) { cout << " Они не равны " << endl; }


	system("pause");
}