#include <stdio.h>
#include <string.h>

#define TEST

int mindis(int a, int b, int n, int num[n]);
    int sum = 0;
    
int main(void)
{
    #ifdef TEST
        freopen("1046.txt", "r", stdin);
    #endif 
    int n, m;
    scanf("%d", &n);
    
    int num[n];
    int dis[n];

    int ans = 0;
    int i, a, b;
    memset(num, 0, sizeof(num));
    memset(dis, 0, sizeof(dis));
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", num+i);
        dis[i] = sum;
        sum += num[i];      
//        printf("%d ", dis[i]);
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        //在线处理
        printf("%d\n", mindis(a-1, b-1, n, dis));
    }
    
    

    return 0;
}

int mindis(int a, int b, int n, int dis[n])
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
    
    sum1 = dis[b1] - dis[a1];
    sum2 = sum - sum1;
//    printf("%d %d\n", sum1, sum2);
    return sum1 > sum2 ? sum2 : sum1;   
    
}
