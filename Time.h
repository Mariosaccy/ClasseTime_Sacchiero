#ifndef CLASSETIME_SACCHIERO_TIME_H
#define CLASSETIME_SACCHIERO_TIME_H

#include <iostream>
using namespace std;

class Time {
private:
    int ore;
    int minuti;
    int secondi;

public:
    Time();
    Time(int ore, int minuti, int secondi);
    Time(const Time& time);

    string show(bool formato);
    void set(int ore, int minuti, int secondi);

    int get_o();
    int get_m();
    int get_s();

    bool operator>(const Time& time);
    bool operator<(const Time& time);
    bool operator==(const Time& time);
    int operator-(const Time& time);
    friend Time operator+(const Time& t, int secondIn);
};


#endif //CLASSETIME_SACCHIERO_TIME_H