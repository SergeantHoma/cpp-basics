#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;


int main() {
	double a, b, c, xn, xk, dx, x, f;
	const double kEps = 1e-15;

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
	cout << "Enter dx , where dx>0: ";
	cin >> dx;
	if (dx > kEps)
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
			if ((x < 5) && (abs(c) < kEps))
			{
				f = a * pow(x, 2) - b;
			}
			else
			{
				if ((x > 5) && (abs(c) < 0))
				{
					if (abs(x)> kEps)
						f = (x - a) / x;
					else
					{
						cout << "|" << setw(11) << x << setw(7);
						cout << "|" << "  division by 0  |\n";
						x += dx;
						continue;
					}
				}
				else
					if (abs(c)>kEps)
					{
						f = (-x) / c;
					}
			}
			cout << "|" << setw(11) << x << setw(7) << "|";

			if (((int(a) | int(b)) % (int(a) | int(c))) != 0)
				cout << setw(11) << f << setw(7);
			else
				cout << setw(9) << int(f) << setw(9);

			cout << "|" << endl;

			x += dx;
		
		}
		cout << string(37, '-') << endl;
	}
	else
		cout << "\nError dx !\n";
	return 0;
}