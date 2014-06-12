#include <cstdio>
#include <cstring>
typedef long long ll;
const int mod=1000000007,N=93;
int l[19],r[19],way[19][3];
void prepare()
{
    l[0]=2,r[0]=3,way[0][0]=5,way[0][1]=4,way[0][2]=3;
    l[1]=1,r[1]=3,way[1][0]=8,way[1][1]=7,way[1][2]=4;
    l[2]=1,r[2]=4,way[2][0]=12,way[2][1]=8,way[2][2]=4;
    l[3]=1,r[3]=3,way[3][0]=8,way[3][1]=4,way[3][2]=3;
    l[4]=2,r[4]=4,way[4][0]=9,way[4][1]=5,way[4][2]=4;
    l[5]=2,r[5]=4,way[5][0]=5,way[5][1]=4,way[5][2]=1;
    l[6]=1,r[6]=3,way[6][0]=7,way[6][1]=4,way[6][2]=3;
    l[7]=1,r[7]=2,way[7][0]=4,way[7][1]=3,way[7][2]=2;
    l[8]=3,r[8]=4,way[8][0]=6,way[8][1]=2,way[8][2]=1;
    l[9]=2,r[9]=4,way[9][0]=9,way[9][1]=5,way[9][2]=1;
    l[10]=2,r[10]=4,way[10][0]=8,way[10][1]=4,way[10][2]=1;
    l[11]=2,r[11]=4,way[11][0]=8,way[11][1]=5,way[11][2]=4;
    l[12]=2,r[12]=3,way[12][0]=4,way[12][1]=3,way[12][2]=1;
    l[13]=3,r[13]=4,way[13][0]=5,way[13][1]=2,way[13][2]=1;
    l[14]=2,r[14]=4,way[14][0]=9,way[14][1]=8,way[14][2]=4;
    l[15]=3,r[15]=4,way[15][0]=6,way[15][1]=5,way[15][2]=1;
    l[16]=3,r[16]=4,way[16][0]=4,way[16][1]=2,way[16][2]=1;
    l[17]=3,r[17]=4,way[17][0]=6,way[17][1]=5,way[17][2]=4;
    l[18]=4,r[18]=4,way[18][0]=3,way[18][1]=2,way[18][2]=1;
}
int get(int state,int pos,int id)
{
    if (pos<l[id] || pos>r[id])
        return(-1);
    pos+=11;
    if (state>>pos&1)
        return(-1);
    state|=1<<pos;
    for (int i=0;i<3;i++)
    {
        int t=pos-way[id][i];
        if (state>>t&1)
            return(-1);
        state|=1<<t;
    }
    return(state);
}
int lq[N][N];
char a[1<<12][1<<12];
bool hehe[1<<12];
void dfs(int id,int pos,int state)
{
    if (pos==5)
    {
        if ((state&15)==15)
        {
            hehe[id]=true;
            a[id][state>>4]++;
        }
        return;
    }
    dfs(id,pos+1,state);
    for (int i=0;i<19;i++)
    {
        int tmp=get(state,pos,i);
        if (tmp!=-1)
            dfs(id,pos+1,tmp);
    }
}
bool ok[1<<12];
void floodfill(int x)
{
    ok[x]=true;
    for (int i=0;i<1<<12;i++)
        if (a[x][i] && !ok[i])
            floodfill(i);
}
int pos[1<<12];
void init()
{
    prepare();
    for (int i=0;i<1<<12;i++)
        dfs(i,1,i);
    floodfill((1<<12)-1);
    int cnt=0;
    memset(pos,-1,sizeof(pos));
    for (int i=0;i<1<<12;i++)
        if (ok[i] && hehe[i])
            pos[i]=cnt++;
    for (int i=0;i<1<<12;i++)
    {
        if (pos[i]==-1)
            continue;
        for (int j=0;j<1<<12;j++)
            if (pos[j]!=-1)
                lq[pos[i]][pos[j]]=a[i][j];
    }
}
void multiply(int a[][N],int b[][N],int c[][N])
{
    int d[N][N]={0};
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            for (int k=0;k<N;k++)
                d[i][j]=(d[i][j]+ll(a[i][k])*b[k][j])%mod;
    memcpy(c,d,sizeof(d));
}
int x[N][N],ret[N][N];
void power(int n)
{
    memset(ret,0,sizeof(ret));
    for (int i=0;i<N;i++)
        ret[i][i]=1;
    memcpy(x,lq,sizeof(lq));
    for (;n;n>>=1)
    {
        if (n&1)
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
        int n;
        scanf("%d",&n);
        power(n);
        static int id=0;
        printf("Case %d: %d\n",++id,ret[N-1][N-1]);
    }
    return(0);
}

