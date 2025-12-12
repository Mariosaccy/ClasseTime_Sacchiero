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

string Time::show(bool formato) {
    if (!formato && ore >= 12) { // formato true 24H, false 12H
        return to_string(ore-12)+"PM:"+to_string(minuti)+":"+to_string(secondi);
    } else if (!formato && ore < 12) {
        return to_string(ore)+"AM:"+to_string(minuti)+":"+to_string(secondi);
    } else {
        return to_string(ore)+":"+to_string(minuti)+":"+to_string(secondi);
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

int Time::get_o() {
    return ore;
}

int Time::get_m() {
    return minuti;
}

int Time::get_s() {
    return secondi;
}

bool Time::operator>(const Time &time) {

        if (ore != time.ore) {
            return ore > time.ore;
        }
        if (minuti != time.minuti) {
            return minuti > time.minuti;
        }
        return secondi > time.secondi;
}

bool Time::operator<(const Time &time) {
    if (ore != time.ore) {
        return ore < time.ore;
    }
    if (minuti != time.minuti) {
        return minuti < time.minuti;
    }
    return secondi < time.secondi;
}

bool Time::operator==(const Time &time) {
    if (ore != time.ore || minuti != time.minuti || secondi != time.secondi) {
        return false;
    } else {
        return true;
    }
}

int Time::operator-(const Time &time) {
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
    int oraCalc = secondIn / 3600;
    secondIn %= 3600;
    int minutiCalc = secondIn / 60;
    int secondInt = secondIn % 60;

    int newSecondi = t.secondi;
    int newMinuti = t.minuti;
    int newOre = t.ore;

    // gestione secondi
    if (newSecondi + secondInt >= 60) {
        newSecondi += secondInt - 60;
        minutiCalc++;
    } else {
        newSecondi += secondInt;
    }

    // gestione minuti
    if (newMinuti + minutiCalc >= 60) {
        newMinuti += minutiCalc - 60;
        oraCalc++;
    } else {
        newMinuti += minutiCalc;
    }

    // gestione ore
    newOre = (newOre + oraCalc) % 24;

    return Time(newOre, newMinuti, newSecondi);
}