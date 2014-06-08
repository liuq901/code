#include <cstdio>
#include <cstring>
const int n=36;
int pos[n][2];
unsigned one[n][n];
bool ok(int x,int y)
{
    return(x!=y && x+1!=y && x-1!=y);
}
bool check(int x,int y)
{
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            if (!ok(pos[x][i],pos[y][j]))
                return(false);
    return(true);
}
void init()
{
    int t=0;
    for (int i=1;i<=10;i++)
        for (int j=i+2;j<=10;j++)
            pos[t][0]=i,pos[t++][1]=j;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (check(i,j))
                one[i][j]++;
}
void multiply(unsigned a[][n],unsigned b[][n],unsigned c[][n])
{
    unsigned d[n][n]={0};
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<n;k++)
                d[i][j]+=a[i][k]*b[k][j];
    memcpy(c,d,sizeof(d));
}
unsigned ret[n][n],x[n][n];
void power(int m)
{
    memset(ret,0,sizeof(ret));
    for (int i=0;i<n;i++)
        ret[i][i]=1;
    memcpy(x,one,sizeof(one));
    for (;m;m>>=1)
    {
        if (m&1)
            multiply(ret,x,ret);
        multiply(x,x,x);
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%d",&m);
        power(m-1);
        unsigned ans=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                ans+=ret[i][j];
        static int id=0;
        printf("Case %d: %u\n",++id,ans);
    }
    return(0);
}

