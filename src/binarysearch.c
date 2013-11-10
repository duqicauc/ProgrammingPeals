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
	/*printf(" %d %d %d\n", l, m, u);*/
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
        int i,t,maxn = 1000;

//		/* 人工测试 */
//        while (scanf("%d %d",&n,&t) != EOF){
//                for(i = 0; i < n; i++)
//                        x[i] =  10*i;
//                printf(" %d\n",binarysearch(t));
//        }

	/* 自动化测试 */
	/* test distinct elements(plus one at the end) */
	for (n=0; n<=maxn; n++) {// 测试主循环
		printf("n=%d\n",n);//当前测试数组中的元素个数
			
		/* 测试所有元素互异的情况*/
		for (i=0; i<=n; i++) {				
			x[i] = 10 * i;
		}
		for (i=0; i<n; i++) {
			assert(binarysearch(10*i) == i);
			assert(binarysearch(10*i - 5) == -1);
		}
		assert(binarysearch(10*n - 5) == -1);
		assert(binarysearch(10*n) == -1);

		/* test equal elements */
		for (i=0; i<=n; i++) {
			x[i] = 10;
		}
		if (n == 0){
			assert(binarysearch(10) == -1);
		}
		else{
			assert(binarysearch(0<=binarysearch(10) && binarysearch(10)<n));
		}
		assert(binarysearch(5) == -1);
		assert(binarysearch(15) == -1);
	}
}
