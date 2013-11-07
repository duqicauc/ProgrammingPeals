#include <iostream>
using namespace std;

int main()
{
	/* 输入 */
    int a[10] = {0};
    int c[10] = {0,1,2,3,4,5,6,7,8,9};
    int m = 7;
    int n,k;
	/* 计算 */
	// 第一个for循环求a1~am
    for(n=1;n<=7;n++)
    {
		// 第二个for循环求a[n]
       for(k=1;k<n;k++)
       {	   
          a[n] += a[n-k]*c[k];
	   }
	   k--;//微调
	   // 给每一个a[n]加相应的常数
       a[n] += c[k+1];
    }
    /* 输出 */
    for(int i=1;i<=m;i++)
    {
      cout << a[i] << endl;
    }
    return 0;    
}
