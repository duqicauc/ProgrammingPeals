/*
 * 问题：给定一个文本文件作为输入，查找其中的最长的重复字符串
 * 例子："Ask not what your country can do for you, but what
 * you can do for your country"中最长的重复字符串为"can do for
 * you"，第二长的是"your country"
 *
 * 思路1：O(n2),比较每一对字串，外循环从0->n-1;内循环从i->n-1；
 * 针对每一对子串，利用一个子函数comlen(p,q)计算两个字符串中共
 * 同部分的最大长度。
 *
 * 思路2：O(nlogn),使用数据结构“后缀数组”，这个结构是一个字符指
 * 针数组，记为a。读取输入的文本时，对a进行初始化，使得每个元素
 * 指向输入字符串中的相应字符。
 * 例如：输入字符串“banana”
 * 后缀数组为：
 *      a[0] : banana
 *      a[1] : anana
 *      a[2] : nana
 *      a[3] : ana
 *      a[4] : na
 *      a[5] : a
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 5000000
char c[MAXN], *a[MAXN];

/* 
 * 比较字符串*p和字符串*q的大小
 * *p < *q, 返回-1；
 * *p == *q,返回0；
 * *p > *q, 返回1
 * */
int pstrcmp(char **p, char **q)
{
    return strcmp(*p,*q);
}

/* 字符串p和q中共同部分的长度 */
int comlen(const char *p, const char *q)
{
    int i = 0;
    while(*p && (*p++ == *q++))
        i++;
    return i;
}

int main()
{
    char ch;
    int n = 0, i;
    /* 读入字符串，同时构建后缀数组 */
    while((ch = getchar()) != EOF)
    {
        a[n] = &c[n];
        c[n++] = ch;
    }
    c[n] = '\0';
    
    /* 使用qsort函数对后缀数组作排序 */
    qsort(a, n, sizeof(char *), pstrcmp);
    
    /* 遍历后缀数组，求最大重复字串 */
    int maxlen = 0,temp,maxi;
    for (i = 0; i < n-1; i++)
    {
        temp = comlen(a[i], a[i+1]);
        if(temp > maxlen)
        {
            maxlen = temp;
            maxi = i;
        }
    }
    printf("%.*s\n", maxlen, a[maxi]);
    return 0;
}
