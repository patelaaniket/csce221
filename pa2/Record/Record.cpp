//implementation of record class

#include "Record.h"
#include <string>
using namespace std;

void Record::set_title(string t) {title = t;}
string Record::get_title() const {return title;}
void Record::set_author(string a){author = a;}
string Record::get_author() const {return author;}
void Record::set_ISBN(string i){isbn = i;}
string Record::get_ISBN() const {return isbn;}
void Record::set_year(string y){year = y;}
string Record::get_year() const {return year;}
void Record::set_edition(string e){edition = e;}
string Record::get_edition() const {return edition;}

std::istream& operator>>(std::istream& is, Record& rec) {
    string x;
    string title;
    string author;
    string isbn;
    string year;
    string edition;

    getline(is, x);
    getline(is, title);
    getline(is, author);
    getline(is, isbn);
    getline(is, year);
    getline(is, edition);

    rec.set_title(title);
    rec.set_author(author);
    rec.set_ISBN(isbn);
    rec.set_year(year);
    rec.set_edition(edition);

    return is;
}
std::ostream& operator<<(std::ostream& os, Record& rec) {
    os << rec.get_title() << endl;
    os << rec.get_author() << endl;
    os << rec.get_ISBN() << endl;
    os << rec.get_year() << endl;
    os << rec.get_edition() << endl;
    return os;
}
bool operator==(const Record& r1, const Record& r2) {
    return (r1.get_title() == r2.get_title() && r1.get_author() == r2.get_author() && r1.get_ISBN() == r2.get_ISBN());
}