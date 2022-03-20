#include <string>
#include "Direction.hpp"

namespace ariel {
    
    class Notebook {
		
        private:
            unsigned int maxPage, maxRow, maxCol;
            char note [][100];
        
        public:
            void write(unsigned int page, unsigned int row, unsigned int col, Direction d, std::string const &str);
            std::string read (unsigned int page, unsigned int row, unsigned int col, Direction d, unsigned int len);
            void erase(unsigned int page, unsigned int row, unsigned int col, Direction d, unsigned int len);
            void show(unsigned int page);

            Notebook() {
                maxPage = UINT16_MAX;
                maxRow = UINT16_MAX;
                maxCol = UINT16_MAX;
            }
            
            Notebook(unsigned int page, unsigned int row, unsigned int col);
	};

}