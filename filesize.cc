#include <fstream>
#include <iostream>
using namespace std;

// output format to use IDENTICALLY:
// BSH:Saru> ./filesize input.3lines input.1line
// program: ./filesize
// input.3lines: 3
// input.1line: 1

int count_lines(string file_name) {
    int count = 0; // count starts at 0 so if there IS a file but it's empty we report 0 lines
    ifstream ifs;
    string _dump; // we don't look at the strings we pull in
    ifs.open(file_name);
    if (ifs.is_open()) {
        /// getline gets to a new line or an EOF so it can handle a file that doesn't end in \n
        while (getline(ifs, _dump)) {
            count++;
        }
    } 
    // if the file doesn't open we return -1 to indicate an error
    else {
        return -1;
    }
    ifs.close(); // close the file so its safe for another process or user to open
    return count;
}

int main(int argc, char *argv[]) {
    // just to get you started, this is how to refer to the arguments that were
    // passed
    cout << "program: " << argv[0] << endl;
    for (int arg = 1; arg < argc; ++arg) {
        cout << " " << argv[arg] << ": " << count_lines(argv[arg]) << endl;
    }
    exit(0); // this means that the program executed correctly!
}
