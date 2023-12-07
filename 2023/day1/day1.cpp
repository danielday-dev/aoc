#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* 1000 lines of input, each with 2 digits
    to get the 2 digits, grab the first and last digit
    answer is sum of all numbers
    */

/* running total, take cin then split it and search through
    upon finding first digit, set digit 1 and digit 2 to the first digit
    upon finding subsequent digits, set digit 2 to the subsequent digit
    jam digits 1 and 2 together to create number
    add number to total
    repeat*/

int main(){
    ifstream myfile;
    myfile.open("input.txt");
    int total = 0;
    int digit1, digit2;
    string current_string;

    int first_digit;
    int second_digit;
    int digit;
    bool first_dig_fnd;
    while ( getline (myfile, current_string)){
        first_dig_fnd = false;
        for(int i = 0; i<current_string.length(); i++){
            switch(current_string[i]) {
                case '1': digit = 1; break;
                case '2': digit = 2; break;
                case '3': digit = 3; break;
                case '4': digit = 4; break;
                case '5': digit = 5; break;
                case '6': digit = 6; break;
                case '7': digit = 7; break;
                case '8': digit = 8; break;
                case '9': digit = 9; break;
                case '0': digit = 0; break;
                default:   continue;
            }
            if(first_dig_fnd == false){
                first_digit = digit;
                first_dig_fnd = true;
            }
            second_digit = digit;
        }

        total += first_digit*10 + second_digit;
    }
    printf("%i", total);
    return 0;
}