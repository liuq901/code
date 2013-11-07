#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n=15,m,e[110][2],f[66000],pre[66000];
bool adj[20][20],ok[66000];
bool check(int state)
{
    for (int i=0;i<n;i++)
    {
        if (!(state>>i&1))
            continue;
        for (int j=i+1;j<n;j++)
        {
            if (!(state>>j&1))
                continue;
            if (adj[i][j])
                return(false);
        }
    }
    return(true);
}
int p[20];
void calc(int state,int step)
{
    if (state==0)
        return;
    int tmp=state^pre[state];
    for (int i=0;i<n;i++)
        if (tmp>>i&1)
            p[i]=step;
    calc(pre[state],step+1);
}
int main()
{
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        char s1[10],s2[10];
        scanf("%s%s",s1,s2);
        int x=s1[0]-'L',y=s2[0]-'L';
        e[i][0]=x,e[i][1]=y;
        adj[x][y]=adj[y][x]=true;
    }
    int limit=1<<n;
    memset(f,63,sizeof(f));
    for (int i=0;i<limit;i++)
        ok[i]=check(i);
    for (int i=0;i<limit;i++)
    {
        if (ok[i])
        {
            f[i]=0;
            pre[i]=0;
            continue;
        }
        for (int j=i;j;j=i&j-1)
            if (ok[i^j] && f[j]+1<f[i])
            {
                f[i]=min(f[i],f[j]+1);
                pre[i]=j;
            }
    }
    printf("%d\n",f[limit-1]-1);
    calc(limit-1,0);
    for (int i=1;i<=m;i++)
    {
        int x=e[i][0],y=e[i][1];
        if (p[x]>p[y])
            swap(x,y);
        printf("%c %c\n",x+'L',y+'L');
    }
    return(0);
}

