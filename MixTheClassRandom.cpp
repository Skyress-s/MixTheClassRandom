// MixTheClassRandom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>

using namespace std;
string fileName = "class.txt";





vector<string> GetArrayOfNames(string _fileName) {
    //new logic using vectors

    vector<string> names;

    string line{};
    ifstream namesFile{};
    namesFile.open("class.txt");
    while (getline(namesFile, line))
    {
        names.push_back(line);
    }
    namesFile.close();
    
    return names;
    
}



int main()
{
    srand(time(0));
    vector<string> names = GetArrayOfNames(fileName);
    

    
    

    //srand(time(0));
    ////gets the array of names
    //int numOfNames = NumOfPeople();
    //vector<string> names{};
    //names = GetArrayOfNames(numOfNames);

    
    
    

    

    return EXIT_SUCCESS;
}

