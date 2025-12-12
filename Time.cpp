#include "Time.h"
#include <iostream>
using namespace std;

Time::Time(int ore, int minuti, int secondi) {
    if (ore >= 24 || minuti >= 60 || secondi >= 60
        || ore < 0 || minuti < 0 || secondi < 0) {
        throw std::out_of_range("Ora fuori range");
    } else {
        this->ore = ore;
        this->minuti = minuti;
        this->secondi = secondi;
    }
}

Time::Time() {
    ore = minuti = secondi = 0;
}

Time::Time(const Time &time) {
    this->ore = time.ore;
    this->minuti = time.minuti;
    this->secondi = time.secondi;
}

string Time::show(bool formato) const {
    if (!formato) { // formato 12H
        int hour12 = ore % 12;
        if (hour12 == 0) hour12 = 12;  // 0 ore = 12 AM
        string periodo = (ore >= 12) ? "PM" : "AM";
        return to_string(hour12) + ":" +
               to_string(minuti) + ":" +
               to_string(secondi) + periodo;
    } else { // formato 24H
        return to_string(ore) + ":" +
               to_string(minuti) + ":" +
               to_string(secondi);
    }
}

void Time::set(int ore, int minuti, int secondi) {
    if (ore >= 24 || minuti >= 60 || secondi >= 60
        || ore < 0 || minuti < 0 || secondi < 0) {
        throw std::out_of_range("Ora fuori range");

        } else {
            this->ore = ore;
            this->minuti = minuti;
            this->secondi = secondi;
        }
}

int Time::get_o() const {
    return ore;
}

int Time::get_m() const {
    return minuti;
}

int Time::get_s() const {
    return secondi;
}

bool Time::operator>(const Time &time) const {

        if (ore != time.ore) {
            return ore > time.ore;
        }
        if (minuti != time.minuti) {
            return minuti > time.minuti;
        }
        return secondi > time.secondi;
}

bool Time::operator<(const Time &time) const {
    if (ore != time.ore) {
        return ore < time.ore;
    }
    if (minuti != time.minuti) {
        return minuti < time.minuti;
    }
    return secondi < time.secondi;
}

bool Time::operator==(const Time &time) const {
    if (ore != time.ore || minuti != time.minuti || secondi != time.secondi) {
        return false;
    } else {
        return true;
    }
}

int Time::operator-(const Time &time) const {
    int oraCalc = ore - time.ore;
    int minutiCalc = minuti - time.minuti;
    int secondiCalc = secondi - time.secondi;
    if (oraCalc < 0) {
        oraCalc = oraCalc * -1;
    }
    if (minutiCalc < 0) {
        minutiCalc = minutiCalc * -1;
    }
    if (secondiCalc < 0) {
        secondiCalc = secondiCalc * -1;
    }

    int secTot = (oraCalc*60*60) + (minutiCalc*60) + secondiCalc;
    return secTot;
}

Time operator+(const Time& t, int secondIn) {
    int total_seconds = t.ore * 3600 + t.minuti * 60 + t.secondi;
    total_seconds += secondIn;

    total_seconds %= (24 * 3600);
    if (total_seconds < 0) {
        total_seconds += 24 * 3600;
    }

    int ore = total_seconds / 3600;
    total_seconds %= 3600;
    int minuti = total_seconds / 60;
    int secondi = total_seconds % 60;

    return Time(ore, minuti, secondi);
}