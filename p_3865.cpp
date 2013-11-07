#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const ull lq=10007;
vector <int> s[10010];
vector <ull> tmp[10010];
char buf[1000000];
ull hash(const string &s)
{
    ull ret=0;
    for (int i=0;i<s.size();i++)
        ret=ret*lq+s[i];
    return(ret);
}
vector <ull> split(char *s)
{
    vector <ull> ret;
    int len=strlen(s);
    s[len]=',';
    string now="";
    for (int i=0;i<=len;i++)
        if (s[i]==',')
        {
            ret.push_back(hash(now));
            now="";
        }
        else
            now+=s[i];
    return(ret);
}
int c[10010];
ull a[10010];
inline bool cmp(int x,int y)
{
    return(a[x]<a[y]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    gets(buf);
    for (int i=1;i<=n;i++)
    {
        gets(buf);
        tmp[i]=split(buf);
    }
    vector <ull> X;
    for (int i=1;i<=n;i++)
        for (int j=0;j<m;j++)
            X.push_back(tmp[i][j]);
    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    for (int i=1;i<=n;i++)
    {
        s[i].resize(m);
        for (int j=0;j<m;j++)
            s[i][j]=lower_bound(X.begin(),X.end(),tmp[i][j])-X.begin();
    }
    bool flag=true;
    for (int i=0;i<m;i++)
        for (int j=i+1;j<m;j++)
        {
            for (int k=1;k<=n;k++)
            {
                c[k]=k;
                a[k]=ull(s[k][i])*1000000+s[k][j];
            }
            sort(c+1,c+n+1,cmp);
            for (int k=2;k<=n;k++)
                if (a[c[k-1]]==a[c[k]])
                {
                    flag=false;
                    printf("NO\n%d %d\n%d %d\n",c[k-1],c[k],i+1,j+1);
                    goto last;
                }
        }
last:
    if (flag)
        printf("YES\n");
    return(0);
}

