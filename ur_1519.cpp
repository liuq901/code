#include <cstdio>
#define N 1600000
typedef long long ll;
int n,m,dep,three[15],q[2][N],cnt[N];
ll f[2][N];
char a[20][20];
inline int get(int state,int x)
{
    return(state/three[x]%3);
}
inline void update(int now,int old,int u,int v)
{
    if (cnt[now]==dep)
        f[u][now]+=f[v][old];
    else
    {
        cnt[now]=dep;
        f[u][now]=f[v][old];
        q[u][++q[u][0]]=now;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%s",a[i]);
    int x0,y0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (a[i][j]=='.')
                x0=i,y0=j;
    three[0]=1;
    for (int i=1;i<=14;i++)
        three[i]=three[i-1]*3;
    int x=0,y=0;
    ll ans=0;
    q[0][0]=1,q[0][1]=0,f[0][0]=1;
    while (1)
    {
        dep++;
        int u=dep&1,v=1-u;
        q[u][0]=0;
        for (int i=1;i<=q[v][0];i++)
        {
            int old=q[v][i],p=get(old,y),q=get(old,y+1);
            if (a[x][y]=='*')
            {
                if (p==0 && q==0)
                    update(old,old,u,v);
                continue;
            }
            if (p==0 && q==0)
            {
                int now=old+three[y]+three[y+1]*2;
                update(now,old,u,v);
            }
            else if (p==0)
            {
                update(old,old,u,v);
                int now=old+three[y]*q-three[y+1]*q;
                update(now,old,u,v);
            }
            else if (q==0)
            {
                update(old,old,u,v);
                int now=old-three[y]*p+three[y+1]*p;
                update(now,old,u,v);
            }
            else
            {
                int now=old-three[y]*p-three[y+1]*q;
                if (p==1 && q==2 && (x0!=x || y0!=y))
                    continue;
                if (p==1 && q==1)
                {
                    int tot=0;
                    for (int j=y+2;j<=m;j++)
                    {
                        int t=get(old,j);
                        if (t==1)
                            tot++;
                        if (t==2)
                            tot--;
                        if (tot==-1)
                        {
                            now-=three[j];
                            break;
                        }
                    }
                }
                if (p==2 && q==2)
                {
                    int tot=0;
                    for (int j=y-1;j>=0;j--)
                    {
                        int t=get(old,j);
                        if (t==2)
                            tot++;
                        if (t==1)
                            tot--;
                        if (tot==-1)
                        {
                            now+=three[j];
                            break;
                        }
                    }
                }
                update(now,old,u,v);
            }
        }
        y++;
        if (y==m)
        {
            x++;
            y=0;
            dep++;
            q[v][0]=0;
            for (int i=1;i<=q[u][0];i++)
            {
                int old=q[u][i];
                if (get(old,m)!=0)
                    continue;
                int now=old%three[m]*3;
                update(now,old,v,u);
            }
        }
        if (x==n)
        {
            for (int i=1;i<=q[u][0];i++)
            {
                int now=q[u][i];
                if (now==0)
                    ans+=f[u][now];
            }
            break;
        }
    }
    printf("%lld\n",ans);
    return(0);
}

