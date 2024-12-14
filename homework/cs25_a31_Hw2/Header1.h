#pragma once
#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Custom constructor
    Time(int hour, int minute, int second);

    // Getter methods to access the private attributes
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    // Adding methods to alter attributes
    void addHour(const Time& other);
    void addHour(int other);
    void addMinute(const Time& other);
    void addMinute(int other);
    void addSecond(const Time& other);
};

class Date {
private:
    int year;
    int month;
    int day;

public:
    // Custom constructor
    Date(int year, int month, int day);

    // Getter methods to access the private attributes
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    
    // Adding methods to alter attributes
    void addYear(const Date& other);
    void addMonth(const Date& other);
    void addMonth(int other);
    void addDay(const Date& other);
};

class DateTime : public Time, public Date {
public:
    // Custom constructor
    DateTime(int hour, int minute, int second, int year, int month, int day) : Time(hour, minute, second), Date(year, month, day) {};
    
    // Computes the difference between 2 DateTime objects
    void computeDifference(DateTime& other);

    // Specifies how the date and time should be displayed
    void format(string formatString);
};