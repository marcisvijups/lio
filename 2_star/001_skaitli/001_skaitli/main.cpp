#include <iostream>
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
using namespace std;

int main()
{
	FILE* infile = fopen("skaitli.in", "r+");
	int32_t a, b, a2b, ab2;
	fscanf(infile, "%d %d %d %d\n", &a, &b, &a2b, &ab2);
	fclose(infile);

	FILE* outfile = fopen("skaitli.out", "w+");

	bool aset = false;
	bool bset = false;
	bool cset = false;
	bool dset = false;


	if (a==0)
		a = -1000;
	else
		aset = true;
	if(b==0)
		b = -1000;
	else
		bset = true;
	if(a2b)
		cset = true;
	if(ab2)
		dset = true;


	// laika optimizaacija
	if(bset && !aset)
		a = b-1;


	while(!(aset && bset && cset && dset))
	{
		if(!aset)
			a++;
		if (a == 0)
			continue;

		if(!bset)
		{
			for(b = -999; b <= a; b++)
			{
				if ( b == 0)
					continue;
				if(cset)
				{
					// b not know but c know
					if((a * a * b) == a2b)
					{
						if(dset)
						{ // b not known but c and d is
							if (a * b * b == ab2)
							{
								aset = true;
								bset = true;
								a2b = a * a * b;
								break;
							}
						}
						else
						{
						// b and d not known but c is
							bset = true;
							aset = true;
							dset = true;
							ab2 = a * b * b;
							break;
						}
					}
					else
					{
						continue;
					}
				}
				else
				{
					// c unkown
					if(dset)
					{
						if(a * b * b == ab2)
						{

							aset = true;
							bset = true;
							cset = true;
							a2b = a * a * b;
							break;
						}
						else
						{
							continue;
						}
					}
					else
					{
						// b, c and d variable unkown
						a2b = a * a * b;
						ab2 = a * b * b;
						aset = true;
						bset = true;
						cset = true;
						dset = true;
						break;
					}
				} // end else (c unkown)

			}// end for loop of b
		}
		else
		{
			// b known
			// is it smaller than a ?.... the same case is excluded in the for loop check
			if(a < b)
				continue;

			if(cset)
			{
				// b and c known
				if((a * a * b) == a2b)
				{
					if(dset)
					{ // b and c and d known
						if(a * b * b == ab2)
						{
							aset = true;
							break;
						}
						else
						{
							continue;
						}
					}
					else
					{
						// b and c known but d unknown
						aset = true;
						dset = true;
						ab2 = a * b * b;
						break;
					}
				}
				else
				{
					continue;
				}

			}
			else
			{
				// b known but c unknown
				if(dset)
				{
					//b and d known but c unknow
					if(a * b * b == ab2)
					{
						aset = true;
						cset = true;
						a2b = a * a * b;
						break;
					}
					else
					{
						continue;
					}

				}
				else
				{
					// b known but c and d unkown
					aset = true;
					cset = true;
					dset = true;
					a2b = a * a * b;
					ab2 = a * b * b;
					break;
				}
			}
		}

	}

	fprintf(outfile,"%d %d %d %d\n", a, b, a2b, ab2);
	fclose(outfile);

    return 0;
}
