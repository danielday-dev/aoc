
/* So the difference here is that i need to go thorugh each hand in a game
    and work out the maximum of each colour. This means checking the delimiter ; if the hand is done*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int getPower(int numRed, int numGreen, int numBlue){
    return numRed * numGreen * numBlue;
}

int main(){
    string line;

    ifstream myfile;
    myfile.open("input.txt");

    int sum_of_powers = 0;

    while (getline(myfile, line)){
        string game;
        string gamenum;
        stringstream ssLine(line);
        ssLine >> game >> gamenum;

        // the minimum amount for the game to be legal
        int maxRed = 0;
        int maxGreen = 0;
        int maxBlue = 0;

        string colour;
        int numOfColour;
        char delimiter;

        while(ssLine >> numOfColour >> colour){
            /* parse the data first then get minimum of the hand*/
            switch(colour[0]){
                case 'r':{if(numOfColour > maxRed){maxRed = numOfColour;}} break;
                case 'g':{if(numOfColour > maxGreen){maxGreen = numOfColour;}} break;
                case 'b':{if(numOfColour > maxBlue){maxBlue = numOfColour;}} break;
            }
            // , or ; (for later)
            // delimiter = colour.back();
        }

        // calculate sum of powers
        sum_of_powers += getPower(maxRed, maxGreen, maxBlue);
    }
    printf("%i", sum_of_powers);
    return 0;
}