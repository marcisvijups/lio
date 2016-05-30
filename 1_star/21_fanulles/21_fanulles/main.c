#include <stdio.h>
#include <stdlib.h>
int faNull(int n)
{
    int k = 5;
    int x = 0;
    while(k <= n)
    {
        x = x + (n/k);
        k = k * 5;
    }
    return x;
}
// The algorithm that solves the mathematical problem taken from here :
// http://stackoverflow.com/questions/23977727/the-number-of-trailing-zeros-in-a-factorial-of-a-given-number-ruby
// My math is a bit rusty :)
int main()
{
    FILE *inFile = fopen("fanulles.in","r+");
    int n;
    fscanf(inFile,"%d\n",&n);
    fclose(inFile);

    FILE *outFile = fopen("fanulles.out","w+");
        fprintf(outFile,"%d",faNull(n));
    fclose(outFile);
    return 0;
}
