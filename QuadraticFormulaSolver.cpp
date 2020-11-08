#include <iostream>
#include <cmath>
using namespace std;
// Jacob Smith
// 627002616
// QuadraticFormulaSolver

int main() {
	float a;
	float b;
	float c;
	float x1;
	float x2;
	float discriminant;
	float absDiscriminant;
	float sqrDiscriminant;
	// Quadratic formula: (-b +- sqrt(b^2 - 4ac)) / 2a
	// Obtain input for coefficients
	cin >> a;
	cin >> b;
	cin >> c;
	// Basic calculations in the quadratic formula for later use
	discriminant = pow(b, 2) - (4 * a * c);
	absDiscriminant = fabs(discriminant);
	sqrDiscriminant = sqrt(absDiscriminant);
	// Solve for linear root (a = 0)
	if ((a == 0) && (b != 0)) {
		x1 = -c / b;
		if ((b >= 0) && (c >= 0)) {
			cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
		}
		else if ((b < 0) && (c >= 0)) {
			cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
		}
		else if ((b < 0) && (c < 0)) {
			cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
		}
		else if ((b >= 0) && (c < 0)) {
			cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
		}
		cout << "x = " << x1 << endl;
	}
	// Solve for no real root (graph all above or below x axis)
	else if (((a > 0) && (b > 0) && (c > 0)) || ((a < 0) && (b < 0) && (c < 0))) {
		// Solve for any imaginary roots
		if (discriminant < 0) {
			// Correct for sign formating in imaginary numbers
			if ((sqrDiscriminant / (2 * a)) > 0) {
				if ((b >= 0) && (c >= 0)) {
					cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c >= 0)) {
					cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c < 0)) {
					cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
				}
				else if ((b >= 0) && (c < 0)) {
					cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
				}
				cout << "x = " << -b / (2 * a) << " - " << sqrDiscriminant / (2 * a) << "i" << endl << " x = " << -b / (2 * a);
				cout << " + " << sqrDiscriminant / (2 * a) << "i" << endl;
			}
			else if ((sqrDiscriminant / (2 * a)) < 0) {
				if ((b >= 0) && (c >= 0)) {
					cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c >= 0)) {
					cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c < 0)) {
					cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
				}
				else if ((b >= 0) && (c < 0)) {
					cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
				}
				cout << "x = " << -b / (2 * a) << " + " << fabs(sqrDiscriminant / (2 * a)) << "i" << endl << " x = " << -b / (2 * a);
				cout << " - " << fabs(sqrDiscriminant) / (2 * a) << "i" << endl;
			}
		}
		// Solve for one root
		else if (discriminant == 0) {
			x1 = -b / (2 * a);
			if ((b >= 0) && (c >= 0)) {
				cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
			}
			else if ((b < 0) && (c >= 0)) {
				cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
			}
			else if ((b < 0) && (c < 0)) {
				cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
			}
			else if ((b >= 0) && (c < 0)) {
				cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
			}
			cout << "x = " << x1 << endl;
		}
		else if (discriminant > 0) {
			sqrDiscriminant = sqrt(discriminant);
			x1 = (-b - sqrDiscriminant) / (2 * a);
			x2 = (-b + sqrDiscriminant) / (2 * a);
			if (x1 == x2) {
				if ((b >= 0) && (c >= 0)) {
					cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c >= 0)) {
					cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c < 0)) {
					cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
				}
				else if ((b >= 0) && (c < 0)) {
					cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
				}
				cout << "x = " << x1 << endl;
			}
			else {
				if ((b >= 0) && (c >= 0)) {
					cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c >= 0)) {
					cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c < 0)) {
					cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
				}
				else if ((b >= 0) && (c < 0)) {
					cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
				}
				cout << "x = " << x1 << endl << "x = " << x2 << endl;
			}
		}
	}
	// Solve for real roots (no negative values for the discriminant)
	else {
		if ((a == 0) && (b == 0) && (c != 0)) {
			if (c > 0) {
				cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
			}
			else if (c < 0) {
				cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
			}
			cout << "Unable to determine root(s)." << endl;
		}
		else if ((a == 0) && (b == 0) && (c == 0)) {
			cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
			cout << "Unable to determine root(s)." << endl;
		}
		// Solve for any remaining imaginary roots
		else if (discriminant < 0) {
			// Correct for sign formating in imaginary numbers
			if ((sqrDiscriminant / (2 * a)) > 0) {
				if ((b >= 0) && (c >= 0)) {
					cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c >= 0)) {
					cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c < 0)) {
					cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
				}
				else if ((b >= 0) && (c < 0)) {
					cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
				}
				cout << "x = " << -b / (2 * a) << " - " << sqrDiscriminant / (2 * a) << "i" << endl << "x = " << -b / (2 * a);
				cout << " + " << sqrDiscriminant / (2 * a) << "i" << endl;
			}
			else if ((sqrDiscriminant / (2 * a)) < 0) {
				if ((b >= 0) && (c >= 0)) {
					cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c >= 0)) {
					cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c < 0)) {
					cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
				}
				else if ((b >= 0) && (c < 0)) {
					cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
				}
				cout << "x = " << -b / (2 * a) << " + " << fabs(sqrDiscriminant / (2 * a)) << "i" << endl << "x = " << -b / (2 * a);
				cout << " - " << fabs(sqrDiscriminant / (2 * a)) << "i" << endl;
			}
		}
		else {
			sqrDiscriminant = sqrt(discriminant);
			x1 = (-b - sqrDiscriminant) / (2 * a);
			x2 = (-b + sqrDiscriminant) / (2 * a);
			if (x1 == x2) {
				if ((b >= 0) && (c >= 0)) {
					cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c >= 0)) {
					cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c < 0)) {
					cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
				}
				else if ((b >= 0) && (c < 0)) {
					cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
				}
				cout << "x = " << x1 << endl;
			}
			else {
				if ((b >= 0) && (c >= 0)) {
					cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c >= 0)) {
					cout << a << "x^2 - " << fabs(b) << "x + " << c << " = 0" << endl;
				}
				else if ((b < 0) && (c < 0)) {
					cout << a << "x^2 - " << fabs(b) << "x - " << fabs(c) << " = 0" << endl;
				}
				else if ((b >= 0) && (c < 0)) {
					cout << a << "x^2 + " << b << "x - " << fabs(c) << " = 0" << endl;
				}
				cout << "x = " << x1 << endl << "x = " << x2 << endl;
			}
		}
	}


	return 0;
}