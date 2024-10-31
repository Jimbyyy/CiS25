#ifndef CS25_A25_H
#define CS25_A25_H

#include <iostream>
using std::string;
using namespace std;

struct Address {
    string street;
    string city;
    int zipCode;
};

struct Customer {
    int id;
    string name;
    string email;
    Address address;
};

#endif