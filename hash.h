#ifndef HASH_H
#define HASH_H
#include <string>
#include <cmath>

inline int hash(string password){
	long long long_long=0;
	int exponent=0;
	for(int i=password.size()-1; i>=0; i--){
		long_long+=(long long) password[i]* (long long) pow(128, exponent);
		exponent++;
	}
	unsigned int w4=long_long%65521;
	long_long=long_long/(long long) 65521;
	unsigned int w3=long_long%65521;
	long_long=long_long/(long long) 65521;
	unsigned int w2=long_long%65521;
	long_long=long_long/(long long) 65521;
	unsigned int w1=long_long&65521;
	unsigned int* arr=new unsigned int[4];
	arr[0]=w1;
	arr[1]=w2;
	arr[2]=w3;
	arr[3]=w4;
	unsigned int final_password=(45912 * w1 + 35511 * w2 + 65169 * w3 + 4625 * w4) % 65521;
	return final_password;
}
#endif