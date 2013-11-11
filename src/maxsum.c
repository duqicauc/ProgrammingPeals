/************************************************************************/
/* maxsum.c---求一个向量的最大子向量                                                                     
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float maxsum(int l, int u); 
float maxsum4(int l,int u);

//a或b如果未函数，则无效，因为宏仅做字符串替换
#define maxmac(a, b) ((a) > (b) ? (a) : (b) )
// 如果希望宏的参数能够是函数，那么要定义函数别名
float maxfun(float a, float b)
{   
	return a > b ? a : b;
}
#define max(a, b) maxfun(a, b)

#define MAXN 100000
float x[MAXN];
int n;

/* Fill x[n] with reals uniform on [-m,m]
在-m和m之间的随机实数 */
void sprinkle(int m) 
{   int i;
    for (i = 0; i < n; i++)
        x[i] = m - 2*m*( (float) rand()/RAND_MAX);
}

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
		maxmac(maxsum(l, m), maxsum(m+1, u)));
}

/* 算法4：O(n)算法*/
float maxsum4(int l, int u)
{
	float maxendinghere=0;
	float maxsofar=0;
	int i;
	for (i = l; i<=u; i++) {
		//maxendinghere是关键，在该语句执行之前保存x[0..i-1]的最大值，该语句执行之后保存x[0...i]的最大值
		maxendinghere = max(maxendinghere + x[i],0);
		maxsofar = max(maxsofar,maxendinghere);
	}
	return maxsofar;
}

/************************************************************************/
/* algum：
/* 1---O(n3)算法
/* 2---O(n2)算法
/* 3---O(nlogn)算法
/* 4---O(n)算法
/************************************************************************/
int main()
{
	float maxnum;
	int algum,starttime,clicks;
	while (scanf("%d %d",&algum,&n) != EOF)
	{
		sprinkle(9);//生成[-9,9]之间的随机数填充x[n]数组
		starttime = clock();
		switch(algum) {
		case 3:
			maxnum = maxsum(0,n-1);
			break;
		case 4:
			maxnum = maxsum4(0,n-1);
		default:
			break;
		}
		clicks = clock() - starttime;
		printf("algum:%d\tn:%d\tmaxsub:%f\tclicks:%d\ttime:%f(s)\n",algum,n,maxnum,clicks,clicks/(float)CLOCKS_PER_SEC);
	}
	return 0;
}
