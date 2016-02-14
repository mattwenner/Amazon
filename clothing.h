#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"
#include "util.h"
#include <string>
#include <iostream>

using namespace std;

class Clothing: public Product{
	public:
		Clothing(string size, string brand, string category, string name,  double price, int qty);

		~Clothing();

		std::set<std::string> keywords() const;

		string displayString() const;

		void dump(ostream& os) const;

	private:
		string size_;
		string brand_;
};
#endif