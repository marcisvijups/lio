#include <iostream>
#include <inttypes.h>
#include <string.h>
#include <stdio.h>

using namespace std;

void decode_chess_input(uint8_t* x, uint8_t *y);
void draw_move_pattern(uint8_t mas[8][8], uint8_t x, uint8_t y, uint8_t moves);

int main()
{
    FILE* infile = fopen("sahs4.dat","r+");
    uint8_t x ,y;
	fscanf(infile, "%c%c",&x,&y);
	fclose(infile);

	uint8_t mas[8][8];
	// saliek visur zvaigzniites saakumaa
	memset(&mas[0][0], '*', sizeof(mas));
	// salabo ievadi
	decode_chess_input(&x, &y);

	// funkcija kas sadrukaas gaajienus rekursiivi sākot no padotās pozīcijas
	draw_move_pattern(mas, x, y, 0);

    FILE* outfile = fopen("sahs4.rez", "w+");
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
void draw_move_pattern(uint8_t mas[8][8], uint8_t x, uint8_t y, uint8_t moves)
{
	if(mas[y][x] > moves)
	{
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


	// pa kreisi taisni - 1 gājienu
	xx = x;
	yy = y;
	if(x > 0)
	{
		xx--;
		draw_move_pattern(mas, xx, yy, moves);
	}



	// pa labi taisni - 1 gājienu
	xx = x;
	yy = y;
	if (x < 7)
	{
		xx++;
		draw_move_pattern(mas, xx, yy, moves);
	}


	// uz augšu taisni - 1 gājienu
	xx = x;
	yy = y;
	if (y > 0)
	{
		yy--;
		draw_move_pattern(mas, xx, yy, moves);
	}

	// uz leju taisni - 1 gājienu
	xx = x;
	yy = y;
	if (y < 7)
	{
		yy++;
		draw_move_pattern(mas, xx, yy, moves);
	}


	// pa kreisi un uz augšu - 1 gājienu
	xx = x;
	yy = y;
	if (x > 0 && y > 0)
	{
		xx--;
		yy--;
		draw_move_pattern(mas, xx, yy, moves);
	}


	// pa kreisi un uz leju - 1 gājienu
	xx = x;
	yy = y;
	if (x > 0 && y < 7)
	{
		xx--;
		yy++;
		draw_move_pattern(mas, xx, yy, moves);
	}


	// pa labi un uz augšu - 1 gājienu
	xx = x;
	yy = y;
	if (x < 7 && y > 0)
	{
		xx++;
		yy--;
		draw_move_pattern(mas, xx, yy, moves);
	}

	// pa labi un uz leju - 1  gājienu
	xx = x;
	yy = y;
	if (x < 7 && y < 7)
	{
		xx++;
		yy++;
		draw_move_pattern(mas, xx, yy, moves);
	}


}
