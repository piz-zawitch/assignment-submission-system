#include <iostream>
#include <fstream>
#include "dataFileTest.h"

using namespace std;

void accounts()
{   
//location is horizontal of columns
    ifstream columnFile;
    columnFile.open("accounts.csv");   

    int sc = 0, e;
    string column;
    //process of column counter into sc
      
    while( getline(columnFile, column)){
        sc++;
        cout << sc << endl;
    } cout << endl;

    cout <<"number of sc "<< sc << endl;
   
    string line, first[sc], id[sc], w[5][sc] {"", "", "", "", ""}; 
    int location = 0, studentCount = 0;
   
    ifstream accountFile;
    accountFile.open("accounts.csv");     
    getline(accountFile, line);
   
    //process loading
    while( getline(accountFile, line)){

        studentCount ++;
    location = line.find(",");
    first[studentCount] = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(",");
    id[studentCount] = line.substr(0, location);
    line = line.substr(location + 1, line.length());
    
    for(int i = 0;i<5;i++)
    {
    location = line.find(",");
    w[i][studentCount] = line.substr(0, location);
    line = line.substr(location + 1, line.length());
    };
    
    cout << first[studentCount] << endl;
    cout << id[studentCount] << endl;
    for(int i = 0;i<5;i++)
    {
    cout << w[i][studentCount];
    }
    cout << endl << endl;
        }

    cout << first[2] << endl;

    cin.ignore();
    cin.get();

    

    accountFile.close();

}