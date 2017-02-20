#include <stdio.h>

#define TEST

double max(double a, double b, double c);
char wtl[3] = {'W', 'T', 'L'};
int main(void)
{
    #ifdef TEST
        freopen("1011.txt", "r", stdin);
    #endif 
    
    double max;
    int ind;
    double tmp, sum;
    tmp = 0.0;
    sum = 1.0;
    int i, j;
    for (i=0; i<3; i++)
    {
        max = 0;
        for (j=0; j<3; j++)
        {
            scanf("%lf", &tmp);
            if (tmp>max)
            {
                max = tmp;
                ind = j;
            }
        }
        sum *= max;
        printf("%c ", wtl[ind]);
    }
    sum = (sum*0.65-1)*2;
    printf("%.2lf", sum);
    
    
    
    return 0;
}

