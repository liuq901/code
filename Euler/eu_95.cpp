#include <cstdio>
#include <algorithm>
using namespace std;
bool flag[1000010];
int calc(int x)
{
    if (x==1)
        return(1);
    int ret=0;
    for (int i=1;i*i<=x;i++)
    {
        if (x%i!=0)
            continue;
        ret+=i;
        if (i!=1 && i*i!=x)
            ret+=x/i;
    }
    return(ret);
}
int vis[1000010];
int main()
{
    int ma=0,ans,n=1000000,now=0;
    for (int i=1;i<=n;i++)
    {
        if (vis[i])
            continue;
        now++;
        for (int j=i;;j=calc(j))
        {
            if (j>n)
                break;
            if (vis[j])
            {
                if (vis[j]==now && !flag[j])
                {
                    int cnt=1,mi=j;
                    flag[j]=true;
                    for (int k=calc(j);k!=j;k=calc(k))
                    {
                        flag[k]=true;
                        mi=min(mi,k);
                        cnt++;
                    }
                    if (cnt>ma)
                    {
                        ma=cnt;
                        ans=mi;
                    }
                }
                break;
            }
            vis[j]=now;
        }
    }
    printf("%d\n",ans);
    return(0);
}

