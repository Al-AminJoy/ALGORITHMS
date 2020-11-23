#include<bits/stdc++.h>
#define N 4

/* A utility function to print solution */
void printSolution(int board[N][N])
{
    static int k = 1;
    printf("%d-\n",k++);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}


bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(int board[N][N], int col)
{

    if (col == N)
    {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        /* Check if queen can be placed on
        board[i][col] */
        if ( isSafe(board, i, col) )
        {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;

            res = solveNQUtil(board, col + 1) || res;

            board[i][col] = 0; // BACKTRACK
        }
    }


    return res;
}


void solveNQ()
{
    int board[N][N];
    memset(board, 0, sizeof(board));

    if (solveNQUtil(board, 0) == false)
    {
        printf("Solution does not exist");
        return ;
    }

    return ;
}

int main()
{
    solveNQ();
    return 0;
}
