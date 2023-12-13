#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//maybe instead do it with a coordinate system that is heavier on memory rather than 3 lines.

/* Im thinking that 3 lines should be loaded at once?*/

/* Find symbol then check ajacent for numbers
    ^this one
    or
    .
    find number then check for adjacent symbols*/

// int grabNumber(string line, int found_idx){
//     int final_num = line[found_idx];
//     int working_idx;

//     if(found_idx > 0){
//         working_idx = found_idx -1; //todo fix seg fault
//     // check to the left
//         while(isdigit(line[working_idx]) && working_idx > 0){
//             final_num = final_num + 10*line[working_idx];

//             working_idx--;
//         }
//         }
//     //  check to the right
//     if(found_idx + 1 < line.length()){
//         working_idx = found_idx + 1;

//         while(isdigit(line[working_idx]) && working_idx < line.length()){
//             final_num = 10 * final_num + line[working_idx];

//             working_idx++;
//         }
//     }
//     return final_num;
// }

bool isSymbol(char guy){
    return !isdigit(guy) && guy != '.';
}

int main(){
    vector <string> lines;
    string line;
    int numdigits;
    int numsymbols;
    int total = 0;
    ifstream myfile;
    myfile.open("input.txt");


    while(getline(myfile, line)){
        lines.push_back(line);
    }

    for(size_t i = 0; i < lines.size(); i++){
        line = lines[i];
        numdigits = 0;
        numsymbols = 0;
        for(size_t j = 0; j <= line.length(); j++){
            if(j < line.length() && isdigit(line[j])){
                numdigits += 1;
            }
            else{
                if(numdigits > 0){
                    // now check for symbols
                    int k = j - numdigits -1; //todo seg fault
                    k = __max(k,0);
                    // check left
                    if(isSymbol(lines[i][k])){numsymbols += 1;};
                    for(;k <= j && k < line.length(); k++){
                        // check above
                        if(i-1 < lines.size() && isSymbol(lines[i-1][k])){numsymbols += 1;};
                        // check below
                        if(i+1 < lines.size() && isSymbol(lines[i+1][k])){numsymbols += 1;};
                    }
                    // check right
                    if(j<line.length()){
                        if(isSymbol(lines[i][j])){numsymbols += 1;};
                    }
                    if(numsymbols > 0){
                        const char* l = line.c_str() + j-numdigits;
                        int k;
                        _snscanf(l, numdigits, "%i", &k);
                        total += k;
                    }
                }
                numsymbols = 0;
                numdigits = 0;}
        }
    }

    printf("%i", total);

    return 0;
}