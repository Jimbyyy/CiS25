#include "Header1.h"
#include <iostream>
using namespace std;

int main() {
	Date date1(2024, 1, 25);
	Date date2(2025, 3, 10);

	date1.addDay(date2);

	cout << date1.getDay() << endl;

	Time time1(23, 45, 6);

	DateTime dateTim1(23, 45, 6, 2024, 1, 25);
	DateTime dateTim2(20, 40, 9, 2004, 6, 8);

	dateTim1.computeDifference(dateTim2);

	return 0;
}