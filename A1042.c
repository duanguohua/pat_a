#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TEST

char shcdj(int a);
void swap(int *a, int *b);

int main(void)
{
    #ifdef TEST
        freopen("1042.txt", "r", stdin);
    #endif 
    
    int num[55]={0};
    int num1[55]={0};
    int order[55]={0};
    int i, n, j;
    int tmp, s;
    //´ÎÊý 
    scanf("%d", &n);
    //Ë³Ðò 
    for (i = 1; i < 55; i++)
    {
        scanf("%d", &order[i]);
        num[i] = i;
    }
    
    for (j = 0; j < n; j++)
    {
        
        for (i = 1; i < 55; i++)
        {
            num1[order[i]] = num[i];
        }
        
        for (i = 1; i < 55; i++)
        {
            num[i] = num1[i];         
        }
    }

    
    
    for (i = 1; i < 55; i++)
    {
        i==1 ? printf("%c%d", shcdj(num[i]), (num[i]-1)%13+1) : printf(" %c%d", shcdj(num[i]), (num[i]-1)%13+1);
    }
    
    
    
    
    
    
    return 0;
}



char shcdj(int a)
{
    switch ((a-1)/13)
    {
        case 0: return 'S';
        case 1: return 'H';
        case 2: return 'C';
        case 3: return 'D';
        case 4: return 'J';
    }
}
