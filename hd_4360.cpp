#include <cstdio>
#include <cstring>
typedef long long ll;
int fix[260],b[1320],a[27000][4],q[10010][2];
ll d[1320][4][2];
bool in[1320][4];
void spfa(int n)
{
    memset(d,63,sizeof(d));
    ll inf=d[0][0][0];
    int l=0,r=1;
    q[1][0]=1,q[1][1]=0;
    in[1][0]=true;
    d[1][0][0]=d[1][0][1]=0;
    bool first=true;
    while (l!=r)
    {
        l=l==10000?1:l+1;
        int x=q[l][0],p0=q[l][1],p=(p0+1)&3,num=p0==3;
        in[x][p0]=false;
        for (int i=b[x];i;i=a[i][3])
        {
            if (a[i][2]!=p0)
                continue;
            int y=a[i][0];
            if (d[x][p0][0]+a[i][1]<d[y][p][0] || d[x][p0][0]+a[i][1]==d[y][p][0] && d[x][p0][1]+num>d[y][p][1])
            {
                d[y][p][0]=d[x][p0][0]+a[i][1];
                d[y][p][1]=d[x][p0][1]+num;
                if (!in[y][p])
                {
                    in[y][p]=true;
                    r=r==10000?1:r+1;
                    q[r][0]=y;
                    q[r][1]=p;
                }
            }
        }
        if (first)
        {
            first=false;
            d[x][0][0]=d[x][0][1]=inf;
        }        
    }
    if (d[n][0][0]==inf)
        printf("Binbin you disappoint Sangsang again, damn it!\n");
    else
        printf("Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %I64d LOVE strings at last.\n",d[n][0][0],d[n][0][1]);
}
int main()
{
    fix['L']=0,fix['O']=1,fix['V']=2,fix['E']=3;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            char ch;
            scanf("%d%d%d %c",&x,&y,&z,&ch);
            a[i][0]=y,a[i][1]=z,a[i][2]=fix[ch],a[i][3]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=fix[ch],a[i+m][3]=b[y],b[y]=i+m;
        }
        static int id=0;
        printf("Case %d: ",++id);
        spfa(n);

    }
    return(0);
}

