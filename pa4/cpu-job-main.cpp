#include "cpu-job.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<CPU_Job> vec;
    string filename = "InputFiles/SetSize10.txt";

    cout << "Reading SetSize10.txt" << endl;
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "Error opening " << filename << endl;
        return 0;
    }
    
    CPU_Job job;
    while (ifs >> job) {
        vec.push_back(job);
    }

    cout << "Outputting jobs" << endl;
    for (auto x : vec) {
        cout << x << endl;
    }
}