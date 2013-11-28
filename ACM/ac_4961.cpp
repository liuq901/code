#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;
pair <int,int> a[30][30];
int n,c[260],f[210][210][30];
char s[30],buf[210];
bool vis[210][210];
bool update(int &a,int b)
{
    if (b!=-1 && (a==-1 || b<a))
    {
        a=b;
        return(true);
    }
    return(false);
}
void dp(int l,int r)
{
    if (vis[l][r])
        return;
    vis[l][r]=true;
    if (l==r)
    {
        f[l][r][c[buf[l]]]=0;
        return;
    }
    for (int i=1;i<=n;i++)
        f[l][r][i]=-1;
    for (int i=l;i<r;i++)
    {
        dp(l,i);
        dp(i+1,r);
        for (int j=1;j<=n;j++)
        {
            if (f[l][i][j]==-1)
                continue;
            for (int k=1;k<=n;k++)
            {
                if (f[i+1][r][k]==-1)
                    continue;
                int to=a[j][k].second,value=a[j][k].first;
                update(f[l][r][to],f[l][i][j]+f[i+1][r][k]+value);
            }
        }
    }
}
int main()
{
    bool first=true;
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            s[i]=buf[0];
            c[s[i]]=i;
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                int x;
                char ch;
                scanf("%d-%c",&x,&ch);
                a[i][j]=make_pair(x,c[ch]);
            }
        if (!first)
            printf("\n");
        first=false;
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            scanf("%s",buf+1);
            int len=strlen(buf+1);
            memset(vis,0,sizeof(vis));
            memset(f,-1,sizeof(f));
            dp(1,len);
            int ans=-1,k;
            for (int i=1;i<=n;i++)
                if (update(ans,f[1][len][i]))
                    k=i;
            printf("%d-%c\n",ans,s[k]);
        }
    }
    return(0);
}

