/************************************************************************/
/* maxsum.c---求一个向量的最大子向量                                                                     
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float maxsum1();
float maxsum2a();
float maxsum2b();
float maxsum3(int l, int u); 
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

/* 算法1：O(n3)算法*/
float maxsum1()
{   
	int i, j, k;
    float sum, maxsofar = 0;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++) {
            sum = 0;
            for (k = i; k <= j; k++)
                sum += x[k];
            maxsofar = maxmac(maxsofar,sum);
		}
    return maxsofar;
}

/* 算法2：O(n2)算法*/
float maxsum2a()
{
	int i, j;
    float sum, maxsofar = 0;
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = i; j < n; j++) {
            sum += x[j];
            maxsofar = maxmac(maxsofar,sum);
        }
    }
    return maxsofar;
}

/* 算法2：O(n2)算法，利用累加和*/
float cumvec[MAXN+1]; //注意c语言如何让数组能否访问array[-1],使用指针

float maxsum2b()
{
	int i, j;
    float *cumarr, sum, maxsofar = 0;
    cumarr = cumvec+1; /* to access cumarr[-1] */
    cumarr[-1] = 0;
	// cumarr[i]记录x[0...i]各个元素的累加和
    for (i = 0; i < n; i++)
        cumarr[i] = cumarr[i-1] + x[i];
	
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
			// 所以x[i...j] = cumarr[j] - cumarr[i-1] 
            sum = cumarr[j] - cumarr[i-1];
            if (sum > maxsofar)
                maxsofar = sum;
        }
    }
    return maxsofar;
}


/* 算法3：O(nlogn)算法
分治法，求向量的最大子向量 */
float maxsum3(int l, int u)
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
	//递归调用,这里的max最好不要用宏maxmac，因为宏的直接替换特性
	//会造成两次同一函数的递归调用，反而运行时间比O(n2)算法的长了
	return max(lmax + rmax,
		max(maxsum3(l, m), maxsum3(m+1, u)));
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
/* 21---O(n2)算法a
/* 22---O(n2)算法b
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
		case 1:
			maxnum = maxsum1();
			break;
		case 21:
			maxnum = maxsum2a();
			break;
		case 22:
			maxnum = maxsum2b();
			break;
		case 3:
			maxnum = maxsum3(0,n-1);
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
