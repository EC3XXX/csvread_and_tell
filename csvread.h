//.csv data file input .h
//by EC3XXX
//2023/9/13
//tools to read .csv data file
//easy to use examples for model checking

//CANNOT USE WITHOUT csvread.cpp FILE

//avoid redeclaration
#ifndef CSVREAD_H
#define CSVREAD_H

//include files
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

//std namespace
using namespace std;

//defination of structrue_csv, using in csvread.cpp and the file where need csvread functions
struct structure_csv{
	vector<string> name;			//name storage, strings
	vector<vector<double>> data;	//data storage, double, 2d
};

void csvread(string filename);				//function csvread, use this to read csvfile
double csvtell(string name_of_col,int row);	//function csvtell, return data in col named name_of_col and row row
											//CAN ONLY USE THIS FUNCTION AFTER USED csvread(filename) ONCE
											//THE ROW NUMBERS START FROM ZERO

#endif
