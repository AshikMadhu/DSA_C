#include <stdio.h>

void printmatrix(int m[10][10], int row, int col)
{
    int i, j;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

void convert(int a[10][10], int row, int col, int s[100][3])
{
    int i, j, k = 1;

    s[0][0] = row;
    s[0][1] = col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }

    s[0][2] = k - 1;
}

void printsparse(int s[100][3])
{
    int i;
    int nonzero = s[0][2];

    printf("Row\tColumn\tValue\n");

    for(i = 0; i <= nonzero; i++)
    {
        printf("%d\t%d\t%d\n",
               s[i][0],
               s[i][1],
               s[i][2]);
    }
}

int main()
{
    int A[10][10], B[10][10];
    int SA[100][3], SB[100][3];
    int C[10][10], T[10][10];

    int row, col;
    int i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &row, &col);

    printf("\nEnter elements of Matrix A:\n");

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    printf("\nMatrix A\n");
    printmatrix(A, row, col);

    printf("\nMatrix B\n");
    printmatrix(B, row, col);

    convert(A, row, col, SA);
    convert(B, row, col, SB);

    printf("\nSparse Matrix of A\n");
    printsparse(SA);

    printf("\nSparse Matrix of B\n");
    printsparse(SB);

    printf("\nAddition of Matrices\n");

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printmatrix(C, row, col);

    printf("\nTranspose of the Result Matrix\n");

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            T[j][i] = C[i][j];
        }
    }

    printmatrix(T, col, row);

    return 0;
}