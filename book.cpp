#include "product.h"
#include "util.h"
#include <sstream>
#include "book.h"

using namespace std;

	Book::Book(string ISBN, string author, string category, string name,double price, int qty):Product(category, name, price, qty){
		ISBN_=ISBN;
		author_=author;

	}
	Book::~Book(){

	}

	//creates set of keywords associated with a product
	std::set<std::string> Book::keywords() const{

		std::set<std::string> set1=parseStringToWords(name_);
		std::set<std::string> set2=parseStringToWords(author_);
		std::set<std::string> set3=setUnion(set1, set2);
		set3.insert(ISBN_);
		return set3;
	}
	//formats product information
	string Book::displayString() const{
		ostringstream oss;
		oss<<name_<<endl<<"Author: "<<author_<<" "<<"ISBN: "<<ISBN_<<endl<<price_<<" "<<qty_<<" left."<<endl;
		return oss.str();
	}
	//for writing information to output file
	void Book::dump(ostream& os) const{
		os<<category_<<endl;
		os<<name_<<endl;
		os<<price_<<endl;
		os<<qty_<<endl;
		os<<ISBN_<<endl;
		os<<author_<<endl;
	}
