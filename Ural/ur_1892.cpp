#include <cstdio>
#include <queue>
using namespace std;
queue <int> Q1,Q2;
int a[60],b[60],ans1[60],ans2[60],t[10][10];
int to(int h,int m,int s)
{
    return(h*3600+m*60+s);
}
int main()
{
    for (int i=0;i<=1;i++)
        for (int j=0;j<=1;j++)
            scanf("%d",&t[i][j]);
    int n,m;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d:%d:%d",&x,&y,&z);
        a[i]=to(x,y,z);
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d:%d:%d",&x,&y,&z);
        b[i]=to(x,y,z);
    }
    int u=1,v=1,now=to(6,0,0),ago=0,type=0;
    while (u<=n || v<=m || !Q1.empty() || !Q2.empty())
    {
        if (u<=n && a[u]==now)
            Q1.push(u++);
        if (v<=m && b[v]==now)
            Q2.push(v++);
        if (!Q1.empty() && Q2.empty() && now-ago>=t[type][0])
        {
            ago=ans1[Q1.front()]=now;
            type=0;
            Q1.pop();
        }
        if (!Q2.empty() && now-ago>=t[type][1])
        {
            ago=ans2[Q2.front()]=now;
            type=1;
            Q2.pop();
        }
        now++;
    }
    for (int i=1;i<=n;i++)
    {
        int x=ans1[i];
        printf("%02d:%02d:%02d\n",x/3600,x%3600/60,x%60);
    }
    for (int i=1;i<=m;i++)
    {
        int x=ans2[i];
        printf("%02d:%02d:%02d\n",x/3600,x%3600/60,x%60);
    }
    return(0);
}

