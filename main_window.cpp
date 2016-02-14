#include "main_window.h"
#include "msort.h"
#include "comparison.h"
#include "splay.h"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

//default constructor
MainWindow::MainWindow(){}


MainWindow::MainWindow(DDataStore* ds, User* user_){
	
	dsptr=ds;
	user=user_;
	Product* recommend=makeRecommendation();
	noMas=new QMessageBox();
	noMas->setText("No more products to recommend.");
	if(recommend==NULL){
		noMas->exec();
	}
	else{
		recommendDialog rd(dsptr, user, recommend);
		rd.exec();
	}
	
	//Title
	string title_=(user->getName()+"'s Account");
	title=QString::fromStdString(title_);

	setWindowTitle(title);

	overallLayout=new QHBoxLayout();

	//everything related to entering search terms
	searchLayout=new QVBoxLayout();
	search_terms=new QLabel("Enter Search Terms:");
	search_input=new QLineEdit();
	searchLayout->addWidget(search_terms);
	searchLayout->addWidget(search_input);
	

	//everything related to choosing search type
	search_type=new QLabel("Choose search type:");
	andButton=new QRadioButton("AND search");
	orButton=new QRadioButton("OR search");
	andOrLayout=new QVBoxLayout();
	andOrLayout->addWidget(search_type);
	andOrLayout->addWidget(andButton);
	andOrLayout->addWidget(orButton);
	searchButton=new QPushButton("Search");
	connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));
	andOrLayout->addWidget(searchButton);
	

	//everything related to search results and their sorting
	resultsLayout=new QVBoxLayout();
	search_results=new QListWidget();
	
	resultsLayout->addWidget(search_results);
	sortAlphaButton=new QPushButton("Sort Alphabetically");
	connect(sortAlphaButton, SIGNAL(clicked()), this, SLOT(sortAlphabetically()));
	sortRatingButton=new QPushButton("Sort by Rating");
	connect(sortRatingButton, SIGNAL(clicked()), this, SLOT(sortByRating()));
	resultsLayout->addWidget(sortAlphaButton);
	resultsLayout->addWidget(sortRatingButton);
	

	//everything related to reviews
	reviews=new QListWidget();
	
	connect(search_results, SIGNAL(currentRowChanged(int)), this, SLOT(displayReviews(int)));
	reviewButton=new QPushButton("Add review");
	connect(reviewButton, SIGNAL(clicked()), this, SLOT(addReview()));
	reviewLayout=new QVBoxLayout();
	reviewLayout->addWidget(reviews);
	reviewLayout->addWidget(reviewButton);
	

	
	
	//adding all users as possible selections
	
	
	userLayout=new QVBoxLayout();
	addButton=new QPushButton("Add-to-Cart");
	resultsLayout->addWidget(addButton);
	connect(addButton, SIGNAL(clicked()), this, SLOT(addToCart()));
	viewButton=new QPushButton("View-Cart");
	connect(viewButton, SIGNAL(clicked()), this, SLOT(viewCart()));
	resultsLayout->addWidget(viewButton);
	
	
	
	//everything related to saving and quitting
	quitLayout=new QVBoxLayout();
	filename=new QLineEdit();
	saveButton=new QPushButton("Click to save changes to output file");
	connect(saveButton, SIGNAL(clicked()), this, SLOT(saveChanges()));
	quitButton=new QPushButton("Click to quit");
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
	enterFileName=new QLabel("Enter filename to save");
	quitLayout->addWidget(enterFileName);
	quitLayout->addWidget(filename);
	quitLayout->addWidget(saveButton);
	quitLayout->addWidget(quitButton);
	
	searching=new QVBoxLayout();
	searching->addLayout(searchLayout);
	searching->addLayout(andOrLayout);
	searching->addLayout(resultsLayout);

	choosing=new QVBoxLayout();
	choosing->addLayout(reviewLayout);
	choosing->addLayout(userLayout);
	choosing->addLayout(quitLayout);
	overallLayout->addLayout(searching);
	overallLayout->addLayout(choosing);

	setLayout(overallLayout);


}

MainWindow::~MainWindow(){
	qDeleteAll(this->children());
	
}

