#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
using namespace std;

/* parse seed to soil
then parse soild to fertiliser
then parse fert to water
then parse water to light
then parse light to temp
then parse temp to humid
then parse humid to location
*/

struct Range;
struct SeedMap;
long long getLocationFromSeed(long long seed, SeedMap& sm);

struct Range{
    //what the fuck is happening
    long long minsourceval, maxsourceval, mindestval;
    Range(){}
};

struct SeedMap{
    vector<Range> maps[7];
};

long long getLocationFromSeed(long long seed, SeedMap& sm){
    for(size_t i = 0; i < sizeof(sm.maps)/sizeof(*sm.maps); i++){
        //if element in map then do the map
        for(auto r:sm.maps[i]){
            if(seed >= r.minsourceval && seed < r.maxsourceval){
                seed = seed - r.minsourceval + r.mindestval;
                break;
            }
        }
        //otherwise dont change seed
    }
    return seed;
}



int main(){
    ifstream myfile;
    myfile.open("input.txt");
    string line;

    int current_case = 0;
    SeedMap sm;

    bool seedsGrabbed = false;
    vector<long long> seeds;

    while(getline(myfile, line)){
        stringstream lineSS(line);

        if(!seedsGrabbed){
            //seeds
            string junk;
            lineSS >> junk;
            long long seedid;
            while(lineSS >> seedid){
                seeds.push_back(seedid);
            }
            seedsGrabbed = true;
            continue;
        }

        if(line.find(':') != -1){
            //move onto next section
            current_case += 1;
            continue;
        }
        //destination range start, source range start, range length
        // get the 3 numbers:
        if(line == "")continue;
        long long nums[3];
        lineSS >> nums[0] >> nums[1] >> nums[2];
        Range r;
        r.minsourceval = nums[1];
        r.maxsourceval = nums[1] + nums[2];
        r.mindestval = nums[0];
        sm.maps[current_case-1].push_back(r);
        // check if num in map, if not include num to num?
        // actually do that in the find function you fucking idtio
    }
    long long location;
    long long smallestlocation = LONG_LONG_MAX;
    for(auto seed : seeds){
        location = getLocationFromSeed(seed, sm);
        if(location<smallestlocation)
            smallestlocation = location;
    }
    printf("%i", smallestlocation);
    return 0;
}