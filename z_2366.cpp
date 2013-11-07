#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
char Z[210],a[2010],b[2010];
int toa[210],tob[210],mina[210],minb[210],d[210][210],f[2010][2010];
char pre[2010][2010];
map <char,int> v;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s%s",Z+1,a+1,b+1);
        int len=strlen(Z+1);
        v.clear();
        for (int i=1;i<=len;i++)
            v[Z[i]]=i;
        memset(mina,63,sizeof(mina));
        memset(minb,63,sizeof(minb));
        for (int i=1;i<=len;i++)
            for (int j=1;j<=len;j++)
            {
                scanf("%d",&d[i][j]);
                if (d[i][j]<mina[i])
                {
                    mina[i]=d[i][j];
                    toa[i]=j;
                }
                if (d[i][j]<minb[j])
                {
                    minb[j]=d[i][j];
                    tob[j]=i;
                }
            }
        int n=strlen(a+1),m=strlen(b+1);
        f[0][0]=0;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=m;j++)
            {
                if (i==0 && j==0)
                    continue;
                f[i][j]=1<<30;
                if (i>0 && f[i-1][j]+mina[v[a[i]]]<f[i][j])
                {
                    f[i][j]=f[i-1][j]+mina[v[a[i]]];
                    pre[i][j]=0;
                }
                if (j>0 && f[i][j-1]+minb[v[b[j]]]<f[i][j])
                {
                    f[i][j]=f[i][j-1]+minb[v[b[j]]];
                    pre[i][j]=1;
                }
                if (i>0 && j>0 && f[i-1][j-1]+d[v[a[i]]][v[b[j]]]<f[i][j])
                {
                    f[i][j]=f[i-1][j-1]+d[v[a[i]]][v[b[j]]];
                    pre[i][j]=2;
                }
            }
        printf("%d\n",f[n][m]);
        string ansa,ansb;
        while (n || m)
        {
            int x=n,y=m;
            if (pre[n][m]==0 || pre[n][m]==2)
                x--;
            if (pre[n][m]==1 || pre[n][m]==2)
                y--;
            if (x==n)
                ansa+=Z[tob[v[b[m]]]],ansb+=b[m];
            else if (y==m)
                ansa+=a[n],ansb+=Z[toa[v[a[n]]]];
            else
                ansa+=a[n],ansb+=b[m];
            n=x,m=y;
        }
        reverse(ansa.begin(),ansa.end());
        reverse(ansb.begin(),ansb.end());
        printf("%s\n%s\n",ansa.c_str(),ansb.c_str());
        if (T)
            printf("\n");
    }
    return(0);
}

