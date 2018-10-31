#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

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
	double nth_term, arc2 = M_PI_2;
	for (n = 0; n <= kMaxIters; n++)
	{
		nth_term = pow(-1, n + 1) * pow(x, 2 * n + 1) / (2 * n + 1);
		arc2 += nth_term;
		if (abs(nth_term) < eps) break;
	}
	return arc2;
}


void PrintTableRow(double x, double func, int n, const int kMaxIter)
{
	cout << "|" << setw(12) << x << setw(3) << "|" << setw(12);
	if (n < kMaxIter)
		cout << func << setw(4) << "|";
	else
		cout << "   max iters   |";
	cout << setw(11) << atan(x) << setw(4) << "|";
	cout << setw(7) << n << setw(7) << "|\n";
}


int main() {
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

	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (eps <= 0) {
		cout << "\nInvalid eps. Must be: eps > 0.\n";
	}
	else if (abs(xn) > 1) {
		cout << "\nInvalid xn. Must be: xn > 1.\n";
	}
	else if (xn > xk) {
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else {
		PrintTableHead();

		cout << fixed;
		cout.precision(6);

		for (double x = xn; x <= xk; x += dx) {
			int n;
			double arcctg = ComputeSeries(x, eps, n, kMaxIter);
			PrintTableRow(x, arcctg, n, kMaxIter);
		}
		cout << string(60, '-');
	}

	return 0;
}