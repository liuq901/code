#include <cstdio>
#include <string>
#include <map>
using namespace std;
const int N=200010;
char a[100],b[100];
int f[N],s[N];
map <string,int> M;
int hash(const string &S)
{
    if (!M.count(S))
    {
        int id=M.size()+1;
        f[id]=id;
        s[id]=1;
        M[S]=id;
    }
    return(M[S]);
}
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        M.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%s%s",a,b);
            int x=hash(a),y=hash(b);
            if (find(x)!=find(y))
            {
                s[find(y)]+=s[find(x)];
                f[find(x)]=find(y);
            }
            printf("%d\n",s[find(y)]);
        }
    }
    return(0);
}

