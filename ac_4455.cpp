#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
string S,T,transform[30][2],a[30][300];
map <string,int> M[30];
ll f[30][300][300];
void read(string &s)
{
    char buf[100];
    scanf("%s",buf);
    s=buf;
}
void work(const string &s)
{
    for (int i=0;i<s.size();i++)
    {
        string tmp=s.substr(i);
        int len=tmp.size();
        if (!M[len].count(tmp))
        {
            int id=M[len].size()+1;
            M[len][tmp]=id;
            a[len][id]=tmp;
        }
    }
}
int main()
{
    while (1)
    {
        read(S);
        if (S==".")
            break;
        read(T);
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            read(transform[i][0]);
            read(transform[i][1]);
        }
        int len=S.size();
        for (int i=1;i<=len;i++)
            M[i].clear();
        work(S);
        work(T);
        for (int i=1;i<=n;i++)
        {
            work(transform[i][0]);
            work(transform[i][1]);
        }
        memset(f,63,sizeof(f));
        ll inf=f[0][0][0];
        static int id=0;
        for (int p=1;p<=len;p++)
        {
            int m=M[p].size();
            for (int i=1;i<=m;i++)
                for (int j=1;j<=m;j++)
                {
                    if (i==j)
                    {
                        f[p][i][j]=0;
                        continue;
                    }
                    for (int k=1;k<=n;k++)
                        if (transform[k][0]==a[p][i] && transform[k][1]==a[p][j])
                            f[p][i][j]=1;
                    if (p==1 || a[p][i][0]!=a[p][j][0])
                        continue;
                    int u=M[p-1][a[p][i].substr(1)];
                    int v=M[p-1][a[p][j].substr(1)];
                    f[p][i][j]=min(f[p][i][j],f[p-1][u][v]);
                }
            for (int k=1;k<=m;k++)
                for (int i=1;i<=m;i++)
                    for (int j=1;j<=m;j++)
                        f[p][i][j]=min(f[p][i][j],f[p][i][k]+f[p][k][j]);
        }
        ll ans=f[len][M[len][S]][M[len][T]];
        if (ans==inf)
            ans=-1;
        printf("Case %d: ",++id);
        if (ans==-1)
            printf("No solution\n");
        else
            printf("%lld\n",ans);
    }
    return(0);
}

