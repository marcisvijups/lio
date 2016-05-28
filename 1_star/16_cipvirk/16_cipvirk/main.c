#include <stdio.h>
#include <stdlib.h>

int cipvirkn(int a1, int a2, int n)
{
    if (n == 1)
        return a1;
    if (n == 2)
        return a2;
    int i,a3;
    for (i = 2; i < n; i++)
    {
        a3 = (a1 + a2)%10;
        a1 = a2;
        a2 = a3;
    }
    return a3;
}
int main()
{
    FILE *inFile = fopen("cipvirk.in","r+");
    int a1,a2,n;
    fscanf(inFile,"%d %d %d",&a1,&a2,&n);
    fclose(inFile);
    inFile = fopen("cipvirk.out","w+");
    fprintf(inFile,"%d",cipvirkn(a1,a2,n));
    fclose(inFile);
    return 0;
}
