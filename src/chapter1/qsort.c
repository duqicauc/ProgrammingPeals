#include <stdlib.h>
#include <stdio.h>

int intcomp(void *a,void *b)
{
    return *(int*)a - *(int*)b;
}

int num[1000000];
FILE *file;
FILE *result_file;

int main(int argc,char* argv[])
{
    file = fopen("rand_num_file.txt","r+");
    result_file = fopen("result.txt","w+");
    int i,n=0;
    while(fscanf(file,"%d",&num[n]) != EOF)
        n++;
    
    qsort(num,1000000,sizeof(num[0]),(__compar_fn_t)intcomp);
   
    for(i=0;i<1000000;i++)
        fprintf(result_file,"%d\n",num[i]);
    
    return 0;
}
