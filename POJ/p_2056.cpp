#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool f[210][210];
char a[210][210];
int d[210][210];
queue <pair <int,int> > q;
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                if (a[i][j]=='S' || a[i][j]=='B' && a[i][j-1]=='S')
                    f[i][j]=true;
            }
        memset(d,-1,sizeof(d));
        for (int i=1;i<=m;i++)
            if (f[1][i])
            {
                d[1][i]=1;
                q.push(make_pair(1,i));
            }
        while (!q.empty())
        {
            int x0=q.front().first,y0=q.front().second;
            q.pop();
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (f[x][y] && d[x][y]==-1)
                {
                    d[x][y]=d[x0][y0]+1;
                    q.push(make_pair(x,y));
                }
            }
        }
        int ans=1<<30;
        for (int i=1;i<=m;i++)
            if (d[n][i]!=-1)
                ans=min(ans,d[n][i]);
        printf("%d\n",ans);
    }
    return(0);
}

