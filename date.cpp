#include "date.hpp"
Date::Date(int d, int m, int y) : d(d), m(m), y(y) {}

Date::Date()
    : d(Date::get_today().d), m(Date::get_today().m), y(Date::get_today().y) {}

Date Date::get_today() { return Date(7, 12, 2016); }

std::string Date::string() const {
  return std::to_string(d) + "/" + std::to_string(m) + "/" + std::to_string(y);
}

Date Date::operator+(const int& a) const { return Date(d + a, m, y); }

bool Date::operator==(const Date& other) const {
  return (d == other.d && m == other.m && y == other.y);
}
