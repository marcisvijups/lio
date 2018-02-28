#include <iostream>
#include <algorithm>    // std::min
#include <fstream>		// file i/o

using namespace std;

int main()
{
    long int n, r , k;

    ifstream infile;
    infile.open("kristali.dat");
    infile >> n;
	infile.close();


    r = 0;
    k = 0;

    int rez =  6666;

	for(int i = 0 ; i < 101; i++)
	{
		for (int j = 0 ; j < 101; j++)
		{
			if(i * j >= n)
			{
				if(i + j < rez)
				{
					rez = i + j;
					r = min(i, j);
					k = max(i, j);
				}
			}
		}
	}


	ofstream outfile;
    outfile.open("kristali.rez");


	outfile << r << " "<< k ;
	outfile.close();
}
