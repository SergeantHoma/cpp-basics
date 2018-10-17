#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;


int main() {
	const int kMaxIter = 500;
	double X1, X2, dX, Eps;
	cout << fixed;
	cout.precision(6);
	cout << "Enter X start: ";
	cin >> X1;
	cout << "Enter X end: ";
	cin >> X2;
	cout << "Enter dX: ";
	cin >> dX;
	cout << "Enter EPS: ";
	cin >> Eps;

	if (abs(X1) <= 1 && abs(X2) <= 1 && abs(dX) > kMaxIter)  {


		cout << string(60, '-') << "\n|"
			<< setw(8) << "X" << setw(7)
			<< "|" << setw(12) << "arcctg(x)"
			<< setw(3) << "|" << setw(12)
			<< "arcctg(x)" << setw(3) << "|" 
			<< setw(12) << "Iterations" << setw(3) << "|\n"
						<< string(60, '-') << endl;
		double arcctg1, arcctg2;

		for (double x = X1; x <= X2; x += dX) {

			arcctg1 = 0, arcctg2 = M_PI_2;

			for (int n = 0; n < kMaxIter; n++) {

				arcctg2 += (pow(-1, n + 1)*pow(x, 2 * n + 1)) / (2 * n + 1);

				if (abs(arcctg2 - arcctg1) < Eps)
				{
					x = atan(x);
					x = M_PI_2 - x;

					cout << "|" << setw(14) << x
						<< "|" << setw(14) << arcctg2 << "|" << setw(14) << x
						<< "|" << setw(13) << n << "|\n";
					continue;
				}


				if (kMaxIter - n < 2) {
					cout << "small EPS";
					return 2;
				}

				arcctg1 = arcctg2;
			}
		}
		cout << string(60, '-');
	}

	else {
		cout << "Error, Invalid values";
	}
	return 0;
}