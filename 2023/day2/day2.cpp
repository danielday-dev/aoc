/* input consists of
Game X: A red, B blue, C green; D red, E green
Game X+1 ...

effectively 2d list delimited by ; and ,
(this would be easy in Python and its split)
*/

/* I could split with a for loop

*/

/* Work out which games are legal
    (12 red, 13 green, 14 blue) */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


int main(){
    int legalRed = 12;
    int legalGreen = 13;
    int legalBlue = 14;
    string line;

    ifstream myfile;
    myfile.open("input.txt");

    int gameID = 1;
    int idSum = 0;


    while (getline(myfile, line)){
        string game;
        string gamenum;
        stringstream ssLine(line);
        ssLine >> game >> gamenum;

        int maxRed = 0;
        int maxGreen = 0;
        int maxBlue = 0;

        string colour;
        int numOfColour;
        char delimiter;

        while(ssLine >> numOfColour >> colour){
            switch(colour[0]){
                case 'r':{if(numOfColour > maxRed){maxRed = numOfColour;}} break;
                case 'g':{if(numOfColour > maxGreen){maxGreen = numOfColour;}} break;
                case 'b':{if(numOfColour > maxBlue){maxBlue = numOfColour;}} break;
            }
            // , or ; (for later)
            delimiter = colour.back();
        }

        //decide if line is legal:
        if(maxRed <= legalRed && maxGreen <= legalGreen && maxBlue <= legalBlue){
            idSum += gameID;
        }
        gameID++;
    }
    printf("%i", idSum);
    return 0;
}