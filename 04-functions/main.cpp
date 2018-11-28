#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void PrintTableHead()
{
	cout << string(68, '-') << endl;
	cout << "|" << setw(7) << "x" << setw(7);
	cout << "|" << setw(19) << " arcctg(x) (mine) ";
	cout << "|" << setw(19) << "arcctg(x) (cmath) ";
	cout << "|" << setw(11) << "iterations" << setw(3) << "|\n";
	cout << string(68, '-') << endl;
}

double ComputeSeries(double x, double eps, int &n, const int kMaxIters)
{
	double arcctg = M_PI_2, nth_term;
	for (n = 0; n <= kMaxIters; n++)
	{
		nth_term = pow(-1, n + 1) * pow(x, 2 * n + 1) / (2 * n + 1);
		arcctg += nth_term;
		if (abs(nth_term) < eps) break;
	}
	return arcctg;
}

void PrintTableRow(double x, double func, int n, const int kMaxIters) {
	cout << "|" << setw(11) << x << setw(3) << "|";
	if (n <= kMaxIters)
		cout << setw(14) << func << setw(6) << "|";
	else
		cout << " limit is exceeded |";
	cout << setw(14) << M_PI_2 - atan(x) << setw(6) << "|";
	cout << setw(7) << n << setw(7) << "|\n";
}

int main() {
	const int kMaxIters = 1000000;

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

	if (dx <= 0)
	{
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (eps <= 0)
	{
		cout << "\nInvalid eps. Must be: eps > 0.\n";
	}
	else if (xn > xk)
	{
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else
	{
		PrintTableHead();

		cout << fixed;
		cout.precision(6);

		for (; xn <= xk; xn += dx)
		{
			int n;
			double arcctg = ComputeSeries(xn, eps, n, kMaxIters);
			PrintTableRow(xn, arcctg, n, kMaxIters);
		}
		cout << string(68, '-');
	}

	return 0;
}