/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 18, 2016, 2:24 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f =fopen("desas.in","r+");
    //read
    int mas[3][3] = { 0 };
    char protocol[255] = {0};
    int len = 0;
    int i , j , x,simboli;
    char c ;
    fscanf(f,"%s",&protocol);
    fclose(f);
    int win1 = 0;
    int win2 = 0;
    for (i = 0; i < 3 ; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mas[i][j]=0;
            //printf("%d ",mas[i][j]);
        }
        //printf("\n");
    }


    simboli = 0;

    len = strlen(protocol);


    f = fopen("desas.out","w+");
    //vai garums nepaarsniedz atlauto ?
    if(len>9)
        fprintf(f,"NEKOREKTS");
    else
    {
    //vai atkaartojas simboli vai arii ir nekorekti ?
        for (i = 0; i < len-1 ; i++)
        {
            c = protocol[i];
            for(j = i+1 ; j < len ; j ++)
            {
                if (
                    (protocol[j] == c)    ||
                    (protocol[j] - 48 > 9)||
                    (protocol[j] - 48 < 1)
                    )

                {
                    simboli =1;
                    break;
                }
            }
        }
        if(simboli)
            fprintf(f,"NEKOREKTS");

        else
        {

            //savada veertiibas 2d masiivaa
            i = j =0;
            int x = 0;
            int y = 0;
            int turn = -1;
            for(i = 0 ; i < len ; i++)
            {
                y = ((protocol[i]-48)-1)/3;
                x = ((protocol[i]-48)-1)%3;
                if(!mas[y][x])
                    mas[y][x] = turn;
                else
                {
                    fprintf(f,"NEKOREKTS");
                    simboli =1 ;
                    break;
                }
                turn=turn * (-1);

            }

            if(! simboli)
            {


                //paarbaudiit vai kaads uzvareeja

                int sum1 , sum2 , dia1, dia2;
                for (i = 0; i < 3 ; i++)
                {
                    sum1 = 0;
                    sum2 = 0;
                    for (j = 0; j < 3; j++)
                    {
                        sum1  += mas[i][j];
                        sum2  += mas[j][i];
                    }
                    if (sum1 == -3 || sum2 == -3)
                        win1 ++;
                    if (sum1 == 3 || sum2 == 3)
                        win2 ++;

                }
                dia1 = dia2 = 0;
                dia1 =( mas[0][0] + mas[1][1] + mas[2][2]);
                dia2 = (mas[0][2]+mas[1][1]+ mas[2][0]);

                if(dia1 == -3 || dia2 == -3)
                    win1 ++;
                if (dia1 == 3 || dia2 == 3)
                    win2 ++;

                if((len < 9 && !win1 && ! win2 ) || win1>2 || win2 >2)
                    fprintf(f,"NEKOREKTS");
                else
                {
                    if(len == 9 && !win1 && !win2)
                        fprintf(f,"NEVIENS");
                    else
                    {
                        if(len == 9 && win1 && win2)
                            fprintf(f,"NEKOREKTS");
                        else
                        {
                            if (win1 && win2)
                                fprintf(f,"NEKOREKTS");
                            else
                            {
                                if(win1)
                                    fprintf(f,"PIRMAIS");
                                else
                                    if(win2)
                                        fprintf(f,"OTRAIS");
                            }
                        }
                    }

                }

            }


        }
    }

    fclose(f);
    return 0;
}
