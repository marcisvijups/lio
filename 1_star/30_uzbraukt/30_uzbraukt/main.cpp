#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("uzbraukt.dat");
	unsigned long long int n, posms, ieprPosms, pirmais_posms;
	bool augsh = false; bool lejup = false; bool lim = false;
	unsigned long long augPos = 0;
	unsigned long long limPos = 0;
	unsigned long long lejPos = 0;

	infile >> n;
	infile >> ieprPosms;
	pirmais_posms = ieprPosms;
	for (unsigned long long  i = 1; i <= n ; i++ )
	{
		if (n != i)
			infile >> posms;
		else
			posms = pirmais_posms;

		// ja jaunais posms lielaaks pa iepreiksheejo - taatad iet uz augshu
		if(posms > ieprPosms)
		{
			if(augsh == true)
			{
				// turpina ripinaat ratinkreeslu uz augshu...
			}
			else
			{
				lim = false;
				lejup  = false;
				augsh = true;
				augPos++;
			}
		}

		// kaapj lejaa
		else if(posms < ieprPosms)
		{
			if(lejup == true)
			{
				// turpina ripot lejaa...
			}
			else
			{
				lim = false;
				lejup  = true;
				augsh = false;
				lejPos++;
			}
		}

		// iet taisni( lidzeni)
		else
		{
			if (true == lim)
			{

			}
			else
			{
				lim = true;
				lejup = false;
				augsh = false;
				limPos++;
			}
		}

		ieprPosms = posms;

	}



	infile.close();

	ofstream outfile;
	outfile.open("uzbraukt.rez");
	outfile <<  augPos << " " << lejPos << " " << limPos<<endl;
	outfile.close();

    return 0;
}
