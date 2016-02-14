#include "reviewdialog.h"
#include "newUserDialog.h"
#include "hash.h"

loginDialog::loginDialog(){}

loginDialog::loginDialog(DDataStore* ds_ptr){
	ptr=ds_ptr;
	
	setWindowTitle("Welcome to Amazon!");
	overallLayout=new QHBoxLayout();
	QHBoxLayout* accountLayout=new QHBoxLayout();
	QVBoxLayout* loginLayout=new QVBoxLayout();
	QVBoxLayout* buttonLayout=new QVBoxLayout();
	username=new QLabel("Enter username:");
	usernameField=new QLineEdit();
	password=new QLabel("Enter password:");
	passwordField=new QLineEdit();
	passwordField->setEchoMode(QLineEdit::Password);
	registered=new QLabel("If registered, log in. Else, make account.");
	loginLayout->addWidget(registered);
	loginLayout->addWidget(username);
	loginLayout->addWidget(usernameField);
	loginLayout->addWidget(password);
	loginLayout->addWidget(passwordField);

	loginButton=new QPushButton("Login");
	connect(loginButton, SIGNAL(clicked()), this, SLOT(login()));
	buttonLayout->addWidget(loginButton);
	
	
	makeNewAccount=new QPushButton("Create new account");
	connect(makeNewAccount, SIGNAL(clicked()), this, SLOT(addUser()));
	
	buttonLayout->addWidget(makeNewAccount);
	accountLayout->addLayout(loginLayout);
	accountLayout->addLayout(buttonLayout);
	overallLayout->addLayout(accountLayout);
	quitButton=new QPushButton("Quit");
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
	buttonLayout->addWidget(quitButton);
	emptyError=new QMessageBox();
	emptyError->setText("Error, one or more fields empty");
	noUser=new QMessageBox();
	noUser->setText("Error, no user with that username in database");
	wrongPassword=new QMessageBox();
	wrongPassword->setText("Error, wrong password for that username");
	lengthError=new QMessageBox();
	lengthError->setText("Error, requested password is longer than 8 characters");
	whiteSpaceError=new QMessageBox();
	whiteSpaceError->setText("Error, whitespace is not allowed in password");
	sameNameError=new QMessageBox();
	sameNameError->setText("Error, requested username already belongs to another user. Please choose a different username");
	setLayout(overallLayout);
}

loginDialog::~loginDialog(){
	qDeleteAll(this->children());

}

void loginDialog::login(){
	//one or more fields empty
	if(usernameField->text().isEmpty()||passwordField->text().isEmpty()){
		emptyError->exec();
		return;
	}
	
	User* potential_user=NULL;
	string username=usernameField->text().toStdString();
	for(set<User*>::iterator it=ptr->getUsers().begin(); it!=ptr->getUsers().end(); ++it){
		if((*it)->getName()==username){
			
			potential_user=*it;
		}
	}
	string password=passwordField->text().toStdString();
	//makes sure password is correct
	int hashed_num=hash(password);
	if(potential_user){
		if(potential_user->getPassword()==hashed_num){
			close();
			MainWindow mainWindow(ptr, potential_user) ;
	 		mainWindow.exec();
			show();
			
			
		}
		else{
			wrongPassword->exec();
			return;
		}
	}
	else{
		noUser->exec();
		return;
	}
}

void loginDialog::addUser(){
	//one or more fields empty
	if(usernameField->text().isEmpty()||passwordField->text().isEmpty()){
		emptyError->exec();
		return;
	}
	string password=passwordField->text().toStdString();
	//makes sure password isn't longer than 8 characters
	if(password.size()>8){
		lengthError->exec();
		return;
	}
	for(unsigned int i=0; i<password.size(); i++){
		if(password[i]==' '){
			whiteSpaceError->exec();
			return;
		}
	}
	
	for(set<User*>::iterator it=ptr->getUsers().begin(); it!=ptr->getUsers().end(); ++it){
		if ((*it)->getName()==usernameField->text().toStdString()){
			sameNameError->exec();
			return;
		}
	}
	//creation of new user
	string username=usernameField->text().toStdString();
	newUserDialog* NUD= new newUserDialog(ptr, username, password);
	NUD->exec();

	delete NUD;

}

void loginDialog::quit(){
	close();
}
