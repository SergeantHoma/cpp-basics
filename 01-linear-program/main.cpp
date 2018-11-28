#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	double a;
	cout << "Enter a: ";
	cin >> a;

	double z1 = pow(cos(3.0 / 8.0 * M_PI - a / 4.0), 2) - 
		pow(cos(11.0 / 8.0 * M_PI + a / 4.0), 2);
	double z2 = sqrt(2.0) / 2.0 * sin(a / 2.0);

	cout << "\nz1 = " << z1 << "\nz2 = " << z2 << endl;

	return 0;
}