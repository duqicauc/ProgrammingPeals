/************************************************************************/
/* maxsum.c---求一个向量的最大子向量                                                                     
/************************************************************************/
#include <stdio.h>

//a或b如果未函数，则无效，因为宏仅做字符串替换
#define maxmac(a, b) ((a) > (b) ? (a) : (b) )
// 如果希望宏的参数能够是函数，那么要定义函数别名
float maxfun(float a, float b)
{   
	return a > b ? a : b;
}
#define max(a, b) maxfun(a, b)

#define MAXN 1000
float x[MAXN];

/* 算法3：O(nlogn)算法
分治法，求向量的最大子向量 */
float maxsum(int l, int u)
{
	int i, m;
	float sum, lmax, rmax;
	//处理0个元素的情况
	if (l > u){
		return 0;
	}
	//处理1个元素的情况
	if (l == u) {
		return max(0,x[l]);
	}

	m = (l + u)/2;
	//计算左半部分的最大值lmax
	lmax=sum = 0;
	for ( i = m; i >= l; i-- ) {
		sum += x[i];
		lmax = max(sum,lmax);
	}
	//计算右半部分的最大值rmax
	rmax=sum = 0;
	for ( i = m+1; i <= u; i++) {
		sum += x[i];
		rmax = max(sum,rmax);
	}
	//递归调用
	return max(lmax + rmax,
		max(maxsum(l, m), maxsum(m+1, u)));
}

/* 算法4：O(n)算法*/
float maxsum4(int l, int u)
{
	int maxendinghere=0;
	int maxsofar=0;
	int i;
	for (i = l; i<=u; i++) {
		//maxendinghere是关键，在该语句执行之前保存x[0..i-1]的最大值，该语句执行之后保存x[0...i]的最大值
		maxendinghere = max(maxendinghere + x[i],0);
		maxsofar = max(maxsofar,maxendinghere);
	}
	return maxsofar;
}

int main()
{
	/* 生成实验数据：大批量的随机数数组，给定数组元素值的范围 */
	x[0] = 1;
	x[1] = -2;
	x[2] = 3;
	x[3] = 10;
	x[4] = -4;
	x[5] = 7;
	x[6] = 2;
	x[7] = -5;
	//printf("maxsub is: %.2f\n",maxsum(0,7));
	printf("maxsub is: %.2f\n",maxsum4(0,7));
	return 0;
}
