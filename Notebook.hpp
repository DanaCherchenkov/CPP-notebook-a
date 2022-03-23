# include <string>
# include <iostream>
# include "Direction.hpp"

using namespace std;

namespace ariel{

    class Notebook{
        public:
            Notebook();

            void write(int page, int row, int col, Direction dir, string str);

            string read(int page, int row, int col, Direction dir, int str);

            void erase(int page, int row, int col, Direction d, int str);

            string show(int page);
    };
}
