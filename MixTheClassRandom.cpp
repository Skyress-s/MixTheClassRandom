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
    namesFile.open(fileName);
    while (getline(namesFile, line))
    {
        names.push_back(line);
    }
    namesFile.close();
    
    return names;
}

int GetMinSpacing(vector<string> _names) {
    int _minSpacing{};
    for (int i = 0; i < _names.size(); i++){
        if (_names[i].length() > _minSpacing){
            _minSpacing = _names[i].length();
        }
    }
    return _minSpacing;
}


int main()
{
    //int a, b, c;
    //a = time(0);
    //for (int i = 0; i < 10000; i++)
    //{
    //    /*c = i * sin(cos(sqrt(time(0))));
    //    cout << c;*/
    //    cout << time(0);

    //}
    //b = time(0);

    //cout << endl << endl << " Total time is: " << (b - a) << endl;


    srand(time(0));
    cout << time(0) << endl;
    
    vector<string> names = GetArrayOfNames(fileName);
    
    vector<vector<int>> randomNameIndexes{};
    

    //create linearArray
    vector<int> lArray{};
    for (int i = 0; i < names.size(); i++)
    {
        lArray.push_back(i);
    }
    

    //uses the lArray to select indexes to insert into namesIndexed list
    while (lArray.size() > 0)
    {
        int test[2];


        int x = rand() % lArray.size();
        
        test[0] = lArray[x];
        
        lArray.erase(lArray.begin() + x);
        

        //same for y
        if (lArray.size() < 1)
        {
            test[1] = -10;
            randomNameIndexes.push_back({test[0], test[1]});
            break;
        }
        int y = rand() % lArray.size();
        test[1] = lArray[y];
        lArray.erase(lArray.begin() + y);


        randomNameIndexes.push_back({test[0], test[1]});
    }
    
    //checks is names is odd or even, if odd, add skybert to the names list AND changes randomnameindexes[last][1] to point to skybert
    if (randomNameIndexes.back()[1] == -10){
        names.push_back("Skybert!");
        randomNameIndexes.back()[1] = names.size() -1;
    }
    
    //gets the spacing
    int minSpacing = GetMinSpacing(names) + 2;


    //outputh he indexes

    for (int i = 0; i < randomNameIndexes.size(); i++)
    {
        int x = randomNameIndexes[i][0];
        int y = randomNameIndexes[i][1];
        
        
        int xs = minSpacing - names[x].size();
        string addx{};
        for (int i = 0; i < xs; i++){
            addx += " ";
        }

        cout << names[x] << addx << " <-----> " << "    ";
        cout << names[y] << endl;
        
    }


    return EXIT_SUCCESS;

}

