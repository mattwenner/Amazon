#ifndef  DIALOG_H
#define  DIALOG_H

#include "ddatastore.h"
#include "main_window.h"
#include "product.h"
#include <QDialog>
#include <QHBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <string>
#include <vector>

class Dialog : public QDialog
 {
    Q_OBJECT

  public:
  	Dialog();
    Dialog(DDataStore *dsptr, std::string username);
    ~Dialog();
    void addProducts(std::string name);

   private slots:
   	void buyCart();
   	void removeItem();
   	void closeDialog();
  private:
  	//pointer that allows access to our stored data
  	 DDataStore* datastore;

  	std::string username_;
  	std::string title;

  	//GUI

  	QHBoxLayout* layout;
  	QListWidget* list;
  	QPushButton* buyButton;
  	QPushButton* removeButton;
  	QVBoxLayout* userInterface;
  	QPushButton* closeButton;
};

#endif
