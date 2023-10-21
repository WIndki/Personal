#include <iostream>

class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(int year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    bool isLeapYear()
    {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    int calculateDay()
    {
        int daysOfMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int dayOfYear = 0;
        if (isLeapYear())
        {
            daysOfMonth[2] = 29;
        }
        for (int i = 1; i < month; i++)
        {
            dayOfYear += daysOfMonth[i];
        }
        dayOfYear += day;
        return dayOfYear;
    }
};

int main()
{
    int year, month, day;
    while (std::cin >> year >> month >> day)
    {
        Date date(year, month, day);
        int dayOfYear = date.calculateDay();
        std::cout << dayOfYear << std::endl;
    }
    return 0;
}
