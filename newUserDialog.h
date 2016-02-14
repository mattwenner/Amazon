#ifndef NEWUSERDIALOG_H
#define NEWUSERDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "ddatastore.h"

//for ciruclar dependencies
class MainWindow;

class loginDialog;

class newUserDialog: public QDialog{

	Q_OBJECT
	public:
		
		newUserDialog(DDataStore* db_ptr,string& name_, string& password_);
		~newUserDialog();

	private slots:
		void cancel();
		void addUser();
	private:
		//passed in
		DDataStore* db;
		string name;
		string password;

		//GUI
		QHBoxLayout* overallLayout;
		QVBoxLayout* enterLayout;
		QVBoxLayout* buttonLayout;
		//fields for making new account
		QLabel* ageLabel;
		QLineEdit* ageEdit;
		QLabel* creditLabel;
		QLineEdit* creditEdit;
		QPushButton* addButton;
		QPushButton* quitButton;
		//Error messageboxes
		QMessageBox* emptyError;
		QMessageBox* numError;
		

};
#endif