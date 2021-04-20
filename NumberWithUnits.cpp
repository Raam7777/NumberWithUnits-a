#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "NumberWithUnits.hpp"

namespace ariel{

    void NumberWithUnits::read_units(ifstream& units_file){

    }
    NumberWithUnits::NumberWithUnits(double num, const string& unit){
        this->num = num;
        this->unit = unit;
    }

        //overloading in and out operators
        istream& operator>>(istream& is, NumberWithUnits& numUnit){
            return is;
        }
        ostream& operator<<(ostream& os, const NumberWithUnits& numUnit){
            return os;
        }

        //overloading arithmetic operators
        NumberWithUnits operator+(const NumberWithUnits& numUnit, double num){
            return numUnit;
        }
        NumberWithUnits operator+(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2){
            return numUnit1;
        }
        NumberWithUnits operator++(NumberWithUnits& numUnit){
            return numUnit;
        }
        NumberWithUnits operator++(NumberWithUnits& numUnit, int){
            return numUnit;
        }
        NumberWithUnits operator+=(NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2){
            return numUnit1;
        }

        NumberWithUnits operator-(const NumberWithUnits& numUnit){
            return numUnit;
        }
        NumberWithUnits operator-(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2){
            return numUnit1;
        }
        NumberWithUnits operator--(NumberWithUnits& numUnit){
            return numUnit;
        }
        NumberWithUnits operator--(NumberWithUnits& numUnit, int){
            return numUnit;
        }
        NumberWithUnits operator-=(NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2){
            return numUnit1;
        }

        NumberWithUnits operator*(const NumberWithUnits& numUnit, double num){
            return numUnit;
        }
        NumberWithUnits operator*(double num, const NumberWithUnits& numUnit){
            return numUnit;
        }
        NumberWithUnits operator*=(NumberWithUnits& numUnit, double num){
            return numUnit;
        }
        NumberWithUnits operator*=(double num, NumberWithUnits& numUnit){
            return numUnit;
        }

        //Comparison operators
        bool operator==(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2){
            return true;
        }
        bool operator!=(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2){
            return true;
        }
        bool operator<(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2){
            return true;
        }
        bool operator<=(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2){
            return true;
        }
        bool operator>(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2){
            return true;
        }
        bool operator>=(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2){
            return true;
        }
}