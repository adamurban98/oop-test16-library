#include "item.hpp"

Item::Item(std::string name): name(name), borrowed(false) {

}

Item::~Item(){

}

void Item::borrow(std::string borrower){
	borrowed = true;
	this->user = borrower;
	this->set_deadline();
}

bool Item::is_borrowed() const{
	return borrowed;
}

std::string Item::get_name() const{
	return name;
}

const Date& Item::get_deadline() const{
	return deadline;
}

const std::string Item::get_user() const{
	return user;
}


Book::Book(std::string name): Item(name){

}

Book::~Book(){

}

void  Book::set_deadline(){
	deadline = Date::get_today() + 7;
}


Dvd::Dvd(std::string name): Item(name){

}

Dvd::~Dvd(){

}

void  Dvd::set_deadline(){
	deadline = Date::get_today() + 14;
}

