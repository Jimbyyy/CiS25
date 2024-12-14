#pragma once
#include "Header1.h"

Time::Time(int hour, int minute, int second) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
}

// Getter methods to access the private attributes
int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}

void Time::addHour(const Time& other) {
    if (hour + other.hour <= 24) {
        hour += other.hour;
    }
    else
        hour = hour + other.hour - 24;
}

void Time::addHour(int other) {
    if (hour + other <= 24) {
        hour += other;
    }
    else
        hour = hour + other - 24;
}

void Time::addMinute(const Time& other) {
    if (minute + other.minute <= 60) {
        minute += other.minute;
    }
    else {
        addHour(1);
        minute = minute + other.minute - 60;
    }
}

void Time::addMinute(int other) {
    if (minute + other <= 60) {
        minute += other;
    }
    else {
        addHour(1);
        minute = minute + other - 60;
    }
}

void Time::addSecond(const Time& other) {
    if (second + other.second <= 60) {
        second += other.second;
    }
    else {
        addMinute(1);
        second = second + other.second - 60;
    }
}

// Custom constructor to initialize the values
Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

// Getter methods to access the private attributes
int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

void Date::addYear(const Date& other) {
    year += other.year;
}

void Date::addMonth(const Date& other) {
    if (month + other.month <= 12) {
        month += other.month;
    }
    else {
        year++;
        month = month + other.month - 12;
    }
}

void Date::addMonth(int other) {
    if (month + other <= 12) {
        month += other;
    }
    else {
        year++;
        month = month + other - 12;
    }
}

void Date::addDay(const Date& other) {
    if (((day + other.day <= 31) && month % 2 != 0) || ((day + other.day <= 28) && month % 2 == 0)) {
        day += other.day;
    }
    else if (month % 2 != 0) {
        addMonth(1);
        day = day + other.day - 31;
    }
    else {
        addMonth(1);
        day = day + other.day - 28;
    }
}

void DateTime::computeDifference(DateTime& other) {
    int dayDifference = getDay() - other.getDay();
    int hourDifference = getHour() - other.getHour();
    int minuteDifference = getMinute() - other.getMinute();
    int secondDifference = getSecond() - other.getSecond();

    cout << "Difference is: "
        << dayDifference << " days, "
        << hourDifference << " hours, "
        << minuteDifference << " minutes, "
        << secondDifference << " seconds."
        << endl;
};

void DateTime::format(string formatString) {};