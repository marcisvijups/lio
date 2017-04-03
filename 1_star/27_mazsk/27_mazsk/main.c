#include <stdio.h>
#include <stdlib.h>


struct bin_tree
{
    long int data;
    struct bin_tree *right, *left;
};
typedef struct bin_tree node;


int main()
{
    FILE *infile = fopen("pirmreiz.dat", "r+");
    long int n;
    fscanf(infile, "%ld", &n);
    fclose(infile);

    node* tree = malloc(sizeof(tree));
    // pieglabâjam sakni
    node* root = tree;
    tree->data = n;
    do
    {
        n = tree->data--;
        if (tree->data % n == 0)
        {
            tree->
        }

    }while(tree->data > 1);


    FILE *outfile = fopen("pirmreiz.rez", "w+");
    fprintf(outfile, "%ld\n", n);
    fclose(outfile);
    return 0;
}
