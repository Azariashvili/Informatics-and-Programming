#include <iostream>
#include <fstream>

using namespace std;

class Vector3D {
public:
	Vector3D();
	Vector3D(double _x, double _y, double _z);

	~Vector3D();

	void output();
	Vector3D operator+(const Vector3D c);
	Vector3D operator-(const Vector3D c);

	Vector3D scalar(const Vector3D c);
	Vector3D operator*(const Vector3D c);

	Vector3D length(const Vector3D c);
	bool operator==(const Vector3D &c);
	bool operator!=(const Vector3D &c);

	friend std::ostream& operator<<(std::ostream& stream, const Vector3D& c);
	friend std::istream& operator>>(std::istream& stream, Vector3D& c);

private:
	double x;
	double y;
	double z;
	double S;
	double S1;
};