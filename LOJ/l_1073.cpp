#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string s[20];
bool flag[20];
int w[20][20],f[32770][20],pre[32770][20],now[32770][20],pos[32770][20];
int calc(const string &s,const string &t)
{
    for (int i=0;i<s.size();i++)
        if (s.substr(i)==t.substr(0,s.size()-i))
            return(i);
    return(s.size());
}
void print(int x,int y,int start)
{
    printf("%s",s[y].substr(start).c_str());
    if (pre[x][y])
    {
        int z=pre[x][y];
        print(x^1<<y-1,z,s[y].size()-w[y][z]);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            char buf[110];
            scanf("%s",buf);
            s[i]=buf;
        }
        sort(s+1,s+n+1);
        memset(flag,0,sizeof(flag));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (s[i].find(s[j])!=string::npos && (s[i]!=s[j] || i<j))
                    flag[j]=true;
        int m=0;
        for (int i=1;i<=n;i++)
            if (!flag[i])
                s[++m]=s[i];
        n=m;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (i!=j)
                    w[i][j]=calc(s[i],s[j]);
        memset(f,63,sizeof(f));
        int inf=f[0][0];
        for (int i=1;i<=n;i++)
            f[1<<i-1][i]=s[i].size();
        for (int i=0;i<1<<n;i++)
            for (int j=1;j<=n;j++)
            {
                if (f[i][j]==inf)
                    continue;
                for (int k=1;k<=n;k++)
                {
                    if (i>>k-1&1)
                        continue;
                    if (f[i][j]+w[k][j]<f[i|1<<k-1][k] || f[i][j]+w[k][j]==f[i|1<<k-1][k] && s[j].substr(s[k].size()-w[k][j])<s[pre[i|1<<k-1][k]].substr(pos[i|1<<k-1][k]))
                    {
                        f[i|1<<k-1][k]=f[i][j]+w[k][j];
                        pre[i|1<<k-1][k]=j;
                        pos[i|1<<k-1][k]=s[k].size()-w[k][j];
                    }
                }
            }
        int ans=1;
        for (int i=1;i<=n;i++)
            if (f[(1<<n)-1][i]<f[(1<<n)-1][ans])
                ans=i;
        static int id=0;
        printf("Case %d: ",++id);
        print((1<<n)-1,ans,0);
        printf("\n");
    }
    return(0);
}

