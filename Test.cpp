#include <string>
#include "Direction.hpp"
#include "Notebook.hpp"
#include "doctest.h"
using namespace ariel;
using namespace std;


TEST_CASE("good input") {
    Notebook note;

    //write

    note.write(0, 0 , 0, Direction::Horizontal, "System");
    note.write(0, 1 , 0, Direction::Horizontal, "Programming");
    note.write(0, 2 , 0, Direction::Horizontal, "Ariel");
    note.write(0, 3 , 0, Direction::Horizontal, "University");

    //Horizonal

    CHECK(note.read(0,0,0, Direction::Horizontal, 6)=="System");
    CHECK(note.read(0,1,0, Direction::Horizontal, 11)=="Programming");
    CHECK(note.read(0,2,0, Direction::Horizontal, 5)=="Ariel");
    CHECK(note.read(0,3,0, Direction::Horizontal, 10)=="University");
    CHECK(note.read(0,2,0, Direction::Horizontal, 6)=="Ariel_");

    //Vertical
    
    CHECK(note.read(0,0,0, Direction::Vertical, 4)=="SPAU");
    CHECK(note.read(0,0,1, Direction::Vertical, 4)=="yrru");
    CHECK(note.read(0,0,2, Direction::Vertical, 4)=="soii");
    CHECK(note.read(0,0,3, Direction::Vertical, 4)=="tgev");
    CHECK(note.read(0,0,4, Direction::Vertical, 4)=="erle");
    CHECK(note.read(0,0,5, Direction::Vertical, 4)=="ma_r");
    CHECK(note.read(0,0,6, Direction::Vertical, 4)=="_m_s");

    //erase

    note.erase(0,0,0,Direction::Horizontal, 6);
    CHECK(note.read(0,0,0, Direction::Horizontal, 6)=="~~~~~~");
    note.erase(0,0,1,Direction::Horizontal, 6);
    CHECK(note.read(0,0,0, Direction::Horizontal, 11)=="~~~~~~mming");
    note.write(0, 0 , 0, Direction::Horizontal, "hagai");
    CHECK(note.read(0,0,0, Direction::Horizontal, 6) == "hagai~");

}

// TEST_CASE("negative numbers") {
//     Notebook note;
//     CHECK_THROWS(note.read(0, 0, -1, Direction::Horizontal, 4));
//     CHECK_THROWS(note.read(0, -1, 0, Direction::Horizontal, 4));
//     CHECK_THROWS(note.read(-1, 0, 0, Direction::Horizontal, 4));

//     CHECK_THROWS(note.write(-1,0,0,Direction::Horizontal, "h"));
//     CHECK_THROWS(note.write(0,-1,0,Direction::Horizontal, "h"));
//     CHECK_THROWS(note.write(0,0,-1,Direction::Horizontal, "h"));

//     CHECK_THROWS(note.erase(-1,0,0,Direction::Horizontal, 4));
//     CHECK_THROWS(note.erase(0,-1,0,Direction::Horizontal, 4));
//     CHECK_THROWS(note.erase(0,0,-1,Direction::Horizontal, 4));
// }

TEST_CASE("bad char") {
    Notebook note;
}

TEST_CASE("override") {
    Notebook note;
    note.write(0, 0 , 0, Direction::Horizontal, "System");
    note.write(0, 1 , 0, Direction::Horizontal, "Programming");
    note.write(0, 2 , 0, Direction::Horizontal, "Ariel");
    note.write(0, 3 , 0, Direction::Horizontal, "University");

    CHECK_THROWS(note.write(0, 0 , 0, Direction::Horizontal, "h"));
    CHECK_THROWS(note.write(0, 1 , 0, Direction::Horizontal, "h"));
    CHECK_THROWS(note.write(0, 2 , 0, Direction::Horizontal, "h"));
    CHECK_THROWS(note.write(0, 3 , 0, Direction::Horizontal, "h"));
    CHECK_THROWS(note.write(0,0,0, Direction::Vertical, "haga"));
}