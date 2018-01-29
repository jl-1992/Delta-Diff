//includes for I/O
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>

using namespace std;

//function to check if command-line args exist
bool exists(const char *f1, const char *f2){
	ifstream ifile1(f1);
	ifstream ifile2(f2);
	return ifile1 && ifile2;
}

//function to extract whitespace from getline strings.
//An example: input string = "a b c d"
//		      output string = "abcd"
//I basically just break the input string down into substrings and
//concatenate them
string extractWS(string str){
	int count=0;
	for(int i=0; i<str.length();i++){
		if(str[i]==' ')
			++count;
	}
	while(count>0){
		for(int i=0; i<str.length(); i++){
			if(str[i]==' '){
				str=str.substr(0,i) + str.substr(i+1,str.length()-1);
				--count;
				break;
			}
		}
	}
	return str;
}

int main(int argc, char *argv[]){
	//check if args exist or send error message
	if(!exists(argv[1],argv[2]))
		cout<< "FILE NOT FOUND" << endl;

	//input file variables and getline strings declared
	ifstream ifile1;
	ifstream ifile2;
	ifile1.open(argv[1]);
	ifile2.open(argv[2]);
	string s1,s2;
	int cmp_len,z;

	//while no errors are encountered
	while(ifile1.good() && ifile2.good())
	{
		//save line into respective strings
		getline(ifile1,s1);
		getline(ifile2,s2);

		//extract whitespace from those strings
		s1=extractWS(s1);
		s2=extractWS(s2);

		//see which string is longer for comparisons
		if(s2.length()>s1.length())
			cmp_len=s1.length();
		else
			cmp_len=s2.length();

		//defined an int 'z' that is left out of loop scope, so that
		//it can be used in the end when needed. This part of the code
		//compared the characters to each other and outputs it if it's
		//different.
		for(z=0; z<cmp_len; z++){
			if(s1[z]!=s2[z])
				cout << s1[z];
		}		

		//if lines were of different lengths, then extra characters
		//are output
		if(cmp_len==s1.length())
			cout << s2.substr(z);
		else
			cout << s1.substr(z);
	}
	cout << endl;

	//For the main ouput, I assumed it would be alright to simply
	//sequentially output each character to the terminal.

	ifile1.close();
	ifile2.close();

	return 0;
}