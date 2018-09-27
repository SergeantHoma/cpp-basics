#include <iostream>
#include <cmath>

#define PI 3.14159265
using namespace std;

int main() {
	double a, z, z1;
	cout << endl << "¬ведите переменную a " << endl;
	cin >> a;
	z = pow(cos(3 / 8 * PI - a / 4), 2) - pow(cos(11 / 8 * PI + a / 4), 2);
	z1 = sqrt(2) / 2 * sin(a / 2);
	cout << "z1= " << z << "z2= " << z1;

	return 0;
}