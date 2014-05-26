#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;
pair <int,int> man[510],woman[510];
bool vis[510],a[510][510];
int b[510];
bool hungary(int x,int m)
{
    if (x==0)
        return(true);
    for (int y=1;y<=m;y++)
    {
        if (vis[y] || !a[x][y])
            continue;
        vis[y]=true;
        if (hungary(b[y],m))
        {
            b[y]=x;
            return(true);
        }
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int N;
        scanf("%*d%*d%d",&N);
        int n=0,m=0;
        for (int i=1;i<=N;i++)
        {
            char s1[10],s2[10];
            int x,y;
            scanf(" %[MF]%d %[MF]%d",s1,&x,s2,&y);
            if (s1[0]=='M')
                man[++n]=make_pair(x,y);
            else
                woman[++m]=make_pair(x,y);
        }
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (man[i].first==woman[j].second || man[i].second==woman[j].first)
                    a[i][j]=true;
        memset(b,0,sizeof(b));
        int ans=n+m;
        for (int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            ans-=hungary(i,m);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

