#include "cs25_a30.h"
#include <iostream>
using namespace std;

int main() {
	TextBox oobla;
	TextBox onko("Plerbus");

	cout << "oobla: " << oobla.getType();
	cout << "\nonko: " << onko.getType();

	oobla.setType("Fleeber");
	cout << "\noobla: " << oobla.getType();

	return 0;
}