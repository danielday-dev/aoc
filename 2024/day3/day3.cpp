#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

int multiplyIfCorrect(std::string substring);
// int extractNumberFromString(std::string subString);

int main(){
    std::ifstream myfile;
    myfile.open("input.txt");

    int total = 0;
    std::string current_string;
    while(getline(myfile, current_string)){
        for(int startPoint = 0; startPoint < current_string.length(); startPoint++){
            if(current_string[startPoint] = 'm'){
                total += multiplyIfCorrect(current_string.c_str() + startPoint);
            }
        }
    }
    printf("\n%i\n", total);
}
int multiplyIfCorrect(std::string subString){
    // printf("%s\n", subString.c_str());
    // index = 4;
    // if(subString.substr(0, index) == "mul("){
    //     // confirm first number
    //     if(isdigit(subString[index])){
    //         num1 = extractNumberFromString(subString.substr(index,3));
    //         index += (int) (std::log (num1));
    //         // confirm comma
    //         if(subString[++index] == ','){
    //             //confirm second number
    //             if(isdigit(subString[++index])){
    //                 num2 = extractNumberFromString(subString.substr(index,3));
    //                 index += (int) (std::log (num1));
    //                 if(subString[++index] = ')'){
    //                     //confirm close bracket
    //                     return num1*num2;
    //                 }
    //             }
    //         }
    //     }
    // }
    char bracketCheck;
    int scanResults, num1, num2;
    scanResults = sscanf(subString.c_str(), "mul(%i,%i%c", &num1, &num2, &bracketCheck);
    // printf("%c %i\n", bracketCheck, scanResults);

    if(scanResults == 3 && bracketCheck == ')'){
        return num1*num2;
    }

    return 0;
}

// int extractNumberFromString(std::string subString){
//     //extracts a number of up to 3 digits from a string.

//     int num, numLength;

//     if(subString.length() <= 3 && isdigit(subString[2])){
//         // 3 digits confirmed
//         numLength = 3;
//     }else if (subString.length() <= 2 && isdigit(subString[1]))
//     {   // 2 digits confirmed
//         numLength = 2;
//     }else{
//         // 1 digit confirmed
//         numLength = 1;
//     }

//     return num = std::stoi(subString.substr(0,numLength));
// }