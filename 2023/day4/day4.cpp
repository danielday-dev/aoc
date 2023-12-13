#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ifstream myfile;
    myfile.open("input.txt");
    string line;
    int cardscore;
    int total = 0;

    while(getline(myfile, line)){
        stringstream ssLine(line);
        string card;
        string cardid;
        ssLine >> card >> cardid;

        int winner;
        int numdog;
        vector<int> winners;

        cardscore = 0;

        for(int i = 0; i < 10; i++){
            ssLine >> winner;
            winners.push_back(winner);
        }

        string stupidBar;
        ssLine >> stupidBar;

        while(ssLine >> numdog){
            if(find(winners.begin(), winners.end(), numdog) != winners.end()){
                if(cardscore){cardscore*=2;}
                else{cardscore+=1;}
            }
        }
        total += cardscore;
    }

    printf("%i", total);
    return 0;

}