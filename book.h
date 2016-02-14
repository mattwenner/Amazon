#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include "util.h"
#include <string>
#include <iostream>


using namespace std;

class Book: public Product{
	public:
		Book(string ISBN, string author, string category, string name,double price, int qty);
		
		~Book();

		std::set<std::string> keywords() const;

		std::string displayString() const;

		void dump(ostream& os) const;

	private:
		string ISBN_;
		string author_;
};
#endif