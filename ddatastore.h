#ifndef DDATASTORE_H
#define DDATASTORE_H
#include "datastore.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "util.h"
#include "splay.h"
#include <set>





using namespace std;

//derived datastore class
class DDataStore:public DataStore{
	public:
		DDataStore();
		~DDataStore();

		void addProduct(Product* p);

		void addUser(User* u);

		void addReview(Review* r);

		//searches for possible products by keywords
		vector<Product*> search(vector<std::string>& terms, int type);

		void dump(ostream& ofile);

		//accessor for set of Product*s
		const set<Product*> & getProducts();

		//accessor for set of User*s
		const set<User*>&  getUsers();

		//for adding a product to a user's cart
		void addToCart (User user, Product* product);

		//accessor to user's cart
		vector<Product*> & getUserCart(string username);

		//accesor to cart splay
		splay<string, vector<Product*> >&getMap();

		//for access to user based on their username
		User* &getUserInfo(string username);


	private:

		//stores all products
		set<Product*> products;
		//stores all users
		set<User*> users;
		//stores all products associated with a keyword
		splay<string, set<Product*> > myMap;
		//stores user's cart
		splay< string, vector<Product*> > cart;

		//allows access to user based on their username
		splay< string, User*> myUserMap;
};




#endif