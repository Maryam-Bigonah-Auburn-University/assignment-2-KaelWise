#include<iostream>
#include<String>

using namespace std;

bool isleapYear(int year);
int getCenturyValue (int year);
int getYearValue(int year);
int getMonthValue(int month, int year);

int main() {
//Create Variables
    int month,
        day = 0,
        year = 0,
        sum = 0,
        day_of_week = 0;
    string day_string = "";

    cout << "enter a year" << endl;

    cin >> year;

    cout << "enter the month"<< endl;

    cin >> month;
//Only values equivalent to months allowed
    while (month < 1 || month > 12){

        cout << "please give a valid month";
        cin >> month;
    }

    cout << "enter a day" << endl;

    cin >> day;
//For the months of April, June, September, and November there are 30 valid dates
    if (month == 4 || month == 6|| month == 9 || month ==11 ) {
        while (day < 1 || day > 30) {
            cout << "Enter a value between 1 and 30:";
            cin  >> day;
        }
    }
//For the months of January, March, May, July, August, October, and December
//there are 31 valid dates
    if (month == 1 || month == 3|| month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) {
        while (day < 1 || day > 31) {
            cout << "Enter a value between 1 and 31:";
            cin  >> day;
        }
    }
//February on leap years has 29 valid dates
    else if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) {
        while (day < 1 || day > 29) {
            cout << "Enter a value between 1 and 29:";
            cin >> day;
        }
    }
//February on non-leap years has 28 valid dates
    else {while (day < 1 || day > 28) {
        cout << "Enter a value between 1 and 28:";
        cin >> day;
    }
    }



    // Calculate the day of the week
    sum = day + getMonthValue(month,year) + getYearValue(year) + getCenturyValue(year);
    day_of_week = sum % 7;

    // Find the corresponding day name
    switch(day_of_week) {

        case 0:
            day_string = "Sunday";
        break;

        case 1:
            day_string = "Monday";
        break;

        case 2:
            day_string = "Tuesday";
        break;

        case 3:
            day_string = "Wednesday";
        break;

        case 4:
            day_string = "Thursday";
        break;

        case 5:
            day_string = "Friday";
        break;

        case 6:
            day_string = "Saturday";
        break;
    }

    cout << day_string;
    return 0;

}

bool isLeapYear(int year) {
    // Leap year is divisible by 400 or divisible by 4 and not 100
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int getCenturyValue(int year) {
    int century = 0,
        century_value = 0;
//First two digits of the year, divide by four and save the remainder.
//Subtract the remainder from 3 and return the value multiplied by two
    century = year / 100;
    century_value = (3 - (century % 4)) * 2;
    return century_value;
}
//Last two digits of the year, factoring leap years, and adding the two results
int getYearValue(int year) {
    int year_value = 0;
    year_value = year % 100;
    int div = year_value / 4;
    year_value = year_value + div;
    return year_value;
}
//Returns the date of the month as a value
int getMonthValue(int month, int year) {
    switch(month) {
        case 1:
            if (isLeapYear(year))
                return 6;
            else
                return 0;
        case 2:
            if (isLeapYear(year))
                return 2;
            else
                return 3;
        case 3:
            return 3;
        case 4:
            return 6;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 5;
    }
    return 0;
}
