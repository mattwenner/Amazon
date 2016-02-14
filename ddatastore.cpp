#include "ddatastore.h"

using namespace std;

DDataStore::DDataStore():DataStore(){}

DDataStore::~DDataStore(){
	for(set<User*>::iterator it=users.begin(); it!=users.end(); ++it){
		delete *it;
	}

	for(set<Product*>::iterator it=products.begin(); it!=products.end(); ++it){
		
		for(unsigned int i=0; i<(*it)->getReviews().size(); i++){
			delete (*it)->getReviews()[i];
		}
	}
	for(set<Product*>::iterator it=products.begin(); it!=products.end(); ++it){
		delete *it;
	}
}

//add product to database by keyword
void DDataStore::addProduct(Product* p){
	std::set<string> temp=p->keywords();
	for(std::set<string>::iterator it=temp.begin(); it!=temp.end(); it++){
		//key not found so create new key
		if(myMap.find(*it)==NULL){
			std::set<Product*> newset;
			newset.insert(p);

			myMap.insert(std::pair<string, std::set<Product*> >(*it, newset));
			
		}
		//add product to key
		else{
			//myMap[*it].insert(p);
			((myMap.find(*it))->getItem().second).insert(p);
		}
	}
	//if product is not in database, add it
	if(products.find(p)==products.end()){
		products.insert(p);
	}
}

void DDataStore::addUser(User* u){
	//maps users with their usernames
	if(myUserMap.find(u->getName())==NULL){
		myUserMap.insert(std::pair<string, User*> (u->getName(), u));
	}


	if(users.find(u)==users.end()){
		users.insert(u);
	}
}

void DDataStore::addReview(Review* r){
	
	for(set<Product*>::iterator it=products.begin(); it!=products.end();++it){
		if(r->prodName==(*it)->getName()){
			(*it)->getReviews().push_back(r);
			
		}
	}
	for(set<User*>::iterator it=getUsers().begin(); it!=getUsers().end(); ++it){
		if ((*it)->getName()==r->user){
			for(set<Product*>::iterator it2=getProducts().begin(); it2!=getProducts().end(); ++it2){
				if(r->prodName==(*it2)->getName()){
					(*it)->getReviewedProducts().insert((*it2));
				}
			}
		}
	}
}

vector<Product*> DDataStore::search(vector<std::string>& terms, int type){
	
	//set that hold possible products after each union/intersection
	set<Product*>possible_products;
	//products that match our search criteria
	vector<Product*>final_items;

	//returns this if no products matched our criteria
	vector<Product*>empty;

	//AND search
	if(type==0){
		bool first_search=true;
		for(unsigned int i=0; i<terms.size(); i++){
			//keyword not found
			if(myMap.find(terms[i])==NULL){
				return empty;
			}
			else{
				//first keyword, so all associated products have possibility of matching all criteria
				if(first_search){
					
					possible_products=myMap.find(terms[i])->getItem().second;
					first_search=false;
					
					
				}
				//any other following keyword
				else{
					
					possible_products=setIntersection(possible_products, myMap.find(terms[i])->getItem().second);
					

				}

			}
			

		}

	}
	//or search
	else{
		for(unsigned int i=0; i<terms.size(); i++){
			if(myMap.find(terms[i])!=NULL){
				
				possible_products=setUnion(possible_products, myMap.find(terms[i])->getItem().second);

			}
		}
	}
	//push all products that match our criteria into the final vector
	for(set <Product*>::iterator it=possible_products.begin(); it!=possible_products.end(); it++){
		final_items.push_back(*it);
	}
	return final_items;
}
//for writing updated inventory to output file
void DDataStore::dump(ostream& ofile){
	ofile<<"<products>"<<endl;
	for(std::set<Product*> ::iterator it=products.begin(); it!=products.end(); it++){
		(*it)->dump(ofile);
	}
	//no more products
	ofile<<"</products>"<<endl;
	ofile<<"<users>"<<endl;
	for(std::set<User*>::iterator it=users.begin(); it!=users.end(); it++){
		(*it)->dump(ofile);
	}
	//no more users
	ofile<<"</users>"<<endl;
	ofile<<"<reviews>"<<endl;
	for(std::set<Product*>::iterator it=products.begin(); it!=products.end(); it++){
		
		(*it)->dumpReviews(ofile);
	}
	//no more reviews
	ofile<<"</reviews>"<<endl;
}

//accessor to products
const set<Product*> & DDataStore::getProducts(){
	return products;
}

//accessor to user
const set<User*> & DDataStore::getUsers(){
	return users;
}

//for adding to user cart
void DDataStore::addToCart(User user_, Product* product){
	string username=user_.getName();
	
	//user cart doesn't exist yet, so create it
	if(cart.find(username)==NULL){
		vector<Product*> items;
		items.push_back(product);
		cart.insert(std::pair< string, vector< Product* > >(username, items));
	}
	else{
		cart.find(username)->getItem().second.push_back(product);
	}
}

//accessor to user cart
vector<Product*> & DDataStore::getUserCart(string username){
	return cart.find(username)->getItem().second;
}

//accessor to cart map
splay<string, vector<Product*> >& DDataStore::getMap(){
	return cart;
}

User* & DDataStore::getUserInfo(string username){
	return (myUserMap.find(username)->getItem().second);
}

