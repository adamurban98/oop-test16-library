#include "main.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include "item.hpp"

std::string get_recordStr(const Item& item) {
  std::string result = item.get_typeName() + ": " + item.get_name() + " ";
  if (item.is_borrowed()) {
    result += "borrowed by " + item.get_user() + " until " +
              item.get_deadline().string();
  } else {
    result += "currently available";
  }
  return result;
}

void loadItems(std::vector<Item*>& items) {
  std::string name;
  std::ifstream file_dvds;
  file_dvds.open("dvds.txt");
  if (!file_dvds) {
    std::cout << "Unable to open file dvds.txt";
    exit(1);  // terminate with error
  }
  while (file_dvds >> name) {
    items.push_back(new Dvd(name));
  }
  std::ifstream file_books;
  file_books.open("books.txt");
  if (!file_books) {
    std::cout << "Unable to open file books.txt";
    exit(1);  // terminate with error
  }
  while (file_books >> name) {
    items.push_back(new Book(name));
  }
}

void print_all_records(std::vector<Item*>& items) {
	std::cout << "items:\n";
  for (unsigned int i = 0; i < items.size(); i++) {
    std::cout << i << ": " << get_recordStr(*items[i]) << std::endl;
  }
}

int main() {
  std::vector<Item*> items;
  loadItems(items);
  print_all_records(items);
  std::cout << "would you like to borrow an item? (y/n)\n";
  char action;
  while (std::cin >> action && action != 'n') {
    if (action == 'y') {
      print_all_records(items);
      std::cout << "to borrow an item please enter its index followed by the borrower’s code\n";
      int itemnum;
      std::cin >> itemnum;
      std::string username;
      std::cin >> username;
      auto itemptr = items[itemnum];
      if(!itemptr->is_borrowed()){
		    itemptr->borrow(username);
      }
      else{
      	std::cout << "this item is not available\n";
      }
    }
	  print_all_records(items);
	  std::cout << "would you like to borrow an item? (y/n)\n";
  }
  std::ofstream ofile;
  ofile.open("librarystate.txt");
	for (unsigned int i = 0; i < items.size(); i++) {
    ofile  << get_recordStr(*items[i]) << std::endl;
  }
  ofile.close();

  // std::for_each(items.begin(), items.end());
}
