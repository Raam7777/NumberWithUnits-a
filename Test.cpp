#include "NumberWithUnits.hpp"
#include "doctest.h"

#include <iostream>
#include <string>

using namespace std;
using namespace ariel;

TEST_CASE("read_units")
{
  ifstream units_file{"units.txt"};
  NumberWithUnits::read_units(units_file);

  /*
  1 km = 1000 m
1 m = 100 cm
1 kg = 1000 g
1 ton = 1000 kg
1 hour = 60 min
1 min = 60 sec
1 USD = 3.33 ILS
  */

  CHECK_THROWS(NumberWithUnits a(10, "M"));
  CHECK_THROWS(NumberWithUnits aa(10, "CM"));
  CHECK_THROWS(NumberWithUnits aaa(10, "Cm"));
  CHECK_THROWS(NumberWithUnits aaaa(10, "cM"));
  CHECK_THROWS(NumberWithUnits b(10, "G"));
  CHECK_THROWS(NumberWithUnits bb(10, "KG"));
  CHECK_THROWS(NumberWithUnits bbb(10, "Kg"));
  CHECK_THROWS(NumberWithUnits bbbb(10, "kG"));
  CHECK_THROWS(NumberWithUnits c(10, "MIN"));
  CHECK_THROWS(NumberWithUnits cc(10, "SEC"));
  CHECK_THROWS(NumberWithUnits ccc(10, "usd"));
  CHECK_THROWS(NumberWithUnits cccc(10, "ils"));
  CHECK_THROWS(NumberWithUnits d(10, "ToN"));
  CHECK_THROWS(NumberWithUnits dd(10, "HOur"));
  CHECK_THROWS(NumberWithUnits ddd(10, "KM"));

  CHECK_THROWS(NumberWithUnits dddd(10, "EURO"));
  CHECK_THROWS(NumberWithUnits e(10, "DINAR"));
  CHECK_THROWS(NumberWithUnits ee(10, "SENT"));
  CHECK_THROWS(NumberWithUnits eee(10, "milimeter"));
  CHECK_THROWS(NumberWithUnits eeee(10, "centimeter"));

}

TEST_CASE("overloading arithmetic operators")
{
    NumberWithUnits a(1, "km");
    NumberWithUnits b(1000, "m");
    NumberWithUnits c(1000, "cm");
    CHECK((a+a).num == 2);
    CHECK((a+a).unit == "km");
    CHECK((b+b).num == 2000);
    CHECK((b+b).unit == "m");
    CHECK((c+c).num == 2000);
    CHECK((c+c).unit == "cm");
    CHECK((a+b).num == 2);
    CHECK((a+b).unit == "km");
    CHECK((b+c).num == 1001);
    CHECK((b+c).unit == "m");

    NumberWithUnits d(100, "m");
    CHECK((a-d).num == 0.9);
    CHECK((a-d).unit == "km");
    CHECK((a-c).num == 0.99);
    CHECK((a-c).unit == "km");
    CHECK((b-c).num == 999);
    CHECK((b-c).unit == "m");
}