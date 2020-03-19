#include <iostream>
#include <fstream>
#include <clocale>
#include <cmath>
#include "Header.h"

#define PI 3.14159265

using namespace std;

Vector3D::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(double _x, double _y, double _z) {
	x = _x;
	y = _y;
	z = _z;
}


Vector3D Vector3D::operator+(const Vector3D c) {
	double xx = x + c.x;
	double yy = y + c.y;
	double zz = z + c.z;
	cout << "—умма векторов равна:" << xx << ", " << yy << ", " << zz << endl;
	return c;
}

Vector3D Vector3D::operator-(const Vector3D c) {
	double xx = x - c.x;
	double yy = y - c.y;
	double zz = z - c.z;
	cout << "–азность векторов равна:" << xx << ", " << yy << ", " << zz << endl;
	return c;
}

Vector3D Vector3D::scalar(const Vector3D c) {
	double k;
	cout << "¬ведите угол между векорами: ";
	cin >> k;
	double sc = (x * c.x + y * c.y + z * c.z)*cos(k*PI / 180);
	cout << "—кал€рное произведение векторов равно: " << sc << endl;
	return c;
}

Vector3D Vector3D::operator*(const Vector3D c) {
	double k;
	cout << "¬ведите угол между векорами: ";
	cin >> k;
	double sc = (x * c.x + y * c.y + z * c.z)*cos(k*PI / 180);
	double xx = sc * x;
	double yy = sc * y;
	double zz = sc * z;
	cout << "”множение векторов на скал€рное произведение равно: " << xx << ", " << yy << ", " << zz << endl;
	return c;
}

Vector3D Vector3D::length(const Vector3D c) {
	double S = sqrt(x * x + y * y + z * z);
	double S1 = sqrt(c.x * c.x + c.y * c.y + c.z * c.z);
	cout << "ƒлина первого вектора: " << S << endl;
	cout << "ƒлина второго вектора: " << S1 << endl;
	return c;
}

bool Vector3D::operator==(const Vector3D &c) {
	if (S == S1)  return true;
	else return false;
}

bool Vector3D::operator!=(const Vector3D &c) {
	if (S != S1) return true;
	else return false;
}

Vector3D::~Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

void Vector3D::output()
{
	cout << x << " " << y << " " << z << endl;
}

std::ostream& operator<<(std::ostream& stream, const Vector3D& c) {
	stream << c.S;
	if (c.S1 > 0) { stream << " + " << c.S1 << "i"; }
	else if (c.S1 < 0) { stream << " - " << -c.S1 << "i"; }
	return stream;
}

std::istream& operator>>(std::istream& stream, Vector3D& c) {
	stream >> c.S >> c.S1;
	return stream;
}