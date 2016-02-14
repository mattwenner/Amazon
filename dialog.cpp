#include "dialog.h"
#include <sstream>


using namespace std;

Dialog::Dialog(){}

Dialog::Dialog(DDataStore* dsptr, string username){
	username_=username;
	title=username_+"'s "+ "Cart";
	setWindowTitle(QString::fromStdString(title));
	datastore=dsptr;
	layout=new QHBoxLayout();
	list=new QListWidget();
	
	buyButton=new QPushButton("Buy-Cart");
	connect(buyButton, SIGNAL(clicked()), this, SLOT(buyCart()));
	removeButton=new QPushButton("Remove Selected Item");
	connect(removeButton, SIGNAL(clicked()), this, SLOT(removeItem()));
	closeButton=new QPushButton("Click to close");
	connect(closeButton, SIGNAL(clicked()), this, SLOT(closeDialog()));
	userInterface=new QVBoxLayout();
	userInterface->addWidget(buyButton);
	userInterface->addWidget(removeButton);
	userInterface->addWidget(closeButton);
	layout->addWidget(list);
	layout->addLayout(userInterface);

	setLayout(layout);
	//adds products in user cart to list widget
	addProducts(username_);

}

Dialog::~Dialog(){
	qDeleteAll(this->children());

}

void Dialog::addProducts(string name){
	for(unsigned int i=0; i<datastore->getUserCart(name).size(); i++){
		stringstream ss;
		ss<<datastore->getUserCart(name)[i]->getName()<<'\n'<<datastore->getUserCart(name)[i]->getPrice();
		list->addItem(QString::fromStdString(ss.str()));
	}
}

void Dialog::buyCart(){
	int marker=0;
            
    //continue buying until user has no more money or there is nothing in his cart
    while((datastore->getUserInfo(username_))->getBalance()>0&&marker<((signed) datastore->getUserCart(username_).size())){
      //user has enough money and item is in stock
      if((datastore->getUserInfo(username_))->getBalance()-(datastore->getUserCart(username_)[marker]->getPrice())>0&&datastore->getUserCart(username_)[marker]->getQty()>0){
        (datastore->getUserInfo(username_))->deductAmount(datastore->getUserCart(username_)[marker]->getPrice());
        //decrement product quantity
        datastore->getUserCart(username_)[marker]->subtractQty(1);
        //remove item from user cart
        datastore->getUserCart(username_).erase(datastore->getUserCart(username_).begin()+marker);                     
        marker=-1;//reset marker, so it will restart looking through user cart after vector has been changed              
      }
    //look at next item
    marker++;
    }
    //refresh user's cart
    list->clear();
    addProducts(username_);
}

void Dialog::removeItem(){
	if(list->currentItem()==NULL){
		return;
	}
	else{
		(datastore->getUserCart(username_)).erase((datastore->getUserCart(username_)).begin()+list->currentRow());
		list->removeItemWidget(list->currentItem());
		list->clear();
		addProducts(username_);//remake?
	}
}

void Dialog::closeDialog(){
	close();
}