#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f[100010][2],g[100010][2];
int bb[100010],be[100010],eb[100010],ee[1000010];
void printF(int x,int op)
{
    string ans;
    for (int i=x;i>1;i--)
        if (!op)
        {
            ans+='B';
            if (f[i][0]==f[i-1][0]+be[i-1])
                op=0;
            else
                op=1;
        }
        else
        {
            ans+='F';
            if (f[i][1]==f[i-1][0]+bb[i-1])
                op=0;
            else
                op=1;
        }
    ans+='F';
    reverse(ans.begin(),ans.end());
    printf("%s\n",ans.c_str());
}
void printG(int x,int op)
{
    string ans;
    for (int i=x;i>1;i--)
        if (!op)
        {
            ans+='B';
            if (g[i][0]==g[i-1][0]+be[i-1])
                op=0;
            else
                op=1;
        }
        else
        {
            ans+='F';
            if (g[i][1]==g[i-1][0]+bb[i-1])
                op=0;
            else
                op=1;
        }
    ans+='B';
    reverse(ans.begin(),ans.end());
    printf("%s\n",ans.c_str());
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        ll sum=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d%d%d%d%d",&x,&bb[i],&be[i],&eb[i],&ee[i]);
            sum+=x;
        }
        f[1][1]=g[1][0]=0;
        f[1][0]=g[1][1]=1LL<<60;
        for (int i=1;i<n;i++)
        {
            f[i+1][0]=min(f[i][0]+be[i],f[i][1]+ee[i]);
            f[i+1][1]=min(f[i][0]+bb[i],f[i][1]+eb[i]);
            g[i+1][0]=min(g[i][0]+be[i],g[i][1]+ee[i]);
            g[i+1][1]=min(g[i][0]+bb[i],g[i][1]+eb[i]);
        }
        f[n][0]+=bb[n],f[n][1]+=eb[n];
        g[n][0]+=be[n],g[n][1]+=ee[n];
        ll ans=min(min(f[n][0],f[n][1]),min(g[n][0],g[n][1]));
        if (sum+ans>m)
            printf("IMPOSSIBLE\n");
        else if (ans==f[n][0])
        {
            f[n][0]-=bb[n];
            printF(n,0);
        }
        else if (ans==f[n][1])
        {
            f[n][1]-=eb[n];
            printF(n,1);
        }
        else if (ans==g[n][0])
        {
            g[n][0]-=be[n];
            printG(n,0);
        }
        else
        {
            g[n][1]-=ee[n];
            printG(n,1);
        }
    }
    return(0);
}

