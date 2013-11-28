#include <cstdio>
#include <cstring>
#include <algorithm>
#define fill __fill__
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct data
{
    int l,r,u,d,x,y;
};
struct data p[236521];
int sum[325],ans[730];
char b[10][10];
inline int count(int x,int y)
{
    return(x*324+y);
}
void build()
{
    int t=-1,z[10],q[325],c[10][10],d[10][10],f[10][10];
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    memset(f,0,sizeof(f));
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
        {
            if (b[i][j]=='0')
                continue;
            int k=b[i][j]-'0';
            c[i][k]=1;
            d[j][k]=1;
            f[(i-1)/3*3+(j-1)/3+1][k]=1;
        }
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
    t=0;
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
            for (int k=1;k<=9;k++)
            {
                t++;
                if (b[i][j]!='0' && b[i][j]-'0'!=k)
                    continue;
                if (b[i][j]=='0' && (c[i][k] || d[j][k] || f[(i-1)/3*3+(j-1)/3+1][k]))
                    continue;
                z[1]=(i-1)*9+k;
                z[2]=(j-1)*9+k+81;
                z[3]=((i-1)/3*3+(j-1)/3)*9+k+162;
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
bool fill[10][10],use[100][100];
int now[10][10];
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
    int tot=0;
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
            now[i][j]=s[++tot];
}
bool dfs(int x,int y)
{
    if (x==10)
        return(true);
    if (y==10)
        return(dfs(x+1,x+2));
    if (use[x][y])
        return(dfs(x,y+1));
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
            if (now[i][j]==x && !fill[i][j])
                for (int k=0;k<4;k++)
                {
                    int x0=i+c[k][0],y0=j+c[k][1];
                    if (x0>=1 && x0<=9 && y0>=1 && y0<=9 && now[x0][y0]==y && !fill[x0][y0])
                    {
                        fill[i][j]=true;
                        fill[x0][y0]=true;
                        if (dfs(x,y+1))
                            return(true);
                        fill[i][j]=false;
                        fill[x0][y0]=false;
                    }
                }
    return(false);
}
bool check()
{
    bool ret=dfs(1,2);
    if (ret)
        for (int i=1;i<=9;i++)
        {
            for (int j=1;j<=9;j++)
                printf("%d",now[i][j]);
            printf("\n");
        }
    return(ret);
}
bool DLX()
{
    if (p[0].r==0)
    {
        print();
        return(check());
    }
    int t,mi=20000000;
    for (int i=p[0].r;i!=0;i=p[i].r)
        if (sum[p[i].y]<mi)
        {
            mi=sum[p[i].y];
            t=i;
        }
    del(t);
    for (int i=p[t].d;i!=t;i=p[i].d)
    {
        ans[++ans[0]]=p[i].x;
        for (int j=p[i].r;j!=i;j=p[j].r)
            del(p[j].y);
        if (DLX())
            return(true);
        ans[0]--;
        for (int j=p[i].l;j!=i;j=p[j].l)
            renew(p[j].y);
    }
    renew(t);
    return(false);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        memset(b,'0',sizeof(b));
        memset(use,0,sizeof(use));
        memset(fill,0,sizeof(fill));
        for (int i=1;i<=n;i++)
        {
            int x,y;
            char s1[10],s2[10];
            scanf("%d%s%d%s",&x,s1,&y,s2);
            use[min(x,y)][max(x,y)]=true;
            b[s1[0]-'A'+1][s1[1]-'0']=x+'0';
            b[s2[0]-'A'+1][s2[1]-'0']=y+'0';
            fill[s1[0]-'A'+1][s1[1]-'0']=true;
            fill[s2[0]-'A'+1][s2[1]-'0']=true;
        }
        for (int i=1;i<=9;i++)
        {
            char s[10];
            scanf("%s",s);
            b[s[0]-'A'+1][s[1]-'0']=i+'0';
            fill[s[0]-'A'+1][s[1]-'0']=true;
        }
        build();
        ans[0]=0;
        static int id=0;
        printf("Puzzle %d\n",++id);
        DLX();
    }
    return(0);
}

