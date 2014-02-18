#include <cstdio>
#include <algorithm>
using namespace std;
struct data
{
    int l,r,u,d,y;
};
data a[1000000];
int tot,p[500],sum[500],X[20],Y[20],pos[30][30];
char A[30][30],B[20][30][30];
void init(int m)
{
    for (int i=1;i<=m;i++)
    {
        a[i].l=i-1;
        a[i].r=i+1;
        p[i]=i;
        sum[i]=0;
    }
    a[0].l=m;
    a[0].r=1;
    a[m].r=0;
    tot=m;
}
int n,m,idx,R,C,cnt[30][30];
char b[30][30];
void rotate()
{
    char c[30][30];
    for (int i=1;i<=R;i++)
        for (int j=1;j<=C;j++)
            c[j][R-i+1]=b[i][j];
    swap(R,C);
    for (int i=1;i<=R;i++)
        for (int j=1;j<=C;j++)
            b[i][j]=c[i][j];
}
void work(int id,int ban)
{
    for (int i=1;i<=X[id];i++)
        for (int j=1;j<=Y[id];j++)
            b[i][j]=B[id][i][j];
    R=X[id],C=Y[id];
    for (int _=0;_<4;_++)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                bool flag=true;
                for (int k=1;k<=R;k++)
                    for (int l=1;l<=C;l++)
                    {
                        int x=i+k-1,y=j+l-1;
                        if (b[k][l]=='#' && (x<=0 || x>n || y<0 || y>m || A[x][y]=='#'))
                        {
                            flag=false;
                            goto out;
                        }
                    }
out:
                if (!flag)
                    continue;
                int now=tot+1;
                for (int k=1;k<=R;k++)
                    for (int l=1;l<=C;l++)
                    {
                        if (b[k][l]!='#')
                            continue;
                        int t=pos[i+k-1][j+l-1];
                        a[++tot].u=p[t];
                        a[p[t]].d=tot;
                        p[t]=tot;
                        a[tot].l=tot-1;
                        a[tot].r=tot+1;
                        a[tot].y=t;
                        sum[t]++;
                    }
                a[++tot].u=p[ban];
                a[p[ban]].d=tot;
                p[ban]=tot;
                a[tot].l=tot-1;
                a[tot].r=now;
                a[tot].y=ban;
                sum[ban]++;
                a[now].l=tot;
            }
        rotate();
    }
}
void build(int m)
{
    for (int i=1;i<=m;i++)
    {
        a[i].u=p[i];
        a[p[i]].d=i;
    }
}
void del(int x)
{
    a[a[x].l].r=a[x].r;
    a[a[x].r].l=a[x].l;
    for (int i=a[x].d;i!=x;i=a[i].d)
        for (int j=a[i].r;j!=i;j=a[j].r)
        {
            sum[a[j].y]--;
            a[a[j].u].d=a[j].d;
            a[a[j].d].u=a[j].u;
        }
}
void renew(int x)
{
    a[a[x].l].r=x;
    a[a[x].r].l=x;
    for (int i=a[x].u;i!=x;i=a[i].u)
        for (int j=a[i].l;j!=i;j=a[j].l)
        {
            sum[a[j].y]++;
            a[a[j].u].d=j;
            a[a[j].d].u=j;
        }
}
bool DLX()
{
    if (a[0].r==0)
        return(true);
    int k,mi=1<<30;
    for (int i=a[0].r;i!=0;i=a[i].r)
        if (sum[i]<mi)
            mi=sum[k=i];
    del(k);
    for (int i=a[k].d;i!=k;i=a[i].d)
    {
        for (int j=a[i].r;j!=i;j=a[j].r)
            del(a[j].y);
        if (DLX())
            return(true);
        for (int j=a[i].l;j!=i;j=a[j].l)
            renew(a[j].y);
    }
    renew(k);
    return(false);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        int num=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",A[i]+1);
            for (int j=1;j<=m;j++)
                if (A[i][j]=='.')
                    pos[i][j]=++num;
        }
        int K;
        scanf("%d",&K);
        for (int i=1;i<=K;i++)
        {
            scanf("%d%d",&X[i],&Y[i]);
            for (int j=1;j<=X[i];j++)
                scanf("%s",B[i][j]+1);
        }
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int N;
            scanf("%d",&N);
            init(num+N);
            for (int i=1;i<=N;i++)
            {
                int x;
                scanf("%d",&x);
                work(x,num+i);
            }
            build(num+N);
            printf("%s\n",DLX()?"YES":"NO");
        }
    }
    return(0);
}

