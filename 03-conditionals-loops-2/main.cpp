#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const int kMaxIter = 1000000;

	double xn, xk, dx, eps;
	cout << "-1 <= x <= 1\n";
	cout << "Enter xn: ";
	cin >> xn;
	cout << "Enter xk >= xn: ";
	cin >> xk;
	cout << "Enter dx > 0: ";
	cin >> dx;
	cout << "Enter eps > 0: ";
	cin >> eps;

	if (abs(xn) <= 1 && abs(xk) <= 1 && dx > 0 && eps > 0 && xn <= xk)
	{
		cout << string(68, '-') << endl;
		cout << "|" << setw(7) << "x" << setw(7);
		cout << "|" << setw(19) << " arcctg(x) (mine) ";
		cout << "|" << setw(19) << "arcctg(x) (cmath) ";
		cout << "|" << setw(11) << "iterations" << setw(3) << "|\n";
		cout << string(68, '-') << endl;

		cout << fixed;
		cout.precision(6);

		for (double x = xn; x <= xk; x += dx)
		{
			int n;
			double arcctg = M_PI_2, nth_term;
			for (n = 0; n <= kMaxIter; n++)
			{
				nth_term = pow(-1, n + 1) * pow(x, 2 * n + 1) / (2 * n + 1);
				arcctg += nth_term;
				if (abs(nth_term) < eps) break;
			}

			cout << "|" << setw(11) << x << setw(3) << "|";
			if (n <= kMaxIter)
				cout << setw(14) << arcctg << setw(6);
			else
				cout << " limit is exceeded ";
			cout << "|" << setw(14) << M_PI_2 - atan(x) << setw(6);
			cout << "|" << setw(7) << n << setw(7) << "|\n";
		}
		cout << string(68, '-');
	}
	else
	{
		cout << "Error!\n";
	}

	return 0;
}