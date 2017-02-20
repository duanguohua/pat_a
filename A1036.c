#include <stdio.h>
#include <string.h>

#define TEST


int main(void)
{
    #ifdef TEST
        freopen("1036.txt", "r", stdin);
    #endif 
    int i, n;
    int min, mini, max, maxi;
    min = 101;
    max = -1;
    mini = maxi = 0;
    scanf("%d", &n);
    char ch, name[n][20], id[n][20];
    int score[n];
    memset(score, 0, sizeof(score));
    
    for (i=0; i<n; i++)
    {
        scanf("%s %c %s %d", name[i], &ch, id[i], score+i);
        if (ch=='F')
        {
            if (score[i]>max)
            {
                max = score[i];
                maxi = i;
            }
        }
        else
        {
            if (score[i]<min)
            {
                min = score[i];
                mini = i;
            }
        }
    }
    if (max == -1)
    {
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n", name[maxi], id[maxi]);
    }
    
    if (min == 101)
    {
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n", name[mini], id[mini]);
    }
    
    if (min==101 || max==-1)
    {
        printf("NA");
    }
    else
    {
        printf("%d", max-min);
    }
    
    
    return 0;
}