void MainWindow::search(){
	if(search_results->count()!=0){
		search_results->clear();
	}

	if(search_input->text().isEmpty()||(!andButton->isChecked()&&!orButton->isChecked())){
		return;
	}

	stringstream ss((search_input->text()).toStdString());
	if(andButton->isChecked()){
		string term;
		vector<string> terms;
		while(ss >> term){
	  		term = convToLower(term);
	  		terms.push_back(term);
		}
		hits = dsptr->search(terms, 0);
		for(unsigned int i=0; i<hits.size(); i++){
			ostringstream oss;
			oss<<hits[i]->getName()<<'\n'<<hits[i]->getPrice();	
			//add to search results list widget	
			search_results->addItem(QString::fromStdString(oss.str()));
		}
	}

	else{
		string term;
		vector<string> terms;
		while(ss >> term){
	  		term = convToLower(term);
	  		terms.push_back(term);
		}
		hits = dsptr->search(terms, 1);
		for(unsigned int i=0; i<hits.size(); i++){
			ostringstream oss;
			oss<<hits[i]->getName()<<'\n'<<hits[i]->getPrice();
			//add to search results list widget
			search_results->addItem(QString::fromStdString(oss.str()));

		}
      
	}

}

void MainWindow::sortAlphabetically(){
	if(search_results->count()!=0){
		search_results->clear();
		
	}
	AlphaComp acomp;
	mergeSort(hits, acomp);
	for(unsigned int i=0; i<hits.size(); i++){
		ostringstream oss;
		oss<<hits[i]->getName()<<'\n'<<hits[i]->getPrice();
		//add sorted products to list widget
		search_results->addItem(QString::fromStdString(oss.str()));

	}
}

void MainWindow::sortByRating(){
	if(search_results->count()!=0){
		search_results->clear();

	}
	RatingComp rcomp;
	mergeSort(hits, rcomp);
	for(unsigned int i=0; i<hits.size(); i++){
		ostringstream oss;
		oss<<hits[i]->getName()<<'\n'<<hits[i]->getPrice();
		//add sorted products to lsit widget
		search_results->addItem(QString::fromStdString(oss.str()));

	}
}

void MainWindow::addToCart(){
	if(search_results->currentItem()!=NULL){
		dsptr->addToCart(*user,hits[search_results->currentRow()]);
	}
}

void MainWindow::viewCart(){
	Dialog* viewDialog=new Dialog(dsptr, user->getName());
	viewDialog->exec();
	delete viewDialog;
}
void MainWindow::displayReviews(int index){
	if(reviews->count()!=0){
		reviews->clear();
	}
	if(index == -1 ) {
		return;
	}
	DateComp dc;
	mergeSort(hits[index]->getReviews(), dc);
	for(unsigned int i=0;i<hits[index]->getReviews().size(); i++){
		stringstream ss;
		ss<<hits[index]->getReviews()[i]->rating<<" "<<hits[index]->getReviews()[i]->user<<" "<<hits[index]->getReviews()[i]->date<<" "<<hits[index]->getReviews()[i]->reviewText;
		//add reviews to reviews list widget
		reviews->addItem(QString::fromStdString(ss.str()));
	}
}

void MainWindow::addReview(){
	//make sure item is selected
	if(search_results->currentItem()==NULL||search_results->currentRow()==-1){
		return;
	}
	else{
		vector<User*> userdb;
		
		for(set<User*>::iterator it=dsptr->getUsers().begin(); it!=dsptr->getUsers().end(); ++it){
			userdb.push_back(*it);
		
		}
		reviewDialog* reviewMenu=new reviewDialog(this, hits, user,  search_results->currentRow());
		reviewMenu->exec();
		delete reviewMenu;
	}
}

void MainWindow::saveChanges(){
	//makes sure there is something filename inputted
	if(filename->text().isEmpty()==true){
		return;
	}
	else{
		ofstream ofile( ((filename->text()).toStdString()).c_str());
		dsptr->dump(ofile);
		ofile.close();	
	}
}

void MainWindow::quit(){
	close();
}

