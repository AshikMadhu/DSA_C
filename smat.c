#include <stdio.h>

void printMatrix(int m[10][10], int row, int col)
{
    int i, j;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            printf("%4d", m[i][j]);
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

void printSparse(int s[100][3])
{
    int i;

    printf("Row\tCol\tValue\n");

    for(i = 0; i <= s[0][2]; i++)
    {
        printf("%d\t%d\t%d\n", s[i][0], s[i][1], s[i][2]);
    }
}

void addSparse(int A[100][3], int B[100][3], int C[100][3])
{
    int i = 1, j = 1, k = 1;

    if(A[0][0] != B[0][0] || A[0][1] != B[0][1])
    {
        printf("\nAddition not possible.\n");
        C[0][2] = -1;
        return;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while(i <= A[0][2] && j <= B[0][2])
    {
        if(A[i][0] == B[j][0] && A[i][1] == B[j][1])
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
            k++;
        }
        else if((A[i][0] < B[j][0]) ||
               (A[i][0] == B[j][0] && A[i][1] < B[j][1]))
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
            k++;
        }
        else
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
            k++;
        }
    }

    while(i <= A[0][2])
    {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++;
        k++;
    }

    while(j <= B[0][2])
    {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++;
        k++;
    }

    C[0][2] = k - 1;
}

void transposeSparse(int A[100][3], int T[100][3])
{
    int i, j, k = 1;

    T[0][0] = A[0][1];
    T[0][1] = A[0][0];
    T[0][2] = A[0][2];

    for(i = 0; i < A[0][1]; i++)
    {
        for(j = 1; j <= A[0][2]; j++)
        {
            if(A[j][1] == i)
            {
                T[k][0] = A[j][1];
                T[k][1] = A[j][0];
                T[k][2] = A[j][2];
                k++;
            }
        }
    }
}

int main()
{
    int A[10][10], B[10][10];
    int SA[100][3], SB[100][3];
    int SC[100][3], ST[100][3];

    int row, col;
    int i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &row, &col);

    printf("\nEnter Matrix A:\n");

    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter Matrix B:\n");

    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &B[i][j]);

    convert(A, row, col, SA);
    convert(B, row, col, SB);

    printf("\nSparse Matrix A\n");
    printSparse(SA);

    printf("\nSparse Matrix B\n");
    printSparse(SB);

    addSparse(SA, SB, SC);

    printf("\nSparse Matrix Addition\n");
    printSparse(SC);

    transposeSparse(SC, ST);

    printf("\nTranspose of Resultant Sparse Matrix\n");
    printSparse(ST);

    return 0;
}
