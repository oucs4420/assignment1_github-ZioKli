#include <fstream>
#include <iostream>
using namespace std;

// output format to use IDENTICALLY:
// BSH:Saru> ./filesize input.3lines input.1line
// program: ./filesize
// input.3lines: 3
// input.1line: 1

int count_lines(string file_name) {
    int count = 0;
    ifstream ifs;
    string _dump;
    ifs.open(file_name);
    if (ifs.is_open()) {
        while (getline(ifs, _dump)) {
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    // just to get you started, this is how to refer to the arguments that were
    // passed
    for (int arg = 1; arg < argc; ++arg) {
        cout << argv[arg] << ": " << count_lines(argv[arg]) << endl;
    }
    exit(0); // this means that the program executed correctly!
}
