#include <stdio.h>
#include <stdlib.h>

int main()
{
    // uzdevumâ dotie limiti liek  pielietot mainiigos ar izmeeru 8 baiti
    long long sk1, sk2, sk3, sum1, sum2, sum3;
    FILE *f = fopen("trissk.dat", "r+");
    fscanf(f, "%lld %lld %lld", &sk1 ,&sk2, &sk3);
    fclose(f);


    sum1 = sk1 + sk2;
    sum2 = sk1 + sk3;
    sum3 = sk2 + sk3;

    char *answer1, *answer2, * answer3;

    answer1 = (sum1 > 0 || sum2 > 0 || sum3 > 0) ? "VAR" : "NEVAR";
    answer2 = (sum1 == 0 || sum2 == 0 || sum3 == 0) ? "VAR" : "NEVAR";
    answer3 = (sum1 < 0 || sum2 < 0 || sum3 < 0) ? "VAR" : "NEVAR";

    f = fopen("trissk.rez", "w+");
    fprintf(f, "%s\n%s\n%s", answer1, answer2, answer3);
    fclose(f);
    return 0;
}
