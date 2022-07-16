#include <stdio.h>
#define N 4 // N is the size of the Maze
typedef long long LL;
bool SolveUtil(LL maze[N][N], LL x, LL y, LL sol[N][N]);
void DispMazeSol(LL sol[N][N]);
bool MazeSol(LL maze[N][N])
{
/* This Functions Checks if any Solution Exists or not */
LL sol[N][N] = { { 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 },
{ 0, 0, 0, 0 } };
if (SolveUtil(maze, 0, 0, sol) == false)
{
printf("Solution doesn't exist");
return false;
}
DispMazeSol(sol);
return true;
}
bool isValid(LL maze[N][N], LL x, LL y)
{
/* This Function checks for the next possible valid move */
if ( x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
return true;
return false;
}
bool SolveUtil( LL maze[N][N], LL x, LL y, LL sol[N][N])
{
/* This is a Recursive Function to solve the Maze and provide the Solution
Matrix */
if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
{
sol[x][y] = 1;
return true;
}
if (isValid(maze, x, y) == true)
{
if (sol[x][y] == 1)
return false;
sol[x][y] = 1;
if (SolveUtil(maze, x + 1, y, sol) == true)
return true;
if (SolveUtil(maze, x, y + 1, sol) == true)
return true;
if (SolveUtil(maze, x - 1, y, sol) == true)
return true;
if (SolveUtil(maze, x, y - 1, sol) == true)
return true;
sol[x][y] = 0;
return false;
}
return false;
}
void DispMazeSol(LL sol[N][N])
{
/* This Function Displays the Solution Maze */
for (LL i = 0; i < N; i++)
{
for (LL j = 0; j < N; j++)
printf("%lld ", sol[i][j]);
printf("\n");
}
}
int main()
{
LL maze[N][N] = { { 1, 0, 1, 0 },
{ 1, 1, 0, 1 },
{ 0, 1, 1, 0 },
{ 1, 0, 1, 1 } };
printf("Solution Path:\n");
MazeSol(maze);
return 0;
}

