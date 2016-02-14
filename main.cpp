#include "logindialog.h"
#include "ddatastore.h"
#include "db_parser.h"
#include "product_parser.h"
#include "main_window.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>



using namespace std;
int main(int argc, char* argv[]){

	if(argc < 2){
    cerr << "Please specify a database file" << endl;
  }

  /****************
   * Declare your derived DataStore object here replacing
   *  DataStore type to your derived type
   ****************/
  DDataStore ds;

  DDataStore* ds_ptr=&ds;
  // Instantiate the parser
  DBParser parser;

  // Instantiate the individual product parsers we want
  parser.addProductParser(new ProductBookParser);
  parser.addProductParser(new ProductClothingParser);
  parser.addProductParser(new ProductMovieParser);

  if( parser.parse(argv[1], ds) ){
    cerr << "Error parsing!" << endl;
    return 1;
  }

	QApplication app(argc, argv);
  loginDialog login(ds_ptr);
  login.exec();

	return app.exec();

}