/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 18, 2016, 12:36 PM
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * f;
    f = fopen("burti.in","r+");
    char v1[250], v2[250];
    fgets(v1,250,f);
    fgets(v2,250,f);
    fclose(f);
    int var = 1;
    int i = 0;
    while (v2[i] != '\0')
    {

        int j =0;
        if (!var)
        {
            break;
        }

        var = 0;
        while (v1[j] != '\0')
        {
            if (v1[j]==v2[i])
            {
                v1[j] = '!';
                var = 1;
                break;

            }
        j++;
        }
    i++;
    }
    f = fopen("burti.out","w+");
    if(var)
        fprintf(f,"VAR");
    else
        fprintf(f,"NEVAR");
    fclose(f);
    return 0;
}
