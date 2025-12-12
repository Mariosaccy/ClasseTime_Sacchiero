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

    string show(bool formato) const;
    void set(int ore, int minuti, int secondi);

    int get_o() const;
    int get_m() const;
    int get_s() const;

    bool operator>(const Time& time) const;
    bool operator<(const Time& time) const;
    bool operator==(const Time& time) const;
    int operator-(const Time& time) const;
    friend Time operator+(const Time& t, int secondIn);
};


#endif //CLASSETIME_SACCHIERO_TIME_H