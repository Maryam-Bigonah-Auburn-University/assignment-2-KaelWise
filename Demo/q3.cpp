#include <iostream>;
#include <iomanip>;

using namespace std;
//MPH conversion set as double
double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);
//Integers set and kph set as double
int main() {
	int minutes = 0,
	    seconds = 0;
	double kph = 0.0;
//Running pace minutes value must be positive
	cout << "Enter running pace minutes: \n";
	cin >> minutes;
	if (minutes < 0) {
		while (minutes < 0) {
			cout << "Enter a positive value:\n";
			cin >> minutes;
		}
	}
//Running pace seconds value must be less than a minute and positive
	cout << "Enter running pace seconds: \n";
	cin >> seconds;
	if (seconds > 59 || seconds < 0)
	{
		while (seconds > 59 || seconds < 0) {
			cout << "Enter a value between 0 and 59\n";
			cin >> seconds;
		}
	}
//KPH precision set to 3 digits
	cout << "Enter kph:\n";
	cin >> kph;
	cout << setprecision(3);
//Output running pace in MPH
	cout << "A " << minutes << " minutes and " << seconds << " seconds mile is equivalent to "
			<< convertToMPH(minutes, seconds) << " mph\n";
	cout << setprecision(3);
//Output kph in MPH
	cout << kph << " kph is equivalent to " << convertToMPH(kph) << " mph\n";


	return 0;
}
//Convert time into MPH
double convertToMPH(int minutes, int seconds) {
	// There are 3600 seconds in an hour
	return (3600.0 / ((minutes * 60) + seconds));
}
//Convert KPH into MPH
double convertToMPH(double kph) {
	return (kph / 1.61);
}
