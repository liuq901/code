#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;
int f[210][2],g[210][2];
map <string,int> M;
vector <int> a[210];
char buf[100000];
int read()
{
    scanf("%s",buf);
    if (!M.count(buf))
    {
        int id=M.size()+1;
        a[id].clear();
        M[buf]=id;
    }
    return(M[buf]);
}
void dp(int x)
{
    for (int i=0;i<a[x].size();i++)
        dp(a[x][i]);
    f[x][0]=0,f[x][1]=g[x][0]=g[x][1]=1;
    for (int i=0;i<a[x].size();i++)
    {
        int y=a[x][i];
        f[x][0]+=f[y][1];
        g[x][0]*=g[y][1];
        f[x][1]+=f[y][0];
        g[x][1]*=g[y][0];
    }
    if (f[x][0]>f[x][1])
        f[x][1]=f[x][0],g[x][1]=g[x][0];
    else if (f[x][0]==f[x][1])
        g[x][1]+=g[x][0];
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        M.clear();
        int root=read();
        for (int i=1;i<n;i++)
        {
            int x=read(),y=read();
            a[y].push_back(x);
        }
        dp(root);
        printf("%d %s\n",f[root][1],g[root][1]==1?"Yes":"No");
    }
    return(0);
}

