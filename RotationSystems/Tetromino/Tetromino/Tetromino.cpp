#include <iostream>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

void idzdoxy(int x, int y) {
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);
}
int main()
{
    float  s[4][4] = { {0,0,0,0},
                       {0,0,0,0},
                       {1,1,1,1},
                       {0,0,0,0} };
    float temp[4][4] = { {0} };
    int x = 1;
    int y = 1;
    int k1 = 0;
    int  pivot_y = 2;
    int  pivot_x = 1;
    int   new_x;
    int  new_y;
    for (;;)
    {
        idzdoxy(0, 0);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                temp[i][j] = 0;
            }
        }
        cout << "Current Piece " << endl;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (s[i][j] > 0)
                {
                    //first way
                    //x = i-pivot_y;
                    //y = j-pivot_x;
                    //temp[pivot_y+y][pivot_x-x]=1;
                    //Second way
                    int ry = i - pivot_y; // i is my current y position
                    int rx = j - pivot_x; // j is my current x position
                    int bigrx = (-1 * ry)+(0 * rx); // -sin 90 and cos90
                    int bigry = (0 * ry)+(1 * rx); //cos 90 and -sin90
                   //int bigry = 0*(ry)+(1)*rx; //cos 90 and sin90
                   //int bigrx = -1*(ry)+0*(rx); // -sin 90 and cos90
                    int new_x = pivot_x + bigrx;
                    int new_y = pivot_y + bigry;
                    cout << new_y << "ry"; //-1
                    cout << new_x << "rx " << endl; //0
                    temp[new_y][new_x] = 1;

                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                {
                    cout << temp[i][j];
                    cout << " ";

                }
            }
            cout << endl;
        }
        cout << endl << endl;

        if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && (k1 == 0))
        {
            k1 = 1;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    s[i][j] = 0;

                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    s[i][j] = temp[i][j];

                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << s[i][j];
                cout << " ";
            }
            cout << endl;
        }
        if (GetAsyncKeyState(VK_SPACE) == 0) k1 = 0;
    }
    return 0;
}
