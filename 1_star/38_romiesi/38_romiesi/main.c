#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h> // strlen

int main(int argc, char** argv)
{
    FILE *infile = fopen("romiesi.dat","r+");
    char inputbuf[20] = {0};
    fscanf(infile, "%s", &inputbuf[0]);
    fclose(infile);
    uint32_t length = strlen(inputbuf);

    uint32_t sum =0;
    uint32_t curr_val = 0; // current value of roman digit
    uint32_t prev_val = 0; // previous digits value
    int32_t i = length-1;



    //we are going from the end to start of the number

    while(i >= 0)
    {

        switch (inputbuf[i])
        {
            case 'I':
                curr_val = 1;
                break;

            case 'V':
                curr_val = 5;
                break;

            case 'X':
                curr_val = 10;
                break;

            case 'L':
                curr_val = 50;
                break;

            case 'C':
                curr_val = 100;
                break;

            case 'D':
                curr_val = 500;
                break;

            case 'M':
                curr_val = 1000;
                break;
        }
        if(curr_val >= prev_val)
        {
            // "current" (i-th) array digit is smaller or same as previous
            sum += curr_val;
            prev_val = curr_val;
        }
        else
        {
            // next number is bigger
            sum -= curr_val;
        }
        curr_val = 0;
        --i;
    } // end of while

    FILE* outFile = fopen("romiesi.rez", "w+");
    fprintf(outFile, "%d\n", sum);
    return 0;
}
