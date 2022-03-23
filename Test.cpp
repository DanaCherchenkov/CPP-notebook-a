# include <string>
# include <iostream>
# include <stdlib.h>
# include "doctest.h"
# include "Notebook.hpp"
# include "Direction.hpp"
# include <stdexcept>
#include <ctime>

using namespace ariel;
using namespace std;


TEST_CASE("Good input"){
    Notebook notebook;
    srand((unsigned) time(0));
	int randomNum1, randomNum2, randomNum3;
	for( int i = 1; i < 10000; i++){

		//range of[-100,100]
		randomNum1 = (int)(rand() % 200) - 100;
		randomNum2 = (int)(rand() % 200) - 100;
        randomNum3 = (int)(rand() % 200) - 100;
		int num1 = randomNum1;
		int num2 = randomNum2;
        int num3 = randomNum3;

        notebook.write(num1, num2, num3, Direction::Horizontal,"hello world");
        if(num1 >= 0 && num2 >= 0 && num3 >= 0){
            CHECK_NOTHROW(notebook.read(num1, num2, num3, Direction::Horizontal, 11));
            
        }
    }
    notebook.write(20, 1, 1, Direction::Horizontal, "Hey");
    for(int i = 1; i < 30; i++){
        CHECK(notebook.read(20, 1, i, Direction::Horizontal, 3) == "Hey");
        CHECK(notebook.read(20, i, 1, Direction::Horizontal, 1) == "H");
        CHECK(notebook.read(i, 10, 5, Direction::Horizontal, 3) == "Hey");
    }

    notebook.write(1000, 50, 0, Direction::Vertical, "Hey you");
    CHECK_NOTHROW(notebook.read(1000, 50, 0, Direction::Vertical, 7));
    notebook.erase(1000, 53, 0, Direction::Vertical, 3);
    CHECK(notebook.read(1000, 50, 0, Direction::Vertical,7) == "Hey ~~~");

}


TEST_CASE("Good deletion"){
    Notebook notebook;
    notebook.write(100, 10, 50, Direction::Horizontal, "Computer Science");
    notebook.erase(100, 10, 50, Direction::Horizontal, 7);
    CHECK(notebook.read(100, 10, 50, Direction::Horizontal, 16) == "~~~~~~~r Science");
}


TEST_CASE("Bad input - Negative numbers"){
    Notebook notebook;
    
    srand((unsigned) time(0));
	int randomNum1, randomNum2, randomNum3;
	for( int i = 1; i < 10000; i++){

		//range of[-100,100]
		randomNum1 = (int)(rand() % 200) - 100;
		randomNum2 = (int)(rand() % 200) - 100;
        randomNum3 = (int)(rand() % 200) - 100;
		int num1 = randomNum1;
		int num2 = randomNum2;
        int num3 = randomNum3;

        notebook.write(num1, num2, num3, Direction::Horizontal,"hello world");
        if(num1 < 0 || num2 < 0 || num3 < 0){
            CHECK_THROWS(notebook.read(num1, num2, num3, Direction::Horizontal, 11));
        }  
    }
}


TEST_CASE("Bad input - Bad deletion"){
    Notebook notebook;
    notebook.write(30, 6, 7, Direction::Horizontal, "Computer Science");
    notebook.erase(30, 6, 7, Direction::Horizontal, 7);
    CHECK_THROWS(notebook.read(30, 6, 7, Direction::Horizontal, 5));
}


TEST_CASE("Bad input - Out of line"){
    Notebook notebook;
    notebook.write(40, 5, 98, Direction::Horizontal, "Goodbey");
    CHECK_THROWS(notebook.read(40, 5, 98, Direction::Horizontal, 7));
}

