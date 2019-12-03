#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <inttypes.h>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("cipvirk3.dat");
    uint64_t n = 0;
    infile >> n;
    infile.close();

    // these could be calculated "on the fly" - time vs  space trade-off
    uint64_t answ[10] = {0, 9, 180, 2700, 36000, 450000, 5400000, 63000000, 720000000};
    ostringstream convert;
    convert << n;
    string str = convert.str();
    int len  = str.length();

    uint64_t result = 0;

    for (int i = 0 ; i < len; i++)
    {
        result+=answ[i];
    }

    uint64_t sub = 0;
    for (int i = 0 ; i < len-1; i++)
    {
        sub = sub * 10 + 9;
    }
    result = result + ((n-sub)*len);


    ofstream outfile;
    outfile.open("cipvirk3.rez");
    outfile << result << "\n";
    outfile.close();
    return 0;
}
