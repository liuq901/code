#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int mod=1000000007;
char a[310],b[110],c[110];
int pos[26],next[310][26],f[310][110][110],g[310][110][110];
int dfs(int x,int y,int z,int m,int K)
{
    if (g[x][y][z]!=-1)
        return(g[x][y][z]);
    int &ret=g[x][y][z];
    ret=0;
    if (y==m && z==K)
        ret=1;
    else if (b[y]==c[z])
    {
        int p=next[x][b[y]-'a'];
        if (p!=-1 && f[x][y][z]==f[p+1][y+1][z+1]+1)
            ret=(ret+dfs(p+1,y+1,z+1,m,K))%mod;
    }
    else
    {
        int p;
        if (y<m)
        {
            p=next[x][b[y]-'a'];
            if (p!=-1 && f[x][y][z]==f[p+1][y+1][z]+1)
                ret=(ret+dfs(p+1,y+1,z,m,K))%mod;
        }
        if (z<K)
        {
            p=next[x][c[z]-'a'];
            if (p!=-1 && f[x][y][z]==f[p+1][y][z+1]+1)
                ret=(ret+dfs(p+1,y,z+1,m,K))%mod;
        }
    }
    return(ret);
}
void update(int i,int j,int k,int u,int v,int w,int delta)
{
    f[i][j][k]=min(f[i][j][k],f[u][v][w]+delta);
}
string getans(int x,int y,int z)
{
    if (f[x][y][z]==0)
        return("");
    for (int i=0;i<26;i++)
    {
        int u=next[x][i],v=b[y]==i+'a'?y+1:y,w=c[z]==i+'a'?z+1:z;
        if (u!=-1 && f[x][y][z]==f[u+1][v][w]+1)
            return(char(i+'a')+getans(u+1,v,w));
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s%s",b,c,a);
        int n=strlen(a),m=strlen(b),K=strlen(c);
        memset(f,63,sizeof(f));
        int inf=f[0][0][0];
        f[n][m][K]=0;
        for (int i=n-1;i>=0;i--)
            for (int j=m;j>=0;j--)
                for (int k=K;k>=0;k--)
                {
                    if (a[i]==b[j] && a[i]==c[k])
                        update(i,j,k,i+1,j+1,k+1,1);
                    if (a[i]==b[j])
                        update(i,j,k,i+1,j+1,k,1);
                    if (a[i]==c[k])
                        update(i,j,k,i+1,j,k+1,1);
                    update(i,j,k,i+1,j,k,0);
                }
        static int id=0;
        printf("Case %d: ",++id);
        if (f[0][0][0]==inf)
            printf("0\nNOT FOUND\n");
        else
        {
            memset(pos,-1,sizeof(pos));
            for (int i=n-1;i>=0;i--)
            {
                pos[a[i]-'a']=i;
                for (int j=0;j<26;j++)
                    next[i][j]=pos[j];
            }
            memset(g,-1,sizeof(g));
            printf("%d\n%s\n",dfs(0,0,0,m,K),getans(0,0,0).c_str());
        }
    }
    return(0);
}

