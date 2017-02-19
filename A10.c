#include <stdio.h>

#define TEST


int main(void)
{
    #ifdef TEST
        freopen("1012.txt", "r", stdin);
    #endif 
    
    
    
    
    return 0;
}
