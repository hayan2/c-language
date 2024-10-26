#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	string message;	
	double PH = 0, PG = 0;

	getline(cin, message);	

	for (int i = 0; i < message.length(); i++) {
		if (message[i] == 'H' || message[i] == 'P' || message[i] == 'Y') {
			PH++;
		}
		if (message[i] == 'S' || message[i] == 'D') {
			PG++;
		}
		if (message[i] == 'A') {
			PH++;
			PG++;
		}
	}
	double res = (PH / (PH + PG) * 100);

	cout.precision(2);
	cout << fixed;

	if (PH == 0 && PG == 0) {
		cout << "50.00" << endl;
	}
	else {
		cout << round(100 * res) / 100 << endl;
	}
	
	return 0;
}