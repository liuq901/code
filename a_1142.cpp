#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
set <string> S;
char buf[10000];
string inv(string a)
{
    reverse(a.begin(),a.end());
    return(a);
}
void work(const string &a,const string &b)
{
    S.insert(a+b);
    S.insert(a+inv(b));
    S.insert(inv(a)+b);
    S.insert(inv(a)+inv(b));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",buf);
        string s=buf;
        S.clear();
        for (int i=1;i<s.size();i++)
        {
            work(s.substr(0,i),s.substr(i));
            work(s.substr(i),s.substr(0,i));
        }
        printf("%d\n",S.size());
    }
    return(0);
}

