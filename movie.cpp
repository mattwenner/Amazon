#include "product.h"
#include "util.h"
#include <sstream>
#include "movie.h"


using namespace std;


	Movie::Movie(string genre, string rating, string category, string name, double price, int qty):Product(category, name, price, qty){
		genre_=genre;
		rating_=rating;
	}
	Movie::~Movie(){

	}
	//creates set of keywords associated with a product
	std::set<std::string> Movie::keywords() const{
		std::set<std::string> set1=parseStringToWords(name_);
		std::set<std::string> set2=parseStringToWords(genre_);
		std::set<std::string> set3=setUnion(set1, set2);
		return set3;
	}
	//formats product information
	string Movie::displayString() const{
		ostringstream oss;
		oss<<name_<<endl<<"Genre: "<<genre_<<" "<<"Rating: "<<rating_<<endl<<price_<<" "<<qty_<<" left."<<endl;
		return oss.str();
	}
	//for writing information to output file
	void Movie::dump(ostream& os) const{
		os<<category_<<endl;
		os<<name_<<endl;
		os<<price_<<endl;
		os<<qty_<<endl;
		os<<genre_<<endl;
		os<<rating_<<endl;
	}




