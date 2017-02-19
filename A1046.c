#include <stdio.h>
#include <string.h>

#define TEST

int maxdis(int a, int b, int n, int num[n]);

int main(void)
{
    #ifdef TEST
        freopen("1046.txt", "r", stdin);
    #endif 
    int n, m;
    scanf("%d", &n);
    int num[n];
    int i, a, b;
    memset(num, 0, sizeof(num));
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", num+i);
//        printf("%d ", num[i]);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        //在线处理
//        printf("%d %d\n", a, b);
        printf("%d\n", maxdis(a-1, b-1, n, num));
    }
    
    

    return 0;
}

int maxdis(int a, int b, int n, int num[n])
{
    int sum1, sum2, i;
    int a1, b1;
    
    sum1 = sum2 = 0;
    
    if (a > b)
    {
        a1 = b;
        b1 = a;
    }
    else
    {
        a1 = a;
        b1 = b;
    }
    
//    printf("%d %d\n", a1, b1);
    
    for (i = a1; i < b1; i++)
    {
        sum1 +=  num[i];
    }
    
    for (i = b1; i < n; i++ )
    {
        sum2 += num[i];
    }
    
    for (i = 0; i < a1; i++ )
    {
        sum2 += num[i];
    }
    
//    printf("%d %d\n", sum1, sum2);
    return sum1 > sum2 ? sum2 : sum1;
    
    
    
}
