//.csv data file input .cpp
//by EC3XXX
//2023/9/13
//tools to read .csv data file
//easy to use examples for model checking

//CANNOT USE WITHOUT csvread.h FILE AND INCLUDE IT
//DECLARE struct structure_csv csv_csvread AGAIN AT THE TOP OF FILE WHICH ARE USING CSVREAD

//connection with .h file
#include "csvread.h"

//std namespace
using namespace std;

//vectors using to record csv contents
//defined in .h file
extern struct structure_csv csv_csvread;

//function csvread, use this to read csvfile
void csvread(string filename)
{
	ifstream data(filename);
	
	//record the name of columns and store into vector<string> name
	string firstline;
	getline(data,firstline);						//read first line only
	stringstream firstlinestream(firstline);
	string firstcell;
	while(getline(firstlinestream,firstcell,','))	//',' means gap
	{
		csv_csvread.name.push_back(firstcell);		//store names as string
	}
	
	//record data and store into vector<vector<double>> data
	//because of pointer moving in previous recording, names aren't included in data vector
	string line;
	while(getline(data,line))					//read other lines
	{
		stringstream linestream(line);
		string cell;
		vector<double> tempdata;
		while(getline(linestream,cell,','))		//',' means gap
		{
			tempdata.push_back(stod(cell));		//std::stod(), transfer string into double
		}
		csv_csvread.data.push_back(tempdata);	//store line data into form data
	}
	
	data.close();
}

//function csvtell, return data in col named name_of_col and row row
//CAN ONLY USE THIS FUNCTION AFTER USED csvread(filename) ONCE
//THE ROW NUMBERS START FROM ZERO
double csvtell(string name_of_col,int row)
{
	auto f = find(csv_csvread.name.begin(),csv_csvread.name.end(),name_of_col); //find which col the name is in
	int col = distance(csv_csvread.name.begin(),f);								//locate the col and row
	return csv_csvread.data[row][col];											//return
}

/*
int main(int argc,char *argv[])
{
	void csvread(string filename);
	double csvtell(string name_of_col,int row);
	csvread("test.csv");
	cout << csv.data[3][3] << endl;
	cout << csvtell("psisbx",3);
	
	
	return 0;
}*/
