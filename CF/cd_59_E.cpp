#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef map <pair <int,int>,vector <int> > hash;
int a[3010][3010],d[3010][3010],pre[3010][3010],q[10000000][2];
hash M;
void print(int x,int y)
{
    if (x==0)
        return;
    print(pre[x][y],x);
    printf(" %d",y);
}
int main()
{
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][++a[x][0]]=y;
        a[y][++a[y][0]]=x;
    }
    for (int i=1;i<=K;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        M[make_pair(x,y)].push_back(z);
    }
    for (hash::iterator k=M.begin();k!=M.end();k++)
        sort(k->second.begin(),k->second.end());
    memset(d,63,sizeof(d));
    int l,r;
    q[l=r=1][0]=0,q[1][1]=1;
    d[0][1]=0;
    while (l<=r)
    {
        int p=q[l][0],x=q[l++][1];
        for (int i=1;i<=a[x][0];i++)
        {
            int y=a[x][i];
            pair <int,int> t(p,x);
            if (M.count(t) && binary_search(M[t].begin(),M[t].end(),y) || d[p][x]+1>=d[x][y])
                continue;
            pre[x][y]=p;
            d[x][y]=d[p][x]+1;
            q[++r][0]=x;
            q[r][1]=y;
        }
    }
    int k=0;
    for (int i=1;i<=n;i++)
        if (d[i][n]<d[k][n])
            k=i;
    if (k==0)
        printf("-1\n");
    else
    {
        printf("%d\n%d",d[k][n],1);
        print(k,n);
        printf("\n");
    }
    return(0);
}

