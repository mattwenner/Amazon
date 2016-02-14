#include "msort.h"
#include <iostream>

using namespace std;
//sort alphabetically
struct AlphaStrComp {
    bool operator()(const std::string& lhs, const std::string& rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs <= rhs; 
    }
  };
//sort by length of string
struct LengthStrComp {
   bool operator()(const std::string& lhs, const std::string& rhs){
   // Uses string's built in operator< 
   // to do lexicographic (alphabetical) comparison
   		return lhs.size() <= rhs.size(); 
   }
  };
//sort reverse alphabetically
struct AlphaRStrComp{
	bool operator()(const std::string& lhs, std::string& rhs){
		return rhs<=lhs;
	}
};
//compare chars
struct CharComp{
	bool operator()(const char&lhs, char&rhs){
		return lhs<=rhs;
	}
};
//compare ints
struct IntComp{
	bool operator()(const int& lhs, const int& rhs){
		return lhs<=rhs;
	}
};
//compare doubles
struct DoubleComp{
	bool operator()(const double& lhs, const double& rhs){
		return lhs<=rhs;
	}
};


int other_main(){
	DoubleComp ic;
	vector<double>arr;
	for(int i=10; i>5; i--){
		arr.push_back(i);
	}
	arr.push_back(0);
	arr.push_back(7);
	arr.push_back(-10);
	arr.push_back(100);
	arr.push_back(.5);
	arr.push_back(4.5);
	arr.push_back(9.999);

	//AlphaStrComp asc;
	vector<string> arr2;
	arr2.push_back("apple2");
	arr2.push_back("apple1");
	arr2.push_back("bacon");
	arr2.push_back("crab1");
	arr2.push_back("crab");
	arr2.push_back("bacon");
	arr2.push_back("apple");
	arr2.push_back("2");
	arr2.push_back("az");
	arr2.push_back("0");
	LengthStrComp lc;
	AlphaRStrComp arsc;

	mergeSort(arr, ic);
	for(unsigned int i=0; i<arr.size(); i++){
		
		cout<<arr[i]<<endl;
	}
	cout<<endl;
	
	mergeSort(arr2, lc);
	for(unsigned int i=0; i<arr2.size();i++){
		cout<<arr2[i]<<endl;
	}

	cout<<endl;
	mergeSort(arr2, arsc);
	for(unsigned int i=0; i<arr2.size();i++){
		cout<<arr2[i]<<endl;
	}
	cout<<endl;

	return 0;
}
