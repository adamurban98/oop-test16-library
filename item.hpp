#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "date.hpp"

class Item
{
private:
	std::string name;
	bool borrowed;
	std::string user;
protected:
	std::string typeName;
	Date deadline;
	Item(std::string name);
public:
	virtual ~Item();
	void borrow(std::string borrower);
	bool is_borrowed() const;
	std::string get_name() const;
	virtual void set_deadline() = 0;
	std::string get_typeName() const;
	const Date& get_deadline() const;
	const std::string get_user() const;
};

class Book: public Item
{
public:
	Book(std::string name);
	virtual ~Book();
	virtual void set_deadline();
};

class Dvd: public Item
{
public:
	Dvd(std::string name);
	virtual ~Dvd();
	virtual void set_deadline();
};
#endif
