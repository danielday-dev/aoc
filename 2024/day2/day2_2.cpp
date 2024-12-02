#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool between1and3(int num1, int num2);
bool isReportValid(vector<int> report);

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

        if(isReportValid(current_report)){
            total++;
        }else{
            for(size_t i = 0; i < current_report.size(); i++){
                vector<int> temp = current_report;
                temp.erase(temp.begin() + i);
                if(isReportValid(temp)){
                    total++;
                    break;
                }
            }
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

bool isReportValid(vector<int> report){
    bool increasing_flag = report[0] < report[1];
    bool report_unsafe = false;
    for(size_t i=1; i < report.size(); i++){
        if(!between1and3(report[i-1], report[i])){
            report_unsafe = true;
            break;
        }

        if(increasing_flag){
            if(!(report[i-1] < report[i])){
                report_unsafe = true;
                break;
            }
        }else{
            if(!(report[i-1] > report[i])){
                report_unsafe = true;
                break;
            }
        }
    }
    return !report_unsafe;
}