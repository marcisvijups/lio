#include <iostream>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>
using namespace std;

void decode_chess_input(uint8_t* x, uint8_t *y);

int main()
{
	FILE* infile = fopen("sahs1.dat","r+");
	uint8_t x ,y;
	fscanf(infile, "%c%c",&x,&y);
	fclose(infile);

	// tornis gandriiz visur ies 2 gaajienos
	uint8_t mas[8][8];
	memset(&mas[0][0], 2, sizeof(mas));

	// salabo ievadi
	decode_chess_input(&x, &y);


	//ievieto vieniniekus uz visaam četraam puseem:

	//pa uz augshu
	int yy = y;
	int xx = x;
	while(yy >= 0)
	{
		mas[yy][xx] = 1;
		yy--;
	}

	// pa kreisi
	yy = y;
	xx = x;
	while(xx >= 0)
	{
		mas[yy][xx] = 1;
		xx--;
	}

	// pa labi
	yy = y;
	xx = x;
	while(xx <= 7)
	{
		mas[yy][xx] = 1;
		xx++;
	}

	// uz leju
	yy = y;
	xx = x;
	while(yy <= 7)
	{
		mas[yy][xx] = 1;
		yy++;
	}

	// ievietojam sākuma koordinātu
	mas[y][x] = 0;

	FILE* outfile = fopen("sahs1.rez","w+");
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			fprintf(outfile,"%d",mas[i][j]);
		}
		fprintf(outfile, "\n");
	}
	fclose(outfile);
    return 0;
}
/*
 * @brief:			modificē ievaddatus no šaha coordinātēm
 * 					uz masīva indeksiem
 * @param [out] x 	pointers uz x koordinātu (a-h)
 * @param [out] y	pointeris uz y kooridnātu - (1-8)
*/
void decode_chess_input(uint8_t* x, uint8_t *y)
{
	*x = *x - 'a';
	*y = 8 - (*y - '0');
}
