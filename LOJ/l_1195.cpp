#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
char a[10010],b[10010];
int f[10010],g[10010];
void calc(char a[],int n,int f[])
{
    stack <int> s;
    for (int i=1;i<=n;i++)
        if (a[i]=='1')
            s.push(i);
        else
        {
            f[s.top()]=i;
            s.pop();
        }
}
string calc(int a[],int l,int r)
{
    if (l>r)
        return("");
    if (a[l]==r)
        return("("+calc(a,l+1,r-1)+")");
    vector <string> tmp;
    for (int i=l;i<=r;i=a[i]+1)
        tmp.push_back(calc(a,i,a[i]));
    sort(tmp.begin(),tmp.end());
    string ret;
    for (int i=0;i<tmp.size();i++)
        ret+=tmp[i];
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(a);
    while (T--)
    {
        gets(a+1);
        gets(b+1);
        static int id=0;
        printf("Case %d: ",++id);
        int n=strlen(a+1);
        calc(a,n,f);
        calc(b,n,g);
        printf("%s\n",calc(f,1,n)==calc(g,1,n)?"Same":"Different");
    }
    return(0);
}

