#include <cstring>
#include <vector>
#include <string>
using namespace std;
struct SafeReturn
{
    int b[60],a[60][60],d[60][60];
    bool vis[60],link[60][60];
    int minRisk(int N,vector <string> streets)
    {
        int n=streets.size();
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            {
                if (streets[i][j]=='-')
                    a[i][j]=1<<20;
                else
                    a[i][j]=streets[i][j]-'0';
                d[i][j]=a[i][j];
            }
        for (int k=0;k<n;k++)
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        memset(link,0,sizeof(link));
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                if (d[0][i]+d[i][j]==d[0][j])
                    link[i][j]=true;
        int ans=N;
        memset(b,0,sizeof(b));
        for (int i=1;i<=N;i++)
        {
            memset(vis,0,sizeof(vis));
            ans-=find(i,N);
        }
        return(ans);
    }
    bool find(int x,int N)
    {
        if (!x)
            return(true);
        for (int i=1;i<=N;i++)
        {
            if (!link[x][i] || vis[i])
                continue;
            vis[i]=true;
            if (find(b[i],N))
            {
                b[i]=x;
                return(true);
            }
        }
        return(false);
    }
};
int main(){}

