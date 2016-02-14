#include "product.h"
#include "util.h"
#include <sstream>
#include "clothing.h"

using namespace std;


	Clothing::Clothing(string size, string brand, string category, string name,  double price, int qty ):Product(category, name, price, qty){
		size_=size;
		brand_=brand;
	}
	Clothing::~Clothing(){

	}
	//creates set of keywords associated with a product
	std::set<std::string> Clothing::keywords() const{
		std::set<std::string> set1=parseStringToWords(name_);
		std::set<std::string> set2=parseStringToWords(brand_);
		std::set<std::string> set3=setUnion(set1, set2);
		
		return set3;
	}
	//formats product information
	string Clothing::displayString() const{
		ostringstream oss;
		oss<<name_<<endl<<"Brand: "<<brand_<<" "<<"Size: "<<size_<<endl<<price_<<" "<<qty_<<" left."<<endl;
		return oss.str();
	}
	//for writing information to output file
	void Clothing::dump(ostream& os) const{
		os<<category_<<endl;
		os<<name_<<endl;
		os<<price_<<endl;
		os<<qty_<<endl;
		os<<size_<<endl;
		os<<brand_<<endl;
	}
