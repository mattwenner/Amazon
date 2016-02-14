#ifndef  MSORT_H
#define  MSORT_H
#include <iostream>
#include <vector>
#include <string>

template<class T, class Comparator>
	void merge(std::vector<T>& myArray, std::vector<T>&first_half, std::vector<T>&second_half, Comparator comp){
		//vector for putting sorted items into
		std::vector<T> temp;
		int x=0;
		int y=0;
		//continues until everything sorted
		while( x<first_half.size()&& y<second_half.size()){
			if(comp(first_half[x],second_half[y])){
				temp.push_back(first_half[x]);
				x++;
			}
			else{
				temp.push_back(second_half[y]);
				y++;
			}

		}
		//puts remainder of first half (if necessary) into sorted vector
		while(x<first_half.size()){
			temp.push_back(first_half[x]);
			x++;
		}
		//puts remainder of second half (if necessary) into sorted vector
		while(y<second_half.size()){
			temp.push_back(second_half[y]);
			y++;
		}
		//copy over sorted contents
		for(unsigned int i=0; i<temp.size(); i++){
			myArray[i]=temp[i];
		}
	}

template <class T, class Comparator>
  void mergeSort (std::vector<T>& myArray, Comparator comp){
  	//done splitting into smaller parts
  	if(myArray.size()<2){
  		return;
  	}
  	//split vector into first half
  	std::vector<T>first_half(myArray.begin(), myArray.begin()+myArray.size()/2);
  	//sort first half
  	mergeSort(first_half,comp);
  	//splits vector into second half
  	std::vector<T>second_half(myArray.begin()+myArray.size()/2, myArray.end());
  	//sort second half
  	mergeSort(second_half,comp);
  	//merge contents in sorted order
  	merge(myArray, first_half, second_half, comp);
  	
  }

#endif