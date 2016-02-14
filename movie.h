#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include "util.h"
#include <string>
#include <iostream>


using namespace std;

class Movie: public Product{
	public:

		Movie(string genre, string rating, string category, string name, double price, int qty);
		~Movie();
		std::set<std::string>keywords() const;
		string displayString() const;
		void dump(ostream& os) const;

	private:
		string genre_;
		string rating_;
};
#endif