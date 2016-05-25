/* 
 * File:   main.c
 * Author: marcis.vijups
 *
 * Created on May 25, 2016, 4:08 PM
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) 
{
    FILE *file = fopen("diena.in","r+");
    int day;
    fscanf(file,"%d",&day);
    fclose(file);
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = 0;
    while (day > months[i])
    {
        day-=months[i];
        i++;
    }
    file = fopen("diena.out","w+");
    fprintf(file,"%d %d",day,i+1);
    fclose(file);
    return (EXIT_SUCCESS);
}

