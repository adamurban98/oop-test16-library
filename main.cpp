#include "main.hpp"


std::string get_recordStr(const Item& item){
	std::string result = item.get_typeName() + ": " + item.get_name() + " " ;
	if (item.is_borrowed()){
		result += "borrowed by " + item.get_user() + " until " + item.get_deadline().string();
	}
	else{
		result += "currently available";
	}
	return result;
}
