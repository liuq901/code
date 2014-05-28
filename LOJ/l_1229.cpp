#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int vis[210],SG[210];
inline int sg(int x)
{
    if (x<=0)
        return(0);
    return(SG[x]);
}
void init()
{
    const int n=200;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
            vis[sg(j-3)^sg(i-j-2)]=i;
        for (int j=0;;j++)
            if (vis[j]!=i)
            {
                SG[i]=j;
                break;
            }
    }
}
char a[210];
bool check(int n)
{
    for (int i=1;i<=n-2;i++)
        if (a[i]=='X' && a[i+1]=='X' && a[i+2]=='X')
            return(true);
    for (int i=1;i<=n-1;i++)
        if (a[i]=='X' && a[i+1]=='X')
            return(false);
    for (int i=1;i<=n-2;i++)
        if (a[i]=='X' && a[i+2]=='X')
            return(false);
    int ans=0,now=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]!='X')
            continue;
        if (now==0)
            ans^=sg(i-now-3);
        else
            ans^=sg(i-now-5);
        now=i;
    }
    ans^=sg(n-now-2);
    return(ans==0);
}
bool ans[210];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a+1);
        int n=strlen(a+1);
        memset(ans,0,sizeof(ans));
        for (int i=1;i<=n;i++)
        {
            if (a[i]=='X')
                continue;
            a[i]='X';
            if (check(n))
                ans[i]=true;
            a[i]='.';
        }
        static int id=0;
        printf("Case %d:",++id);
        if (count(ans+1,ans+n+1,true)==0)
            printf(" 0\n");
        else
        {
            for (int i=1;i<=n;i++)
                if (ans[i])
                    printf(" %d",i);
            printf("\n");
        }
    }
    return(0);
}

