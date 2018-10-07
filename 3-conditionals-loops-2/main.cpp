#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;


int main() {
	const int MaxIter = 500;
	double X1, X2, dX, Eps, f;
	cout << "Enter X start: ";
	cin >> X1;
	cout << "Enter X end: ";
	cin >> X2;
	cout << "Enter dX: ";
	cin >> dX;
	cout << "Enter EPS: ";
	cin >> Eps;

	if (dX > 0 && X2 > 1 && abs(X1) <= 1) {


		cout << string(60, '-') << "\n|"
			<< setw(8) << "X" << setw(7)
			<< "|" << setw(12) << "arcctg(x)"
			<< setw(3) << "|" << setw(12)
			<< "arcctg(x)" << setw(3) << "|" << setw(12) << "Iterations" << setw(3) << "|\n"
			<< string(60, '-') << endl;
		double arcctg1, arcctg2;

		for (double x = X1; x <= X2; x += dX) {

			arcctg1 = 0, arcctg2 = M_PI_2;

			for (int n = 0; n < MaxIter; n++) {

				arcctg2 += (pow(-1, n + 1)*pow(x, 2 * n + 1)) / (2 * n + 1);

				if (abs(arcctg2 - arcctg1) < Eps)
				{
					f = atan(x);
					f = M_PI_2 - f;

					cout << "|" << setw(14) << x
						<< "|" << setw(14) << arcctg2 << "|" << setw(14) << f
						<< "|" << setw(13) << n << "|\n";
					break;
				}


				if (MaxIter - n < 2) {
					cout << "small EPS";
					return 2;
				}

				arcctg1 = arcctg2;
			}
		}
		cout << string(60, '-');
	}

	else {
		cout << "Error";
	}
	return 0;
}