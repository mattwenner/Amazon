#include <sstream>
#include <iomanip>
#include "product.h"

using namespace std;

Product::Product(const std::string category, const std::string name, double price, int qty) : 
  name_(name),
  price_(price),
  qty_(qty),
  category_(category)
{

}

Product::~Product()
{

}


double Product::getPrice() const
{
  return price_;
}

std::string Product::getName() const
{
  return name_;
}

void Product::subtractQty(int num)
{
  qty_ -= num;
}

int Product::getQty() const
{
  return qty_;
}

vector <Review*>& Product::getReviews() {
  return reviews;
}

void Product::dump(std::ostream& os) const
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
}

void Product::dumpReviews(std::ostream& os) const{
  for(unsigned int i=0; i<reviews.size(); i++){


    os<<reviews[i]->prodName<<"\n";
    os<<reviews[i]->rating<<" "<<reviews[i]->user<<" "<<reviews[i]->date<<" "<<reviews[i]->reviewText<<"\n";
  }
}

