/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 18, 2016, 2:18 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int printLen (int value){
  int l=!value;
  while(value){ l++; value/=10; }
  return l;
}

/*
Function for calculating power of a number
@in     n - base of the number
@in     x - power that you wish to calculate
@out    returns the result of n^x as an integer value
*/
int power(int n, int x)
{
    if (x == 0)
        return 1;
    int i =0;
    int rez = n;
    for (i = 1 ; i < x; i++)
        rez *=n;

    return rez;
}


int getInt(int mas[250],int x1 ,int x2)
{
    //logic
    int i = 0;
    int rez = 0;
    int n = 0;
    for(i = x2-1 ; i >= x1; i--)
    {

        rez = rez+ (mas[i]*(power(10,n)));
        n++;

    }

    return rez;
}


int main()
{
    FILE* f = fopen("atlikums.in","r+");
    char sk1[250] = {0};
    char csk2[10] = {0};
    int sk22[10] = {0};
    fscanf(f,"%s\n%s\n",&sk1[0],&csk2[0]);
    fclose(f);

    int len1 = strlen(sk1);
    int len2 = strlen(csk2);
    int tmp2;

    int i,j,sk2 = 0;
    for(j = 0; j<len2;j++)
    {
        sk22[j]=csk2[j]-48;
    }
    sk2 = getInt(sk22,0,len2);

    int mas[250] = {0};

    for (i = 0; i < len1 ; i++)
        mas[i]=sk1[i]-48;

    f = fopen("atlikums.out","w+");

    int pos1 = 0;
    int pos2 = 0;
    int tmpValue = 0;
    int starp = 0;
    int gar = 0;
    int powerint = 0;
    if (len2>=len1)
    {
        //just write sk1 to file and end
        fprintf(f,"%d",(getInt(mas,0,len1))%sk2);
    }
    else
    {
        //stuff


        //printf("Get int value: %d",getInt(mas,0,5,0));
        while(len2 <= len1-pos1 && pos2 <= len1)
        {
            tmpValue = getInt(mas,pos1,pos2);
            while(tmpValue < sk2 && pos2 <= len1)
            {
                pos2++;
                if (pos2 <= len1)
                    tmpValue = getInt(mas,pos1,pos2);
                else break;

            }

            tmpValue = tmpValue % sk2;
            tmp2 = tmpValue;
            gar = printLen(tmpValue);
            starp = pos2 - pos1;
            for (i = pos1 ; i < pos2; i++)
                mas[i] = 0;
            powerint = 0;
            pos1 += (starp - gar);
            for (i = pos1; i < pos2; i++)
            {

                mas[i] = tmpValue/(power(10,gar - powerint-1));
                tmpValue %= (power(10,gar - powerint-1));
                powerint++;
            }





        }
    fprintf(f,"%d",tmp2);
    }






    fclose(f);
    return 0;
}
