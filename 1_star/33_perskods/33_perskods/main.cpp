#include <iostream>

using namespace std;

int main()
{
    FILE *f = fopen("perskods.dat","r+");
    char mas[255];
    fscanf(f,"%s",mas);
    fclose(f);

    char answ[11] = {'J', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'Z'};

    uint32_t answ_index = ((mas[0]-'0') * 2 + (mas[1]-'0') * 7 +
        (mas[2]-'0') * 6 + (mas[3]-'0') * 5 + (mas[4]-'0') * 4 +
        (mas[5]-'0') * 3 + (mas[6]-'0') * 2 ) % 11;

    f = fopen("perskods.rez", "w+");
    fprintf(f,"%c\n",answ[answ_index]);
    fclose(f);

    return 0;
}
