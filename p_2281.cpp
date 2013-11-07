#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const pair <int,int> nil(-1,-1);
char lq[260],a[40][40];
int step,n,m,b[40][40];
pair <int,int> begin,end;
int vis[40][40];
void update(int dep,const pair <int,int> &start,const pair <int,int> &target)
{
    if (dep<step || dep==step && (start<begin || start==begin && target<end))
        step=dep,begin=start,end=target;
}
void one()
{
    for (int i=1;i<=n;i++)
    {
        int prev=-1;
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]=='.')
                continue;
            if (prev!=-1 && a[i][j]==a[i][prev])
                update(1,make_pair(i,prev),make_pair(i,j));
            prev=j;
        }
    }
    for (int j=1;j<=m;j++)
    {
        int prev=-1;
        for (int i=1;i<=n;i++)
        {
            if (a[i][j]=='.')
                continue;
            if (prev!=-1 && a[i][j]==a[prev][j])
                update(1,make_pair(prev,j),make_pair(i,j));
            prev=i;
        }
    }
}
pair <int,int> to[40][40][4];
void two()
{
    if (step!=4)
        return;
    for (int i=0;i<=n+1;i++)
        for (int j=0;j<=m+1;j++)
            for (int k=0;k<4;k++)
                to[i][j][k]=nil;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]=='.')
                continue;
            for (int k=0;k<4;k++)
            {
                int x=i+c[k][0],y=j+c[k][1];
                if (a[x][y]=='.')
                    to[x][y][k]=make_pair(i,j);
            }
        }
    for (int i=0;i<=n+1;i++)
        for (int j=0;j<=m+1;j++)
        {
            if (a[i][j]!='.')
                continue;
            for (int k=1;k<4;k+=2)
            {
                if (to[i][j][k]==nil)
                    continue;
                int x=i+c[k][0],y=j+c[k][1];
                if (x>=0 && x<=n+1 && y>=0 && y<=m+1 && a[x][y]=='.')
                    to[x][y][k]=to[i][j][k];
            }
        }
    for (int i=n+1;i>=0;i--)
        for (int j=m+1;j>=0;j--)
        {
            if (a[i][j]!='.')
                continue;
            for (int k=0;k<4;k+=2)
            {
                if (to[i][j][k]==nil)
                    continue;
                int x=i+c[k][0],y=j+c[k][1];
                if (x>=0 && x<=n+1 && y>=0 && y<=m+1 && a[x][y]=='.')
                    to[x][y][k]=to[i][j][k];
            }
        }
    for (int i=0;i<=n+1;i++)
        for (int j=0;j<=m+1;j++)
        {
            if (a[i][j]!='.')
                continue;
            for (int k=0;k<4;k++)
            {
                if (to[i][j][k]==nil)
                    continue;
                for (int l=k+1;l<4;l++)
                {
                    if (to[i][j][l]==nil)
                        continue;
                    if (a[to[i][j][k].first][to[i][j][k].second]==a[to[i][j][l].first][to[i][j][l].second])
                        update(2,min(to[i][j][k],to[i][j][l]),max(to[i][j][k],to[i][j][l]));
                }
            }
        }
}
void three()
{
    if (step!=4)
        return;
    pair <int,int> lq[26];
    for (int i=0;i<=n+1;i++)
    {
        for (int j=0;j<26;j++)
            lq[j]=nil;
        for (int j=0;j<=m+1;j++)
        {
            if (a[i][j]!='.')
            {
                for (int k=0;k<26;k++)
                    lq[k]=nil;
                continue;
            }
            for (int k=0;k<2;k++)
            {
                if (to[i][j][k]==nil)
                    continue;
                int kind=a[to[i][j][k].first][to[i][j][k].second]-'A';
                if (lq[kind]!=nil)
                {
                    update(3,min(lq[kind],to[i][j][k]),max(lq[kind],to[i][j][k]));
                    lq[kind]=min(lq[kind],to[i][j][k]);
                }
                else
                    lq[kind]=to[i][j][k];
            }
        }
    }
    for (int j=0;j<=m+1;j++)
    {
        for (int i=0;i<26;i++)
            lq[i]=nil;
        for (int i=0;i<=n+1;i++)
        {
            if (a[i][j]!='.')
            {
                for (int k=0;k<26;k++)
                    lq[k]=nil;
                continue;
            }
            for (int k=2;k<4;k++)
            {
                if (to[i][j][k]==nil)
                    continue;
                int kind=a[to[i][j][k].first][to[i][j][k].second]-'A';
                if (lq[kind]!=nil)
                {
                    update(3,min(lq[kind],to[i][j][k]),max(lq[kind],to[i][j][k]));
                    lq[kind]=min(lq[kind],to[i][j][k]);
                }
                else
                    lq[kind]=to[i][j][k];
            }
        }
    }
}
void move()
{
    memset(vis,0,sizeof(vis));
    int cnt=0;
    while (1)
    {
        cnt++;
        bool flag=false;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]=='.' || vis[i][j]==cnt || b[i][j]==4)
                    continue;
                int op=b[i][j],x=i+c[op][0],y=j+c[op][1];
                if (x>0 && x<=n && y>0 && y<=m && a[x][y]=='.')
                {
                    flag=true;
                    swap(a[i][j],a[x][y]);
                    swap(b[i][j],b[x][y]);
                    vis[x][y]=cnt;
                }
            }
        if (!flag)
            break;
    }
}
int main()
{
    lq['U']=0,lq['D']=1,lq['L']=2,lq['R']=3,lq['S']=4;
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(a,'.',sizeof(a));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                char buf[10];
                scanf("%s",buf);
                a[i][j]=buf[0];
                b[i][j]=lq[buf[1]];
            }
        while (1)
        {
            step=4;
            one();
            two();
            three();
            if (step==4)
                break;
            a[begin.first][begin.second]='.';
            a[end.first][end.second]='.';
            move();
        }
        static int id=0;
        printf("Case %d\n",++id);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
    }
    return(0);
}

