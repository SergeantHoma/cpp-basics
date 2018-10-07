#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	double a, b, c, xn, xk, dx, x, f;
	const double EPS = 1e-15;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter xn: ";
	cin >> xn;
	cout << "Enter xk: ";
	cin >> xk;
	cout << "Enter dx: ";
	cin >> dx;
	if (abs(dx) > EPS)
	{
		cout << endl << string(37, '-') << endl;
		cout << "|" << setw(9) << "x" << setw(9);
		cout << "|" << setw(9) << "f" << setw(9) << "|";
		cout << endl << string(37, '-') << endl;

		cout << fixed;
		cout.precision(3);

		x = xn;

		while(x<=xk)
		{
			if ((x < 5) && (c != 0))
			{
				f = a * (pow(x, 2)) - b;
			}
			else
			{
				if ((x > 5) && (c = 0))
				{
					if (x != 0)
						f = ((x - a) / x);
					else
					{
						cout << "|" << setw(11) << x << setw(7);
						cout << "|" << "  division by 0  |\n";
						x += dx;
						continue;
					}
				}
				else
					f = ((-x) / c);
			}
			cout << "|" << setw(11) << x << setw(7) << "|";

			if (((int(a) | int(b)) & (int(a) | int(c))) != 0)
				cout << setw(11) << f << setw(7);
			else
				cout << setw(9) << int(f) << setw(9);

			cout << "|" << endl;

			x += dx;
		
		}
		cout << string(37, '-') << endl;
	}
	else
		cout << "\nError!\n";
	return 0;
}