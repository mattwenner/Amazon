#ifndef  MAIN_WINDOW_H
#define  MAIN_WINDOW_H

#include "dialog.h"
#include "ddatastore.h"
#include "product.h"
#include "reviewdialog.h"
#include "logindialog.h"
#include "recommenddialog.h"
#include "heap.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QString>
#include <QRadioButton>
#include <QComboBox>
#include <QDialog>
#include <QMessageBox>
#include <string>
#include <vector>

//nodes for dijkstr'as
struct dNode{
	User* curr;
	bool inTree;
	double distance;
	dNode(User* curr_, bool inTree_, double distance_):
		curr(curr_),
		inTree(inTree_),
		distance(distance_){}
	
};

//comparator for dijklstra nodes
struct NodeComp{
	bool operator()(dNode* lhs, dNode* rhs){
		return lhs->distance < rhs->distance;
	}

};

//for circular dependencies
class reviewDialog;

class MainWindow : public QDialog
{
	Q_OBJECT
public:
	//default construtor
	MainWindow();
	//constructor used
	MainWindow(DDataStore* ds, User* user_);
	~MainWindow();
	void updateReviews(int index);

private slots:
	void search();
	void sortAlphabetically();
	void sortByRating();
	void addToCart();
	void viewCart();
	void displayReviews(int index);
	void addReview();
	void saveChanges();
	void quit();


private:
	double getBasicSimilarity(User* to, User* from);
	double getRefinedSimilarity(User* first, User* end);
	Product* makeRecommendation();

	//passed in ddatastore
	DDataStore* dsptr;
	//stores search hits
	std::vector<Product*> hits;
	//user
	User* user;
	//GUI

	//overall layout
	QHBoxLayout* overallLayout;

	//everything related to entering searches
	QVBoxLayout* searchLayout;
	QLineEdit* search_input;
	QLabel* search_terms;

	//everything related to search type
	QRadioButton* andButton;
	QRadioButton* orButton;
	QLabel* search_type;
	QVBoxLayout* andOrLayout;
	QPushButton* searchButton;

	//everything related to search results and sorting them
	QVBoxLayout* resultsLayout;
	QPushButton* sortAlphaButton;
	QPushButton* sortRatingButton;
	QListWidget* search_results;

	//everything related to reviews
	QListWidget* reviews;
	QPushButton* reviewButton;
	QVBoxLayout* reviewLayout;

	//everything related to users
	QVBoxLayout* userLayout;
	
	QPushButton* addButton;
	QPushButton* viewButton;

	//everything related to saving and quitting
	QVBoxLayout* quitLayout;
	QPushButton* saveButton;
	QPushButton* quitButton;
	QLabel* enterFileName;
	QLineEdit* filename;

	//title of mainwindow
	QString title;

	//more organization
	QVBoxLayout* searching;
	QVBoxLayout* choosing;

	//if user has reviewed everything
	QMessageBox* noMas;

};

#endif