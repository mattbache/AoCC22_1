//
//  main.cpp
//  AoC22_1
//
//  Created by Matthew Bache on 12/1/22.
//

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char * argv[]) {
    fstream inputFile;
    inputFile.open("/Users/matthewbache/Documents/AoC22/AoCC22_1/AoC22_1 Input.txt");
    if (!inputFile.is_open()) {
        cout << "Could not open file\n";
        return 1;
    }
    string line;
    long current = 0, max = 0;
    long topThree[3] = {0,0,0};
    int len = sizeof(topThree)/sizeof(topThree[0]);
    
    while (getline(inputFile, line)) {
        if (line.length() == 0) {
            if (current > max) {
                max = current;
            }
            // is current in top three? add it, resort top three
            if (current > topThree[0]) {
                topThree[0] = current;
                sort(topThree, topThree+len);
            }
            current = 0;
        }
        else {
            current += atoi(line.c_str());
        }
    }
    cout << "max: " << max << "\n";
    cout << "Top Three:";
    for(int i=0; i<len; i++) {
        cout << " " << topThree[i];
    }
    cout << "\nAnd top three total: " << topThree[0]+topThree[1]+topThree[2] << "\n";
    
    inputFile.close();
    return 0;
}
