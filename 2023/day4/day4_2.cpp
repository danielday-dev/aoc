#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


int main(){
    ifstream myfile;
    myfile.open("input.txt");
    string line;
    int numMatching;
    vector<int> multipliers;
    int currentID = 0;

    while(getline(myfile, line)){
        stringstream ssLine(line);
        string card;
        string cardid;
        ssLine >> card >> cardid;

        int winner;
        int numdog;
        vector<int> winners;

        numMatching = 0;

        for(int i = 0; i < 10; i++){
            ssLine >> winner;
            winners.push_back(winner);
        }

        string stupidBar;
        ssLine >> stupidBar;

        while(ssLine >> numdog){
            if(find(winners.begin(), winners.end(), numdog) != winners.end()){
                numMatching += 1;
            }
        }

        if(multipliers.size() < currentID+1){
            multipliers.push_back(1);
        }

        for(int i = currentID+1; i <= currentID + numMatching; i++){
            while(i >= multipliers.size()){
                multipliers.push_back(1);
            }
            multipliers[i] += multipliers[currentID];
            }
        currentID +=1;
    }

    int total = accumulate(multipliers.begin(), multipliers.end(), 0);
    printf("%i", total);
    cout << " " << multipliers.size() << " " << currentID;

    return 0;
}