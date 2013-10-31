#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//实现bigrand()，至少返回30个随机位
int bigrand();
//实现randint(l,u)，返回[l,u]范围内的一个随机整数
int randint(int l,int u);
 

int main()
{
    printf("============================================\n");
    printf("C库函数rand()通常返回约15个随机位\n");
    printf("使用该函数实现函数bigrand()和randint(l,u)\n");
    printf("要求前者至少返回30个随机位\n");
    printf("后者返回[l,u]范围内的一个随机整数\n");
    printf("============================================\n");
    printf("bigrand()=%d\n",bigrand());
    printf("randint(%d,%d)=%d\n",5000,10000,randint(5000,10000));
    return 0;
}

//实现bigrand()，至少返回30个随机位
int bigrand()
{ 
    srand((unsigned)time(NULL));
    return rand()*RAND_MAX + rand();
}
                        
//实现randint(l,u)，返回[l,u]范围内的一个随机整数
int randint(int l,int u)
{
    int temp;
    srand((unsigned)time(NULL));
    temp = floor(l + (1.0*rand()/RAND_MAX)*(u - l + 1 ));
    return temp;
}
