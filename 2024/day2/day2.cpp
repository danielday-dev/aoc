#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool between1and3(int num1, int num2);

int main(){
    ifstream myfile;
    myfile.open("input.txt");
    int total = 0;

    string current_string;
    while(getline(myfile, current_string)){
        // get data

        vector<int> current_report;
        stringstream s(current_string);
        int level;
        while(s >> level){
            current_report.push_back(level);
        }

        // process data
        bool increasing_flag;
        increasing_flag = current_report[0] < current_report[1];
        bool report_unsafe = false;
        for(size_t i=1; i < current_report.size(); i++){
            if(increasing_flag){
                if(!(between1and3(current_report[i-1], current_report[i]) && current_report[i-1] < current_report[i])){
                    report_unsafe = true;
                    break;
                }
            }
            else{
                if(!(between1and3(current_report[i-1], current_report[i]) && current_report[i-1] > current_report[i])){
                    report_unsafe = true;
                    break;
                }
            }
        }
        if(!report_unsafe){
            total++;
        }
    }
    printf("%i", total);
}
bool between1and3(int num1, int num2){
    int difference;
    difference = abs(num1 - num2);
    if(difference > 3 || difference < 1){
        return false;
    }
    return true;
};