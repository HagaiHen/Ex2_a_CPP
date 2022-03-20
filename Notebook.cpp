#include <string>
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;


void Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction d, std::string const &str) {

}

std::string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction d, unsigned int len) {
    this->maxPage=UINT16_MAX;
    std::string s;
    return s;
}

void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction d, unsigned int len) {

}

void Notebook::show(unsigned int page) {

}

Notebook::Notebook(unsigned int page, unsigned int row, unsigned int col) {
    this->maxPage = page;
    this->maxRow = row;
    this->maxCol = col;
}


