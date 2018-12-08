#ifndef DATE_HPP
#define DATE_HPP
#include <string>

class Date
{
	int d,m,y;
public:
	Date(int d, int m, int y);
	Date();
	bool operator==(const Date& date) const;
	static Date get_today();
	std::string string() const;
	Date operator+(const int& a) const;
};

#endif
