#include <iostream>
#include <fstream>


using namespace std;
int mas[200][200] = {{0}};

int check_win(int x, int y)
{
    if (mas[x][y] != 0)
    {
        // check next 4 values "to right" are the same as this one
        if( (mas[x][y] == mas[x][y+1]) &&
            (mas[x][y] == mas[x][y+2]) &&
            (mas[x][y] == mas[x][y+3]) &&
            (mas[x][y] == mas[x][y+4]))
        {
            if (mas[x][y] != mas[x][y+5] &&
                mas[x][y] != mas[x][y-1])
            {
                return mas[x][y];
            }
        }

        // check next 4 values "to left" are the same as this one
        if( (mas[x][y] == mas[x][y-1]) &&
            (mas[x][y] == mas[x][y-2]) &&
            (mas[x][y] == mas[x][y-3]) &&
            (mas[x][y] == mas[x][y-4]))
        {
            if (mas[x][y] != mas[x][y-5] &&
                mas[x][y] != mas[x][y+1])
            {
                return mas[x][y];
            }
        }

        // check next 4 values "below" are the same as this one
        if( (mas[x][y] == mas[x+1][y]) &&
            (mas[x][y] == mas[x+2][y]) &&
            (mas[x][y] == mas[x+3][y]) &&
            (mas[x][y] == mas[x+4][y]))
        {
            if (mas[x][y] != mas[x+5][y] &&
                mas[x][y] != mas[x-1][y])
            {
                return mas[x][y];
            }
        }

        // check next 4 values "Above" are the same as this one
        if( (mas[x][y] == mas[x-1][y]) &&
            (mas[x][y] == mas[x-2][y]) &&
            (mas[x][y] == mas[x-3][y]) &&
            (mas[x][y] == mas[x-4][y]))
        {
            if (mas[x][y] != mas[x-5][y] &&
                mas[x][y] != mas[x+1][y] )
            {
                return mas[x][y];
            }
        }

        // next 4 values to bottom right
        if( (mas[x][y] == mas[x+1][y+1]) &&
            (mas[x][y] == mas[x+2][y+2]) &&
            (mas[x][y] == mas[x+3][y+3]) &&
            (mas[x][y] == mas[x+4][y+4]))
        {
            if (mas[x][y] != mas[x+5][y+5] &&
                mas[x][y] != mas[x-1][y-1])
            {
                return mas[x][y];
            }
        }

        // next 4 values to bottom left
        if( (mas[x][y] == mas[x+1][y-1]) &&
            (mas[x][y] == mas[x+2][y-2]) &&
            (mas[x][y] == mas[x+3][y-3]) &&
            (mas[x][y] == mas[x+4][y-4]))
        {
            if (mas[x][y] != mas[x+5][y-5] &&
                mas[x][y] != mas[x-1][y+1])
            {
                return mas[x][y];
            }
        }


        // next 4 values to top left
        if( (mas[x][y] == mas[x-1][y-1]) &&
            (mas[x][y] == mas[x-2][y-2]) &&
            (mas[x][y] == mas[x-3][y-3]) &&
            (mas[x][y] == mas[x-4][y-4]))
        {
            if (mas[x][y] != mas[x-5][y-5] &&
                mas[x][y] != mas[x+1][y+1])
            {
                return mas[x][y];
            }
        }

        // next 4 values to top right
        if( (mas[x][y] == mas[x+1][y+1]) &&
            (mas[x][y] == mas[x+2][y+2]) &&
            (mas[x][y] == mas[x+3][y+3]) &&
            (mas[x][y] == mas[x+4][y+4]))
        {
            if (mas[x][y] != mas[x+5][y+5] &&
                mas[x][y] != mas[x-1][y-1])
            {
                return mas[x][y];
            }
        }


    }

    return 0;
}












int main()
{
    ifstream inFile;
    inFile.open("rendzju.dat");

    for(int i = 0; i < 19; i++)
    {
        for(int j = 0 ; j < 19; j++)
        {
            inFile >> mas[i+100][j+100];
        }

    }
    inFile.close();


    int result = 0;
    int win = 0;

    for(int i = 99; i < 120 && win == 0; i++)
    {
        for(int j = 99 ; j < 120 && win == 0; j++)
        {
            if (mas[i][j] != 0)
            {
                win = check_win(i,j);
            }

            if(win != 0)
            {
                result = win;
               // cout << "player "<< result  << " won [" << i-99 << " " << j-99<<"]\n";
            }

        }

    }

    ofstream outFile;
    outFile.open("rendzju.rez");
    outFile << result << endl;

    outFile.close();
    return 0;
}
