#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
using namespace std;

// go farther than the furthest recorded distance in each race
// time is a constraint
// Charge time vs time going forward

//  input is race time and distance to beat

//  starting speed is 0 mm/ms
//  each millisecond spent holding down adds 1 to speed

// Determine the number of ways you could beat the record in each race.
// What do you get if you multiply these numbers together?

int examineRace(int, int);

int main(){
    ifstream myfile;
    myfile.open("input.txt");
    string line;
    string dump;

    getline(myfile, line);
    stringstream ssLine1(line);

    getline(myfile, line);
    stringstream ssLine2(line);

    int numInputs = 4;

    int times[numInputs];
    int distances[numInputs];
    int possible_results[numInputs];
    int results = 1;

    ssLine1 >> dump;
    ssLine2 >> dump;
    for(int i = 0; i < numInputs; i++){
        ssLine1 >> times[i];
        ssLine2 >> distances[i];
        possible_results[i] = examineRace(times[i], distances[i]);
        results *= possible_results[i];
    }

    printf ("%i", results);

    return EXIT_SUCCESS;

}

/**
 * @return number of possible ways to win race
*/
int examineRace(int maxTime, int goalDistance){
    //find min time
    //find max time
    //return max - min

    //iterate through entire race time until end time is found
    // find min and max times mathematically

    int possibleValues;
    int minimum;
    bool minFound = false;
    for(int speed = 0; speed <= maxTime; speed++){

        int boatDistance = (maxTime - speed) * speed;
        if (!minFound && (boatDistance > goalDistance)){
            // get max
            minFound = true;
            minimum = speed;
        }
        if( minFound && ((boatDistance <= goalDistance))){
            // get min
            possibleValues = speed - minimum;
            break;
        }
    }
    return possibleValues;
}