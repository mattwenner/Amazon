#include "newUserDialog.h"
#include "hash.h"
#include <sstream>

newUserDialog::newUserDialog(DDataStore* db_ptr, string& name_, string& password_){
	db = db_ptr;
	name=name_;
	password=password_;
	overallLayout=new QHBoxLayout();
	enterLayout=new QVBoxLayout();
	buttonLayout=new QVBoxLayout();
	
	ageLabel=new QLabel("Enter age:");
	ageEdit=new QLineEdit();
	creditLabel=new QLabel("Enter credit:");
	creditEdit=new QLineEdit();
	
	enterLayout->addWidget(ageLabel);
	enterLayout->addWidget(ageEdit);
	enterLayout->addWidget(creditLabel);
	enterLayout->addWidget(creditEdit);
	addButton=new QPushButton("Add User");
	connect(addButton, SIGNAL(clicked()), this, SLOT(addUser()));
	quitButton=new QPushButton("Cancel");
	connect(quitButton, SIGNAL(clicked()), this, SLOT(cancel()));
	emptyError=new QMessageBox();
	emptyError->setText("One or more fields are empty.");
	numError=new QMessageBox();
	numError->setText("Error, did not enter number values for either age or credit");
	
	buttonLayout->addWidget(addButton);
	buttonLayout->addWidget(quitButton);
	overallLayout->addLayout(enterLayout);
	overallLayout->addLayout(buttonLayout);
	setLayout(overallLayout);


}

newUserDialog::~newUserDialog(){
	

	qDeleteAll(this->children());
}

void newUserDialog::addUser(){
	//one or more fields empty
	if(ageEdit->text().isEmpty()||creditEdit->text().isEmpty()){
		emptyError->exec();
		return;
	}
	string age=ageEdit->text().toStdString();
	string credit=creditEdit->text().toStdString();
	
	//makes sure only integers are entered
	for(unsigned int j=0; j<age.size(); j++){
		if(isdigit(age[j])==false){
			numError->exec();
			return;				
		}
	}
	//makes sure only integers are entered
	for(unsigned int j=0; j<credit.size(); j++){
		if(isdigit(credit[j])==false){
			numError->exec();
			return;				
		}
	}
	

	int age_=atoi(age.c_str());
	int credit_=atoi(credit.c_str());
	int hashed_password=hash(password);
	//create new user
	User* newUser=new User(name, age_, credit_, 0,hashed_password);
	db->addUser(newUser);
	QMessageBox created;
	ostringstream ss;
	ss<<"Created new account!"<<"\n"<<"\n"<<"New user info: "<<"\n"<<"Name: "<<name<<"\n"<<"Password: "<<password<<"\n"<<"Age: "<<age_<<"\n"<<"Credit: "<<credit_<<"\n";
	created.setText(QString::fromStdString(ss.str()));
	created.exec();
	close();

}

void newUserDialog::cancel(){
	close();
}