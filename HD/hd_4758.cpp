#include <cstdio>
#include <cstring>
const int mod=1000000007;
typedef long long ll;
struct trie
{
    int value,father,suffix,state,son[2];
};
trie a[210];
int tot;
int node(int x,int fa)
{
    tot++;
    a[tot].value=x;
    a[tot].father=fa;
    a[tot].state=a[tot].son[0]=a[tot].son[1]=0;
    return(tot);
}
int child(int x,int value)
{
    if (a[x].son[value])
        return(a[x].son[value]);
    if (x==1)
        return(1);
    return(child(a[x].suffix,value));
}
int q[210];
void build()
{
    int l,r;
    q[l=r=1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=0;i<2;i++)
        {
            if (!a[x].son[i])
                continue;
            q[++r]=a[x].son[i];
        }
    }
    for (int i=1;i<=tot;i++)
    {
        int x=q[i];
        if (x==1 || a[x].father==1)
            a[x].suffix=1;
        else
            a[x].suffix=child(a[a[x].father].suffix,a[x].value);
        a[x].state|=a[a[x].suffix].state;
    }
}
char buf[110];
int c[210][2],f[2][110][210][4];
inline void update(int &a,int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        tot=0;
        tot=node(0,1);
        for (int i=1;i<=2;i++)
        {
            scanf("%s",buf);
            int now=1,len=strlen(buf);
            for (int j=0;j<len;j++)
            {
                int here=buf[j]=='D';
                if (!a[now].son[here])
                    a[now].son[here]=node(here,now);
                now=a[now].son[here];
            }
            a[now].state|=i;
        }
        build();
        for (int i=1;i<=tot;i++)
            for (int j=0;j<2;j++)
                c[i][j]=child(i,j);
        memset(f,0,sizeof(f));
        f[0][0][1][0]=1;
        int ans=0;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++)
                for (int k=1;k<=tot;k++)
                    for (int l=0;l<4;l++)
                    {
                        if (i<n)
                        {
                            int x=c[k][0];
                            update(f[i+1&1][j][x][l|a[x].state],f[i&1][j][k][l]);
                        }
                        if (j<m)
                        {
                            int x=c[k][1];
                            update(f[i&1][j+1][x][l|a[x].state],f[i&1][j][k][l]);
                        }
                        if (i==n && j==m && l==3)
                            update(ans,f[i&1][j][k][3]);
                        f[i&1][j][k][l]=0;
                    }
        printf("%d\n",ans);
    }
    return(0);
}

