#include <iostream>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>

using namespace std;

void decode_chess_input(uint8_t* x, uint8_t *y);
void draw_move_pattern(uint8_t mas[8][8], uint8_t x, uint8_t y, uint8_t moves, uint8_t avoidx, uint8_t avoidy);

int main()
{
    FILE* infile = fopen("sahs6.dat","r+");
    uint8_t x ,y;
    uint8_t x2, y2;
	fscanf(infile, "%c%c\n",&x,&y);
	fscanf(infile, "%c%c\n",&x2,&y2);
	fclose(infile);

	uint8_t mas[8][8];
	// saliek visur zvaigzniites saakumaa
	memset(&mas[0][0], '*', sizeof(mas));
	// salabo ievadi
	decode_chess_input(&x, &y);
	decode_chess_input(&x2, &y2);

	// funkcija kas sadrukaas gaajienus rekursiivi sākot no padotās pozīcijas
	draw_move_pattern(mas, x, y, 0, x2, y2);

    FILE* outfile = fopen("sahs6.rez", "w+");
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			if(mas[i][j] != '*')
			{
				fprintf(outfile,"%d",mas[i][j]);
			}
			else
			{
				fprintf(outfile,"%c",mas[i][j]);
			}
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

/*
 * @brief: 				uzzīmē figūras gājienu patternu izmantokjot rekursīvu funkcijas izsaukšanu
   @param [out]	mas	    2d masīvs oriģināli aizpildīts ar zvaigzītēm
   @param [in]  x 		sākotnējā x koordināta(horizontāli [0 kreisaa mala -> 7 labaa mala]) no kuras sāk zīmēt
   @param [in]  y 		sākotnējā y kootdināta(vertikāli 0 [0 augšējā rinda -> 7 pēdējā rinda) no kuras sāk zīmēt
   @param [in] moves    vērtība kas nosaka cik gājienos ir nokļūts sākotnējajā pozīcijā
*/
void draw_move_pattern(uint8_t mas[8][8], uint8_t x, uint8_t y, uint8_t moves, uint8_t avoidx, uint8_t avoidy)
{
	if(mas[y][x] > moves)
	{
		if(x == avoidx && y == avoidy)
			return;
		else
			mas[y][x] = moves;
		// no šī lauciņa ejot tālāk būs jāizdara vēlviens gājiens
		moves++;
	}
	else
	{
		// ja jau šeit var nonākt ar mazāk gājieniem nav jēgas no šī lauciņa tālāk nekur iet
		return;
	}

	// rekursīvi iet :
	int xx, yy;


	// pa kreisi taisni
	xx = x;
	yy = y;
	while(xx > 0)
	{
		xx--;
		if(xx == avoidx && yy == avoidy)
			break;
		draw_move_pattern(mas, xx, yy, moves, avoidx, avoidy);
	}

	// pa labi taisni
	xx = x;
	yy = y;
	while(xx < 7)
	{
		xx++;
		if(xx == avoidx && yy == avoidy)
			break;
		draw_move_pattern(mas, xx, yy, moves, avoidx, avoidy);
	}

	// uz augšu taisni
	xx = x;
	yy = y;
	while(yy > 0)
	{
		yy--;
		if(xx == avoidx && yy == avoidy)
			break;
		draw_move_pattern(mas, xx, yy, moves, avoidx, avoidy);
	}

	// uz leju taisni
	xx = x;
	yy = y;
	while(yy < 7)
	{
		yy++;
		if(xx == avoidx && yy == avoidy)
			break;
		draw_move_pattern(mas, xx, yy, moves, avoidx, avoidy);
	}
}
