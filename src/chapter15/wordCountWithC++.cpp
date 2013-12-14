#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> M;
    map<string, int>::iterator iter;
    string str;
    while(cin >> str)
        M[str]++;
    for (iter = M.begin(); iter != M.end(); iter++)
        cout << iter->first << "\t" << iter->second <<endl;
    return 0;
}
