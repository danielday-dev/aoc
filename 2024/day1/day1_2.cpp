#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;


int main(){
    ifstream myfile;
    myfile.open("input.txt");
    vector <int> leftList, rightList;

    int leftNum, rightNum;
    string current_string;
    while(getline(myfile, current_string)){
        stringstream s(current_string);
        s >> leftNum >> rightNum;
        leftList.push_back(leftNum);
        rightList.push_back(rightNum);
    }

    //get similarity numbers
    map<int, int> similarityMultipliers;
    for(size_t i = 0;i < rightList.size();i++){
        try{
            similarityMultipliers[rightList[i]]++;
        }
        catch(...){
            similarityMultipliers[rightList[i]] = 1;
        }
    }

    int totalDistance = 0;
    for(size_t i = 0;i < leftList.size();i++){
        try{
            totalDistance += leftList[i]*similarityMultipliers[leftList[i]];
        }
        catch(...){
            //do nothing
        }
        }
    printf("%i", totalDistance);
}
