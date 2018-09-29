#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, z1, z2;
	cout << endl << "Enter a:  " << endl;
	cin >> a;
	z1 = pow(cos(3 / 8 * M_PI - a / 4), 2) - pow(cos(11 / 8 * M_PI + a / 4), 2);
	z2 = sqrt(2) / 2 * sin(a / 2);
	cout << "\nz1 = " << z1 << "\nz2 = " << z2 << endl;

	return 0;
}