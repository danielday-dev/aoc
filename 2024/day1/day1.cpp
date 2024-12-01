#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
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

    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());

    int totalDistance = 0;
    for(size_t i = 0;i < leftList.size();i++){
        totalDistance += abs(leftList[i] - rightList[i]);
        }
    printf("%i", totalDistance);
}
