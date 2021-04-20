#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace ariel {

    class NumberWithUnits {
        public:
        std::string unit;
        double num;

        static void read_units(std::ifstream& units_file);
        NumberWithUnits(double num, const std::string& unit);

        //overloading in and out operators
        friend std::istream& operator>>(std::istream& is, NumberWithUnits& numUnit);
        friend std::ostream& operator<<(std::ostream& os, const NumberWithUnits& numUnit);

        //overloading arithmetic operators
        friend NumberWithUnits operator+(const NumberWithUnits& numUnit, double num);
        friend NumberWithUnits operator+(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2);
        friend NumberWithUnits operator++(NumberWithUnits& numUnit);
        friend NumberWithUnits operator++(NumberWithUnits& numUnit, int);
        friend NumberWithUnits operator+=(NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2);

        friend NumberWithUnits operator-(const NumberWithUnits& numUnit);
        friend NumberWithUnits operator-(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2);
        friend NumberWithUnits operator--(NumberWithUnits& numUnit);
        friend NumberWithUnits operator--(NumberWithUnits& numUnit, int);
        friend NumberWithUnits operator-=(NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2);

        friend NumberWithUnits operator*(const NumberWithUnits& numUnit, double num);
        friend NumberWithUnits operator*(double num, const NumberWithUnits& numUnit);
        friend NumberWithUnits operator*=(NumberWithUnits& numUnit, double num);
        friend NumberWithUnits operator*=(double num, NumberWithUnits& numUnit);

        //Comparison operators
        friend bool operator==(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2);
        friend bool operator!=(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2);
        friend bool operator<(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2);
        friend bool operator<=(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2);
        friend bool operator>(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2);
        friend bool operator>=(const NumberWithUnits& numUnit1, const NumberWithUnits& numUnit2);
    };
}