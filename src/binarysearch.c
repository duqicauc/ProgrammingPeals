#include <stdio.h>

#define MAX 20
typedef int DataType;

int n;
DataType x[MAX];

int binarysearch(DataType t)
	/* return (any) position if t in sorted x[0..n-1] or
	   -1 if t is not present */
{
	int l,u,m;
	l = 0;
	u = n-1;
	while(l <= u){
		m = (l + u)/2;
		if (x[m] < t)
			l = m + 1;
		else if (x[m] == t)
			return m;
		else
			u = m - 1;
	}
	return -1;
}

/* C语言脚手架：调用binarysearch的驱动程序 */
int main()
{
	int i,t;
	while (scanf("%d %d",&n,&t) != EOF){
		for(i = 0; i < n; i++)
			x[i] =  10*i;
		printf(" %d\n",binarysearch(t));
	}
	return 0;
}
