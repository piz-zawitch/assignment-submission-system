#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line = "", first = "", id = "";
    int location = 0;

    ifstream accountFile;
    accountFile.open("accounts.csv");

    getline(accountFile, line);
    getline(accountFile, line);

    location = line.find(",");
    first = line.substr(0, location);
    line = line.substr(location + 1, line.length());

    location = line.find(",");
    id = line.substr(0, location);
    line = line.substr(location + 1, line.length());


    cout << id;
    

    cin.ignore();
    cin.get();

    accountFile.close();

}