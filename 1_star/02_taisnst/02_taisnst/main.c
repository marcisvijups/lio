#include <stdio.h>
#include <stdlib.h>


int n,m;

void setNmax ()
{
    int c;
    if (m> n)
    {
        c = n;
        n = m;
        m = c;
    }
}

int main(void)
{
    FILE *f = fopen("taisnst.in","r+");

    fscanf(f,"%d %d", &n , &m);
    fclose (f);

    setNmax();
    int S = n * m ;
    int answer = 0;

    f = fopen("taisnst.out","w+");
    do
    {
        S = S - m*m;
        n = n -m;
        setNmax();
        answer++;

    }while(S);

    fprintf(f,"%d",answer);
 //   printf("%d",answer);

    fclose (f);
    return 0;
}
