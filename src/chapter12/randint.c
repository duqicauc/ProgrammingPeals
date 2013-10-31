#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 生成大随机数（30位）
 * */
unsigned int bigrand()
{
    return rand()*RAND_MAX + rand();
}

/**
 * 生成[l,m]之间的随机数
 * */
unsigned int randint(int l, int m)
{
    return l + bigrand() % (m-l+1);
}

/**
 * 测试bigrand()和randint(int,int)的正确性
 * */
int main()
{
    // 设置种子
    srand((unsigned)time(NULL));
    // 生成[1000000,10000000]之间的10个随机数
    for(int i=0;i<10;i++)
    {
        printf("bigrand() = %u\n",bigrand());
        printf("randint(1000000,10000000) = %u\n",randint(1000000,10000000));
    }
    return 0;
}
