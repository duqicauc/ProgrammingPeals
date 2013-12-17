#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXN 500000
char c[MAXN], *a[MAXN];
char dest[50];

int pstrcmp(char **p, char **q)
{
    return strcmp(*p,*q);
}

int comlen(char *p, char *q)
{
    int i=0;
    while(*p && (*p++ == *q++))
        i++;
    return i;
}

int main()
{
    /* 读入文本，并构建后缀数组 */
    char ch;
    int n = 0,i;
    int maxi,temp;
    int maxlen = 0;
    
    printf("请输入原文本: ");
    while((ch = getchar()) != EOF)
    {
        a[n] = &c[n];
        c[n++] = ch;
    }
    c[n] = '\0';
    
    printf("请输入目标字符串：");
    scanf("%s",dest);

    /* 排序后缀数组 */
    qsort(a, n, sizeof(char *), pstrcmp);
    
    /* 遍历后缀数组，找到目标字符串 */
    for (i = 0; i < n; i++)
    {
        temp = comlen(a[i], dest);
        if(temp > maxlen)
        {
            maxlen = temp;
            maxi = i;
        }
    }
    
    printf("%.*s\n", maxlen, a[maxi]);
    return 0;
}
