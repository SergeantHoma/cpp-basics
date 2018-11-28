#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	const double kEps = 1e-15;

	double a, b, c, xn, xk, dx;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	cout << "Enter xn: ";
	cin >> xn;
	cout << "Enter xk >= xn: ";
	cin >> xk;
	cout << "Enter dx, where dx > 0: ";
	cin >> dx;

	if (dx > 0 && xk >= xn)
	{
		cout << endl << string(37, '-') << endl;
		cout << "|" << setw(9) << "x" << setw(9);
		cout << "|" << setw(9) << "f" << setw(9) << "|";
		cout << endl << string(37, '-') << endl;

		cout << fixed;
		cout.precision(3);

		double x = xn;
		while (x <= xk)
		{
			cout << "|" << setw(11) << x << setw(7) << "|";

			double f;
			if ((x < 5) && (abs(c) > kEps))
			{
				f = -a * pow(x, 2) - b;
			}
			else if ((x > 5) && (abs(c) < kEps))
			{
				f = (x - a) / x;
			}
			else
			{
				if (abs(c) > kEps)
				{
					f = (-x) / c;
				}
				else
				{
					cout << "  division by 0  |\n";
					x += dx;
					continue;
				}
			}

			int ac = static_cast<int>(a);
			int bc = static_cast<int>(b);
			int cc = static_cast<int>(c);

			if (((ac | bc) ^ (ac | cc)) != 0)
				cout << setw(11) << f << setw(7);
			else
				cout << setw(9) << int(f) << setw(9);
			cout << "|" << endl;

			x += dx;
		}

		cout << string(37, '-') << endl;
	}
	else
	{
		cout << "\nError dx or xk!\n";
	}
	return 0;
}