//allows access to MainWindow's display reviews slot, updates reviews after adding a review
void MainWindow::updateReviews(int index){
	displayReviews(index);
}
Product* MainWindow::makeRecommendation(){
	vector <Product*> notReviewed;
	Product* most_interesting_prod=NULL;
	if(this->user->getReviewedProducts().size()==dsptr->getProducts().size()){
		return most_interesting_prod;
	}
	for(set<Product*>::iterator it=dsptr->getProducts().begin(); it!=dsptr->getProducts().end(); ++it){
		if(user->getReviewedProducts().find(*it)==user->getReviewedProducts().end()){
			notReviewed.push_back(*it);
	
		}
	}
	//set of users with products that logged in user has not reviewed
	set<User*> userSet;
	for(unsigned int i=0; i<notReviewed.size(); i++){
		for(unsigned int j=0; j<notReviewed[i]->getReviews().size(); j++){
			for(set<User*>::iterator it=dsptr->getUsers().begin(); it!=dsptr->getUsers().end(); ++it){
				if(notReviewed[i]->getReviews()[j]->user==(*it)->getName()){
					userSet.insert(*it);
				}
			}
		}
	}

	double most_interesting=0;
	
	for(unsigned int i=0; i<notReviewed.size(); i++){
		double r=0;
		double w=0;
		for(unsigned int j=0; j<notReviewed[i]->getReviews().size(); j++){
			for(set<User*>::iterator it=userSet.begin(); it!=userSet.end(); ++it){
				if(notReviewed[i]->getReviews()[j]->user==(*it)->getName()){
					int rating= notReviewed[i]->getReviews()[j]->rating;
					double similarity=getRefinedSimilarity(*it, user);
					r+=(1-similarity)*rating;
					w+=(1-similarity);
				}
			}
		}
		double interestingness=0;
		if(w==0){
			
		}
		else{
		interestingness=r/w;
		}
		//cout<<notReviewed[i]->getName()<<" "<<interestingness<<endl;
		if(interestingness>most_interesting){
			most_interesting=interestingness;
			most_interesting_prod=notReviewed[i];
		}
	}
	return most_interesting_prod;
}
double MainWindow::getBasicSimilarity(User* from, User* to){
	double similarity=1;
	int myRating=0;
	int otherRating=0;	
	set<Product*> sharedProducts=setIntersection(from->getReviewedProducts(), to->getReviewedProducts());
	
	if(sharedProducts.size()==0){
		return similarity;
	}
	else{
		double running_similarity=0;
		int counter = 0;
		for(set<Product*>::iterator it2=sharedProducts.begin(); it2!=sharedProducts.end(); ++it2){
			counter++;
			for(unsigned int i=0; i<(*it2)->getReviews().size(); i++){
				if((*it2)->getReviews()[i]->user==from->getName()){
					myRating=(*it2)->getReviews()[i]->rating;
				}
				if((*it2)->getReviews()[i]->user==to->getName()){
					otherRating=(*it2)->getReviews()[i]->rating;
				}
			}
			running_similarity+=abs(myRating-otherRating)/4.0;
			
		}
		double avg_similarity=running_similarity/counter;
		return avg_similarity;
	}
			
}
double MainWindow::getRefinedSimilarity(User* first, User* end){
	//instantiate starting node
	dNode* firstNode=new dNode(first, true, 0);
	NodeComp ncomp;
	Heap<dNode*, NodeComp> pq(2, ncomp);
	pq.push(firstNode);
	vector<dNode*> tracker;
	tracker.push_back(firstNode);
	//start at "infinity"
	double minPath=2147483647;
	for(set<User*>::iterator it=dsptr->getUsers().begin(); it!=dsptr->getUsers().end(); ++it){
		//instantiate other nodes
		if(*it!=first){
			dNode*firstNeighbor=new dNode(*it, false, 2);
			pq.push(firstNeighbor);
			tracker.push_back(firstNeighbor);

		}
	}
	//keep going until we have visited all nodes
	while(!pq.empty()){
		if(pq.top()->curr==end){
			minPath=pq.top()->distance;
			break;
		}
		dNode* v=pq.top();
		v->inTree=true;
		pq.pop();
		for(unsigned int i=0; i<tracker.size(); i++){
			//found node not in our tree
			if(tracker[i]->inTree==false&&tracker[i]!=v){
				double basicSim=getBasicSimilarity(v->curr, tracker[i]->curr);
				//found shorter distance
				if(v->distance+basicSim<tracker[i]->distance){
					tracker[i]->distance=v->distance+basicSim;
					pq.reBubbleUp(tracker[i]);
					
				}
			}
		}
	}
	//delete all nodes in dijkstra's
	for(unsigned int i=0; i<tracker.size(); i++){
		delete tracker[i];
	}
	return minPath;

}