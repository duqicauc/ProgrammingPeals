/* 问题定义：编写程序从0~n-1中随机取出m个有序整数，要求不能重复 */
#include <iostream>
#include <ctime>
#include <set>
#include <algorithm>
using namespace std;

#define MAXN 10000000
int x[MAXN];

/* 生成一个大随机数 */
int bigrand()
{
	return RAND_MAX*rand() + rand();
}

/* 生成[l,u]之间的一个随机数 */
int randint(int l, int u)
{	return l + bigrand() % (u-l+1);
}

/*使用C++的STL库，这里的时间主要耗费每生成一个随机数，在
将它放入结果集之前要检查是否已经存在*/
void gensets(int m, int n)
{
	int start,end,clicks;
	start = clock();
	set<int> S; /* 忽略重复值 */
	while (S.size() <m)
		S.insert(bigrand() % n);
	clicks = clock() - start;
	cout << clicks/float(CLOCKS_PER_SEC) << "s\n"; 
//	set<int>::iterator i;
//	for (i=S.begin(); i != S.end(); i++)
//	{
//		cout << *i << "\n";
//	}
}

/* 
m   --- select
n-i --- remaining
只要m<=n,程序选出的整数就恰为m个：
(1)不会多选，因为当select等于0之后，if条件语句不会成立，也就不能再选择整数
(2)不会少选，因为当select/remaining=1时，if条件一定成立（n-i = m时肯定成立）
	
时间复杂度：O(n)
时空复杂度：O(m)
赋值次数：m
*/
void getknuth(int m, int n)
{
	int start,clicks,j=0;
	start = clock();
	for (int i=0; i< n; i++)
	{
		if (bigrand() % (n-i) < m)
		{
			//cout << i << "\n";
			x[j++] = i;
			m--;
		}
	}
	clicks = clock() - start;
	cout << clicks/float(CLOCKS_PER_SEC) << "s\n"; 
}

/* 相比Knuth算法，需要更多的内存读写操作，所以性能要差一些 
时间复杂度：O(n)+O(m)
空间复杂度：O(n+1)
赋值次数：n+3*m;
*/
void genshuf(int m, int n)
{
	int start,end,clicks;
	start = clock();
	int i, j;
	for (i = 0; i < n; i++)  
		x[i] = i;
	for (i = 0; i < m; i++) {
		j = randint(i, n-1);
		int t = x[i]; x[i] = x[j]; x[j] = t;
	}
	sort(x, x+m);
	clicks = clock() - start;
	cout << clicks/float(CLOCKS_PER_SEC) << "s\n"; 
//	for (i = 0; i < m; i++)
//		cout << x[i] << "\n";
}

int main()
{
	//gensets(1000000,MAXN);
	//getknuth(1000000,10000000);
	genshuf(1000000,MAXN);
	return 0;
}
