# include <string>
# include <iostream>
# include "Direction.hpp"
# include "Notebook.hpp"

using namespace std;
using namespace ariel;

namespace ariel{

    Notebook::Notebook(){}

    void Notebook::write(int page, int row, int col, Direction dir, string str){}

    string Notebook::read(int page, int row, int col, Direction dir, int str){return " ";}

    void Notebook::erase(int page, int row, int col, Direction dir, int str){}

    string Notebook::show(int page){return " ";}
}

