#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "date.hpp"
#include "main.hpp"
#include "item.hpp"


TEMPLATE_TEST_CASE("Item", "[item]", Dvd, Book) {

  std::string a_name = "aldsji_dfWEASDFDSEc";
  std::string b_name = "raadafasifmfasjkf";
  std::string c_name = "";
  TestType a = TestType(a_name);
  TestType b = TestType(b_name);
  TestType c = TestType(c_name);
  SECTION("Book") {
    REQUIRE(a.get_name() == a_name);
    REQUIRE(b.get_name() == b_name);
    REQUIRE(c.get_name() == c_name);
    REQUIRE(a.is_borrowed() == false);
    REQUIRE(b.is_borrowed() == false);
    REQUIRE(c.is_borrowed() == false);
  }
}

TEST_CASE("Get todays Date") {
  REQUIRE(Date::get_today() == Date(1, 12, 2016));
}

TEST_CASE("Test Date opertator+"){
  Date d(1,2,2003);
  for(int i = 0; i < 31; i+=5){
    REQUIRE(d + 0 == Date(1+i,2,2003));
  }
}


TEST_CASE("Test borrow Date") {
  WHEN("Book") {
    Book book("myBook");
    book.borrow("user");
    REQUIRE(book.get_deadline() == Date(21, 12, 2016));
  }
  WHEN("Dvd") {
    Dvd dvd("myDvd");
    dvd.borrow("user");
    REQUIRE(dvd.get_deadline() == Date(14, 12, 2016));
  }
}

TEST_CASE("Date to string") {
  REQUIRE(Date(1, 2, 2022).string() == "1/2/2022");
  REQUIRE(Date::get_today().string() == "7/12/2016");
  REQUIRE(Date(0, 0, 0).string() == "0/0/0");
}

TEST_CASE("Output str") {
  WHEN("Book") {
    Book book("mybook");
    REQUIRE(get_recordStr(book) == "book: mybook currently available");
    book.borrow("user");
    REQUIRE(
          get_recordStr(book) ==
          "book: mybook borrowed by user until 14/12/2016");
    }
  WHEN("Dvd") {
    Dvd dvd("mydvd");
    REQUIRE(get_recordStr(dvd) == "dvd: mydvd currently available");
    dvd.borrow("user");
    REQUIRE(
          get_recordStr(dvd) ==
          "dvd: mydvd borrowed by user until 21/12/2016");
  }
}
