#include <iostream>
struct Date {
    int year;
    int month;
    int day;
};

bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int calculateDay(Date date) {
    int daysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear = 0;
    if (isLeapYear(date.year)) {
        daysOfMonth[2] = 29;
    }
    for (int i = 1; i < date.month; i++) {
        dayOfYear += daysOfMonth[i];
    }
    dayOfYear += date.day;
    return dayOfYear;
}

int main() {
    int year, month, day;
    while (std::cin >> year >> month >> day) {
        Date date = {year, month, day};
        int dayOfYear = calculateDay(date);

        std::cout << dayOfYear << std::endl;
    }
    return 0;
}
