/**
 * 生成1000 0000个[100 0000, 999 9999]之间的不重复的数
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num[10000000];
unsigned bigrand();
unsigned randint(int l, int u);
void     swap(int *a,int *b);

int main(int argc,char* argv[])
{
    int i;
    FILE *fp = fopen("rand_num_file.txt","a+");
    if(fp == NULL)
    {
        printf("cannot open this file!\n");
        exit(0);
    }
    srand((unsigned)time(NULL));
    
    for(i=0; i<10000000; i++)
        num[i] = i;
    for(i=0; i<1000000; i++)
    {
        swap(&num[i],&num[randint(1000000,10000000-1)]);
        fprintf(fp,"%d\n",num[i]);
    }
    fclose(fp);
    return 0;
}

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

