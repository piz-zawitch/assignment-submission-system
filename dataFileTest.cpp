#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string line = "", first = "";
    int location = 0;

    ifstream accountFile;
    accountFile.open("accounts.csv");

    getline(accountFile, line);
    getline(accountFile, line);

    cin.ignore();
    cin.get();

    accountFile.close();

}