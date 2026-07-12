#include <stdio.h>

struct poly
{
int coeff;
int expo;
};

int main()
{
struct poly x1[20], x2[20], x3[40];
int n1, n2;
int i, j, k;

printf("Enter number of terms in first polynomial: ");
scanf("%d", &n1);

printf("Enter coefficient and exponent (descending order):\n");
for(i = 0; i < n1; i++)
{
scanf("%d %d", &x1[i].coeff, &x1[i].expo);
}

printf("Enter number of terms in second polynomial: ");
scanf("%d", &n2);

printf("Enter coefficient and exponent (descending order):\n");
for(i = 0; i < n2; i++)
{
scanf("%d %d", &x2[i].coeff, &x2[i].expo);
}

i = 0;
j = 0;
k = 0;

while(i < n1 && j < n2)
{
if(x1[i].expo == x2[j].expo)
{
x3[k].coeff = x1[i].coeff + x2[j].coeff;
x3[k].expo = x1[i].expo;

i++;
j++;
k++;
}
else if(x1[i].expo > x2[j].expo)
{
x3[k] = x1[i];

i++;
k++;
}
else
{
x3[k] = x2[j];

j++;
k++;
}
}

while(i < n1)
{
x3[k] = x1[i];
i++;
k++;
}

while(j < n2)
{
x3[k] = x2[j];
j++;
k++;
}

printf("\nResultant Polynomial:\n");

for(i = 0; i < k; i++)
{
if(x3[i].expo == 0)
printf("%d", x3[i].coeff);
else if(x3[i].expo == 1)
printf("%dx", x3[i].coeff);
else
printf("%dx^%d", x3[i].coeff, x3[i].expo);

if(i != k - 1)
printf(" + ");
}

return 0;
}
