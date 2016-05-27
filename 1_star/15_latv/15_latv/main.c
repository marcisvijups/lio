#include <stdio.h>
#include <stdlib.h>

int replaceTokens(char *a, char *b)
{
    if (*a == 'a' && *b == 'a')
    {
        *a = '*';
        *b = '*';
        return 1;
    }

    if (*a == 'e' && *b == 'e')
    {
        *a = '*';
        *b = '*';
        return 1;
    }

    if (*a == 'i' && *b == 'i')
    {
        *a = '*';
        *b = '*';
        return 1;
    }

    if (*a == 'u' && *b == 'u')
    {
        *a = '*';
        *b = '*';
        return 1;
    }

    if (*a == 'g' && *b == 'j')
    {
        *a = '*';
        *b = '*';
        return 1;
    }

    if (*a == 'l' && *b == 'j')
    {
        *a = '*';
        *b = '*';
        return 1;
    }

    if (*a == 'k' && *b == 'j')
    {
        *a = '*';
        *b = '*';
        return 1;
    }

    if (*a == 'n' && *b == 'j')
    {
        *a = '*';
        *b = '*';
        return 1;
    }

    if (*a == 'c' && *b == 'h')
    {
        *a = '*';
        *b = '*';
        return 1;
    }

    if (*a == 's' && *b == 'h')
    {
        *a = '*';
        *b = '*';
        return 1;
    }

    if (*a == 'z' && *b == 'h')
    {
        *a = '*';
        *b = '*';
        return 1;
    }
    return 0;
}

int main()
{
    FILE *inFile = fopen("latv.in","r+");
    char buf[255];
    fgets(buf,sizeof(buf),inFile);
    fclose(inFile);

    int i = 0;
    int replaced = 0;
    char *p = buf;
    for(i = 0; i < strlen(buf)-1;i++)
    {
        if(buf[i]==' ')
            replaced++;
        replaced = replaced + replaceTokens(p+i,p+i+1);

    }


    FILE *outFile = fopen("latv.out","w+");
    fprintf(outFile,"%d",strlen(buf)-replaced);
    fclose(outFile);

    return 0;
}
