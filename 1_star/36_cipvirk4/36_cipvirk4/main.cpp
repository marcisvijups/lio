#include <iostream>
#include <fstream>
#include <inttypes.h>
#include <string>
#include <sstream>


using namespace std;

int main()
{
    ifstream infile;
    infile.open("cipvirk4.dat");
    
    uint32_t input_num = 0;
    infile >> input_num;
    //cin >> input_num;
    infile.close();

    ostringstream convert;
    convert << input_num;
    string search_str = convert.str();
    string result_string = "";
    string temp_str;

    for (uint32_t i = 1 ; i  <= input_num; i++)
    {
        ostringstream new_convert;
        new_convert << i;
        temp_str = new_convert.str();
        //cout << "temp str is: " << temp_str << "\n";
        // append seems to have a far greater performance than plus operator!
        result_string = result_string.append(temp_str);
    }

    ofstream outfile;
    outfile.open("cipvirk4.rez");
    //outfile << "result_str : " << result_string << "\tsearch_str: " << search_str <<  endl;
    outfile << result_string.find(search_str)+1 << "\n";
    //cout << result_string.find(search_str)+1 << "\n";
    outfile.close();
}
