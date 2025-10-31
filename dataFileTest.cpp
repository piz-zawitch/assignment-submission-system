#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line = "", first = "", id = "", w[5] = {"","","","","",};
    int location = 0, accID = 0, accColumn[accID] = {};

    ifstream accountFile;
    accountFile.open("accounts.csv");
    getline(accountFile, line);
    
    //process loading
    while( getline(accountFile, line)){

    location = line.find(",");
    first = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(",");
    id = line.substr(0, location);
    line = line.substr(location + 1, line.length());
    
    for(int i = 0;i<5;i++)
    {
    location = line.find(",");
    w[i] = line.substr(0, location);
    line = line.substr(location + 1, line.length());
    };
    
    cout << first << endl;
    cout << id << endl;
    for(int i = 0;i<5;i++)
    {
    cout << w[i];
    }
    cout << endl << endl;
        }

    

    

    cin.ignore();
    cin.get();

    accountFile.close();

}