#include <iostream>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <functional>
#include <chrono>
using namespace std;
void idzdoxy(int x, int y) {
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);
}
int  t[4][4] ={{0,0,0,0},
                {1,1,1,0},
                {0,1,0,0},
                {0,0,0,0}};

int  lc[4][4] ={{0,1,0,0},
                {0,1,0,0},
                {1,1,0,0},
                {0,0,0,0}};

int  l[4][4] ={{0,1,0,0},
                {0,1,0,0},
                {0,1,1,0},
                {0,0,0,0}};

int  st[4][4] ={{0,0,0,0},
                {0,1,1,0},
                {1,1,0,0},
                {0,0,0,0}};

int  sc[4][4] ={{0,0,0,0},
                {1,1,0,0},
                {0,1,1,0},
                {0,0,0,0}};

int  s[4][4] ={{0,0,0,0},
                {1,1,1,0},
                {0,1,0,0},
                {0,0,0,0}}; // its first element its some random figure

int  o[4][4] ={{0,0,0,0},
                {0,1,1,0},
                {0,1,1,0},
                {0,0,0,0}};

int d[4][4] ={{0,0,1,0},
               {0,0,1,0},
               {0,0,1,0},
               {0,0,1,0}};
int board[21][20];
int rotationid=4;
char piece =219;
int N=3;
char c = 196;
char c1 = 186;
int randomp;
int n=20;
int k1=0;
char kierunek = '0';
int x=5;
int y=0;
char colidechar='n';
int tetromino=0;
int rotation = 4;
char x205=205;
bool ablerotate =true;
int score =0;
int s1 =0;
void threading(int &y)
{
    Sleep(500);
    y++;
}
void clear_line(int &counter) {

	for (int j = 0; j < 20; j++) {
		int i = 0;
		while (i < 10) {
			if (board[j][i] == 0) {
				break;
			}
			else
            {
                i++;

            }
		}
		if (i == 10) {
			for (int k = j; k > 0; k--) {
				for (int m = 0; m < 10; m++) {
					board[k][m] = board[k - 1][m];
				}
			}
			counter =counter +1;
		}
	}

}
bool is_collide() {
	for (int  i = 0; i < rotationid; i++) {
		for (int  j = 0; j < rotationid; j++) {
			if (s[i][j] && board[y + i][x + j]==1)
            {
				return 1;
			}
		}
	}
	return 0;
}
bool is_collide_wall() {
	for (int  i = 0; i < rotationid; i++) {
		for (int  j = 0; j < rotationid; j++) {
			if (s[i][j] && board[y + i][x + j]==-1)
            {
				return 1;
			}
		}
	}
	return 0;
}
VOID CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{
    y=y+1;
  cout.flush();
}
int main()
{

        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                board[j][i]=0;
            }
        }
        for (int i=0; i<rotationid; i++)
        {

            for(int j=0; j<rotationid; j++)
            {
                board[y + i][x + j] =s[i][j];
            }
        }
	srand (time(NULL));
    int Counter=0;
    MSG Msg;

    UINT TimerId = SetTimer(NULL, 0, 2000, &TimerProc); //2000 milliseconds

   if (!TimerId)
    return 16;

    for(;;)
    {
        idzdoxy(0,0);
        Sleep(50);

            for (int i=0; i<=n; i++)
            {
            for(int j=-1; j<=20; j++)
                {
                    if(j==-1||j==10)
                    {
                        board[i][j]=-1; // colide wall
                    }
                    else if(i==20)
                    {
                        board[i][j]=1; //colide ground
                    }
                }
            }
            for(int i=0; i<20; i++)
            {
                for(int j=0; j<=10;j++)
                {
                    if(j==0 || j==10 )
                    {
                        cout <<c1;
                    }
                    if(board[i][j]>0)
                    {
                        cout <<piece;
                    }
                    else cout <<" ";
                }
                cout <<endl;
            }
            for(int i=0; i<=11; i++)
            {
                if(i==0)
                {
                    char dd=200;
                    cout <<dd;
                }
                else if(i==11)
                {
                    char dd=188; // dd and c1 are chars from ascii table for better " graphics "
                    cout <<dd;
                }
                else
                {
                   cout <<x205;

                }

            }


            for (int  i = 0; i < rotationid; i++)
            {
                for (int j = 0; j <rotationid; j++)
                {
                    board[y + i][x + j] -= s[i][j];
                }
            }
            if(GetAsyncKeyState(VK_DOWN))
            {
                kierunek='d';
            }
            if(GetAsyncKeyState(VK_LEFT))
            {
               kierunek='l';
            }
            if(GetAsyncKeyState(VK_RIGHT))
            {
                kierunek='p';

            }
                     if (!is_collide())
            {
                y=y+1;
            }

            if (!is_collide())
            {

            }
            if(kierunek=='d')
            {

            if (!is_collide())
            {
                y++;
            }

            }
            if( kierunek=='l')
            {
                if (!is_collide())
            {
                x=x-1;
            }
            }
            if(  kierunek=='p')
            {
                if (!is_collide())
            {
                x=x+1;
            }
            }

            if(GetAsyncKeyState(VK_UP)&& 0x8000 && (s1 == 0))
            {
                s1=1;
                kierunek ='g';
                for(;;)
                {
                    if(!is_collide())
                    {
                        y++;
                    }
                    else
                    {

                        break;
                    }
                }
            }
            if(GetAsyncKeyState(VK_UP) == 0) s1 = 0;
            if(is_collide_wall())
                {
                    ablerotate=false;
                    if(kierunek=='d')
                    {
                        y=y-1;
                    }
                    else if(kierunek=='p')
                    {
                        x=x-1;
                    }
                    else if(kierunek=='l')
                    {
                        x=x+1;
                    }
                }
            if(is_collide())
                {

                    ablerotate=false;
                    Sleep(30);
                    y= y-1;
                    if(kierunek=='p')
                    {
                        x=x-1;
                    }
                    else if(kierunek=='d')
                    {
                       // y=y+1;
                    }
                    else if(kierunek=='g')
                    {
                        y=y-2;
                    }
                    else if(kierunek=='l')
                    {
                        x=x+1;
                    }
                    for (int i = 0; i < rotationid; i++)
                    {

                        for (int  j = 0; j < rotationid; j++)
                        {
                            board[y + i][x + j] += s[i][j]; // add current piece to the board //s is a temp piece;
                        }
                    }
                    x=5; //reset coord x;
                    y =0; //reset coord y
                    N=3;
                    randomp =rand()%7+1;
                     cout <<randomp;
                    if(randomp==1)
                    {
                    for (int i=0; i<rotationid; i++)
                    {
                        piece =178;
                        for (int j=0; j<rotationid; j++)
                        {
                            s[i][j]=l[i][j];

                        }
                    }
                    }
                    else if(randomp ==2)
                    {
                    for (int i=0; i<rotationid; i++)
                    {
                        for (int j=0; j<rotationid; j++)
                        {
                            s[i][j]=t[i][j];

                        }
                    }
                    }
                    else if(randomp ==3)
                    {
                    for (int i=0; i<rotationid; i++)
                    {
                        for (int j=0; j<rotationid; j++)
                        {
                            s[i][j]=lc[i][j];

                        }
                    }
                    }

                    else if(randomp ==5)
                    {
                    for (int i=0; i<rotationid; i++)
                    {
                        for (int j=0; j<rotationid; j++)
                        {
                            s[i][j]=st[i][j];

                        }
                    }
                    }
                    else if(randomp ==6)
                    {
                    for (int i=0; i<rotationid; i++)
                    {
                        for (int j=0; j<4; j++)
                        {
                            s[i][j]=sc[i][j];

                        }
                    }
                    }
                    else if (randomp ==7)
                    {

                    for (int i=0; i<rotationid; i++)
                    {
                        for (int j=0; j<rotationid; j++)
                        {
                            N=0;
                            s[i][j]=o[i][j];

                        }
                    }
                    }
                    else if (randomp==4)
                    {
                    for (int i=0; i<rotationid; i++)
                    {
                        for (int j=0; j<rotationid; j++)
                        {
                            N=4;
                            s[i][j]=d[i][j];

                        }
                    }
                    }

            }
        cout<<endl<<"Amount of score "<<"|"<<score<<"|";
        kierunek = 'n';  // reset direction
        if(ablerotate==true)
        {
            if((GetAsyncKeyState(VK_SPACE) & 0x8000) && (k1 == 0))
            {
                k1=1;
                for (int i = 0; i < N / 2; i++)
                {
                    for (int j = i; j < N - i - 1; j++)
                    {
                        int temp = s[i][j];
                        s[i][j] = s[N -1- j][i];
                        s[N - 1 - j][i] =  s[N - 1 - i][N - 1 - j];
                        s[N - 1 - i][N - 1 - j] =  s[j][N - 1 - i];
                        s[j][N - 1 - i] = temp;
                    }
                }
            }
        }

        clear_line(score);
        ablerotate=true;
        if(GetAsyncKeyState(VK_SPACE) == 0) k1 = 0;

        for (int i = 0; i < rotationid; i++)
        {

            for (int  j = 0; j < rotationid; j++)
            {
                board[y + i][x + j] += s[i][j];
            }
        }

    }
return 0;
}


