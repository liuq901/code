#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const int d[4]={16,32,64,128};
struct data
{
    int l,r,u,d,x,y;
};
data p[240000];
int all,q[330],sum[330],ans[730],tmp[730],a[10][10],belong[10][10];
bool go[10][10][4];
void dfs(int x0,int y0,int v)
{
    belong[x0][y0]=v;
    for (int i=0;i<4;i++)
    {
        if (!go[x0][y0][i])
            continue;
        int x=x0+c[i][0],y=y0+c[i][1];
        if (!belong[x][y])
            dfs(x,y,v);
    }
}
int count(int x,int y)
{
    return(x*324+y);
}
void build()
{
    memset(belong,0,sizeof(belong));
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
            if (!belong[i][j])
                dfs(i,j,++belong[0][0]);
    for (int i=1;i<=324;i++)
    {
        p[i].l=i-1;
        p[i].r=i+1;
        sum[i]=0;
        p[i].x=0;
        p[i].y=i;
        q[i]=i;
    }
    p[0].r=1;
    p[0].l=324;
    p[324].r=0;
    int t=0;
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
            for (int k=1;k<=9;k++)
            {
                t++;
                if (a[i][j]!=0 && a[i][j]!=k)
                    continue;
                int z[10];
                z[1]=(i-1)*9+k;
                z[2]=(j-1)*9+k+81;
                z[3]=(belong[i][j]-1)*9+k+162;
                z[4]=(i-1)*9+j+243;
                for (int l=1;l<=4;l++)
                {
                    sum[z[l]]++;
                    int tmp=count(t,z[l]);
                    p[tmp].x=t;
                    p[tmp].y=z[l];
                    if (l!=1)
                    {
                        p[tmp].l=count(t,z[l-1]);
                        p[count(t,z[l-1])].r=tmp;
                    }
                    p[tmp].u=q[z[l]];
                    p[q[z[l]]].d=tmp;
                    q[z[l]]=tmp;
                }
                p[count(t,z[1])].l=count(t,z[4]);
                p[count(t,z[4])].r=count(t,z[1]);
            }
    for (int i=1;i<=324;i++)
    {
        p[i].u=q[i];
        p[q[i]].d=i;
    }
}
void del(int t)
{
    p[p[t].r].l=p[t].l;
    p[p[t].l].r=p[t].r;
    for (int i=p[t].d;i!=t;i=p[i].d)
        for (int j=p[i].r;j!=i;j=p[j].r)
        {
            sum[p[j].y]--;
            p[p[j].u].d=p[j].d;
            p[p[j].d].u=p[j].u;
        }
}
void renew(int t)
{
    p[p[t].r].l=t;
    p[p[t].l].r=t;
    for (int i=p[t].u;i!=t;i=p[i].u)
        for (int j=p[i].l;j!=i;j=p[j].l)
        {
            sum[p[j].y]++;
            p[p[j].u].d=j;
            p[p[j].d].u=j;
        }
}
void print()
{
    int s[90];
    for (int i=1;i<=ans[0];i++)
    {
        int x=(ans[i]-1)/9;
        int y=ans[i]%9;
        if (y==0)
            y=9;
        s[x+1]=y;
    }
    for (int i=1;i<=81;i++)
    {
        printf("%d",s[i]);
        if (i%9==0)
            printf("\n");
    }
}
void search()
{
    if (p[0].r==0)
    {
        all++;
        memcpy(ans,tmp,sizeof(tmp));
        return;
    }
    int mi=1<<30,t;
    for (int i=p[0].r;i;i=p[i].r)
        if (sum[p[i].y]<=mi)
        {
            mi=sum[p[i].y];
            t=i;
        }
    del(t);
    for (int i=p[t].d;i!=t;i=p[i].d)
    {
        tmp[++tmp[0]]=p[i].x;
        for (int j=p[i].r;j!=i;j=p[j].r)
            del(p[j].y);
        search();
        if (all==2)
            return;
        tmp[0]--;
        for (int j=p[i].l;j!=i;j=p[j].l)
            renew(p[j].y);
    }
    renew(t);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=9;i++)
            for (int j=1;j<=9;j++)
            {
                scanf("%d",&a[i][j]);
                for (int k=0;k<4;k++)
                {
                    go[i][j][k]=true;
                    if ((a[i][j]&d[k])==d[k])
                    {
                        go[i][j][k]=false;
                        a[i][j]-=d[k];
                    }
                }
            }
        build();
        all=0;
        tmp[0]=0;
        search();
        static int id=0;
        printf("Case %d:\n",++id);
        if (all==0)
            printf("No solution\n");
        else if (all==2)
            printf("Multiple Solutions\n");
        else
            print();
    }
    return(0);
}

