#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int s[20],f[20][310][310];
pair <int,char> a[20];
inline void update(int &a,int b)
{
    if (a==-1 || a>b)
        a=b;
}
vector <pair <int,char> > now;
vector <char> lq;
void dfs(int i,int j,int k)
{
    if (f[i][j][k]==-1)
        return;
    if (i==0 && j==0 && k==0)
    {
        vector <pair <int,char> > ret=now;
        sort(ret.begin(),ret.end());
        vector <char> tmp;
        for (int i=0;i<ret.size();i++)
            tmp.push_back(ret[i].second);
        if (lq.empty() || tmp<lq)
            lq=tmp;
        return;
    }
    int p=s[i]-j-k,x=a[i].first;
    if (j>=x && f[i-1][j-x][k]+j==f[i][j][k])
    {
        now.push_back(make_pair(j,a[i].second));
        dfs(i-1,j-x,k);
        now.pop_back();
    }
    if (k>=x && f[i-1][j][k-x]+k==f[i][j][k])
    {
        now.push_back(make_pair(k,a[i].second));
        dfs(i-1,j,k-x);
        now.pop_back();
    }
    if (p>=x && f[i-1][j][k]+p==f[i][j][k])
    {
        now.push_back(make_pair(p,a[i].second));
        dfs(i-1,j,k);
        now.pop_back();
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
            scanf("%d",&a[i].first);
            a[i].second=i+'A'-1;
        }
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++)
            s[i]=s[i-1]+a[i].first;
        memset(f,-1,sizeof(f));
        f[0][0][0]=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<=300;j++)
                for (int k=0;k<=300;k++)
                {
                    if (f[i][j][k]==-1)
                        continue;
                    int p=s[i]-j-k,x=a[i+1].first;
                    if (j+x<=300)
                        update(f[i+1][j+x][k],f[i][j][k]+j+x);
                    if (k+x<=300)
                        update(f[i+1][j][k+x],f[i][j][k]+k+x);
                    if (p+x<=300)
                        update(f[i+1][j][k],f[i][j][k]+p+x);
                }
        int ans=0,sum;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=300;j++)
                for (int k=0;k<=300;k++)
                {
                    if (f[i][j][k]==-1)
                        continue;
                    if (i>ans)
                        ans=i,sum=f[i][j][k];
                    else if (i==ans && f[i][j][k]<sum)
                        sum=f[i][j][k];
                }
        lq.clear();
        for (int i=0;i<=300;i++)
            for (int j=0;j<=300;j++)
                if (f[ans][i][j]==sum)
                    dfs(ans,i,j);
        static int id=0;
        printf("Data set %d:",++id);
        for (int i=0;i<lq.size();i++)
            printf(" %c",lq[i]);
        printf(" %d %d\n",ans,sum);
    }
    return(0);
}

