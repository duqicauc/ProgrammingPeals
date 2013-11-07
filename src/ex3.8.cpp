#include <iostream>
using namespace std;

int main()
{
	char show[5]={125,125,125,125,125}; //初始都显示为0
	int a[10] = {125,80,55,87,90,79,111,84,127,95};//七段数码管表示的0~9，用下标0~9对应相应的七段数码管二进制值
	int s,r=0;
	cout << "请输入5位数：" <<endl;
	cin >> s;

	// 将用户输入的数字分解
	int i=4;
	while (s!=0)
	{	
		r = s % 10;
		show[i--] = a[r];
		s /= 10;
	}

	return 0;
}
