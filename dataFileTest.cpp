#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream accountFile("accounts.csv");

    string text;
    while(0)
    {
    getline(accountFile, text);
    }
    cout << text;
}