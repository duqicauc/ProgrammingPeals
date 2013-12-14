#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *nodeptr;
typedef struct node{
    char *word;
    int count;
    nodeptr next;
}node;

#define NHASH 29989
#define NULT 31
nodeptr bin[NHASH];

/* hash函数：激素指定单词字符串的映射位置 */
unsigned int hash(char *p)
{
    unsigned int h = 0;
    for ( ; *p; p++)
        h = NULT * h + *p;
    return h % NHASH;
}

/* incword:将指定单词字符串添加到三列表中*/
void incword(char *s)
{
    int h = hash(s);
    nodeptr p;
    for (p = bin[h]; p != NULL; p=p->next)
        if (strcmp(s, p->word) == 0)
        {
            (p->count)++;
            return;
        }
    p = (nodeptr)malloc(sizeof(node));
    p->count = 1;
    p->word = (char*)malloc(strlen(s) +  1);
    strcpy(p->word,s);
    p->next = bin[h];
    bin[h] = p;
}

int main()
{
    int i;
    char buf[50];
    nodeptr p;

    for (i = 0;i < NHASH; i++ )
        bin[i] = NULL;

    while(scanf("%s",buf) != EOF)
        incword(buf);
    
    for (i =0; i< NHASH; i++)
        for (p = bin[i]; p != NULL; p = p->next)
            printf("%s\t%d\n", p->word, p->count);
    return 0;
}
