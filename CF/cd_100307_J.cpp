#include <cstdio>
#include <map>
#include <sstream>
using namespace std;
map <string,int> M;
int pre[50010],f[50010],best[50010];
char buf[1000000];
void print(int x)
{
    if (f[x]!=1)
    {
        print(pre[x]);
        printf(" ");
    }
    printf("%d",x);
}
int main()
{
    freopen("join.in","r",stdin);
    freopen("join.out","w",stdout);
    int n;
    scanf("%d",&n);
    gets(buf);
    for (int i=1;i<=n;i++)
    {
        gets(buf);
        stringstream sin(buf);
        string name;
        sin>>name;
        name=name.substr(0,name.size()-1);
        if (!M.count(name))
        {
            int tmp=M.size()+1;
            M[name]=tmp;
        }
        int x=M[name];
        f[i]=1;
        while (sin>>name)
        {
            if (!M.count(name))
                continue;
            int y=M[name];
            if (x!=y && best[y]!=0 && f[best[y]]+1>f[i])
            {
                f[i]=f[best[y]]+1;
                pre[i]=best[y];
            }
        }
        if (best[x]==0 || f[i]>f[best[x]])
            best[x]=i;
    }
    int pos=1;
    for (int i=1;i<=n;i++)
        if (f[i]>f[pos])
            pos=i;
    printf("%d\n",f[pos]);
    print(pos);
    printf("\n");
}

