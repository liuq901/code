#include <cstdio>
#include <vector>
using namespace std;
int a[100010],vis[100010];
vector <int> ans;
int calc(int x)
{
    int ret=0;
    while (x)
    {
        ret+=x%10;
        x/=10;
    }
    return(ret);
}
bool calc(int x,int limit)
{
    if (vis[x]!=-1)
        return(vis[x]);
    vis[x]=0;
    for (int i=limit;i;i--)
        if (x>=a[i] && calc(x-a[i],i-1))
        {
            vis[x]=1;
            ans.push_back(i);
            break;
        }
    return(vis[x]);
}
int main()
{
    for (int i=1;i<100000;i++)
    {
        a[i]=calc(i);
        vis[i]=-1;
    }
    int n;
    scanf("%d",&n);
    vis[0]=1;
    if (calc(n,99999))
    {
        printf("%d\n",ans.size());
        for (int i=0;i<ans.size();i++)
            printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    else
        printf("-1\n");
    return(0);
}

