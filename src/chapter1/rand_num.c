/**
 * 生成1000 0000个[100 0000, 999 9999]之间的不重复的数
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//#define ARRAY_NUMBER 10000000
//#define SORT_NUMBER 1000000
unsigned bigrand();
unsigned randint(int l, int u);
void    swap(int *a,int *b);

int main(int argc,char* argv[])
{
    int num[1000000];
    int i;
    FILE *rand_num_file = fopen("rand_num_file.txt","w+");
   
    srand((unsigned)time(NULL));
    
    for( i=0; i<1000000; i++)
        num[i] = randint(1000000,9999999);
         
    for( i=0; i<1000000; i++)
        fprintf(rand_num_file,"%d\n",num[i]);
   
    return 0;
}

/*实现randint(l,u)，返回[l,u]范围内的一个随机整数
int randint(int l,int u)
{
    int temp;
    temp = floor(l + (1.0*rand()/RAND_MAX)*(u - l + 1 ));
    return temp;
}*/
/* 
 * 生成大随机数（30位）
 **/
unsigned int bigrand()
{
    return rand()*RAND_MAX + rand();
}

/* 
 * 生成[l,m]之间的随机数
 **/
unsigned int randint(int l, int u)
{
        return l + bigrand() % (u-l+1);
}

//交换
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

