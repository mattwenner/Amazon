#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "ddatastore.h"
#include "newUserDialog.h"

//needed to solve circular dependencies with main_window.h
class MainWindow;

class newUserDialog;

class loginDialog: public QDialog{
	Q_OBJECT

	public:
		loginDialog();
		loginDialog(DDataStore* ds_ptr);
		~loginDialog();
	private slots:
		void login();
		void addUser();
		void quit();

	private:
		//passed in database
		DDataStore* ptr;
		
		//GUI
		QHBoxLayout* overallLayout;
		QLabel* username;
		QLineEdit* usernameField;
		QLabel* password;
		QLineEdit* passwordField;
		QPushButton* loginButton;
		QPushButton* quitButton;
		QPushButton* makeNewAccount;
		QLabel* registered;
		QHBoxLayout* accountLayout;
		QVBoxLayout* loginLayout;
		QVBoxLayout* buttonLayout;
		
		//Error QMessageboxes
		QMessageBox* emptyError;
		QMessageBox* noUser;
		QMessageBox* wrongPassword;
		QMessageBox* lengthError;
		QMessageBox* whiteSpaceError;
		QMessageBox* sameNameError;


};
#endif