#include <stdio.h>

#define TEST


int main(void)
{
    #ifdef TEST
        freopen("1065.txt", "r", stdin);
    #endif 
    
    long long a, b, c, sum;
    int n, i, j;
    j = 0;
    scanf("%d", &n);
//    printf("%d\n", n);
    for (i=0; i<n; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        sum = a+b;
        if (a>0 && b>0 && sum<0)    j = 1;
        else if (a<0 && b<0 && sum>=0)    j = 0;        //sum>=0中的等于号不能少。 
        else {
            j = (sum > c)? 1:0;
        }
        
        if (j)
        {
            printf("Case #%d: true\n", i+1);
        }
        else
        {
            printf("Case #%d: false\n", i+1);
        }
    }
    
    
    
    return 0;
}
