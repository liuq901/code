#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
pair <pair <int,int>,int> a[50010];
map <int,pair <int,int> > f,g,h,pos;
int ans[50010],pre[50010],to[50010],tmp[50010];
int main()
{
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].first.second,&a[i].first.first);
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    f[0]=make_pair(0,0);
    g[0]=make_pair(0,0);
    h[0]=make_pair(0,0);
    memset(ans,-63,sizeof(ans));
    ans[0]=0;
    for (int i=1,j;i<=n;i=j)
    {
        for (j=i;j<=n && a[i].first.first==a[j].first.first;j++)
        {
            int x=a[j].first.second,y=a[j].first.first;
            if (f.count(x) && f[x].first+1>ans[j])
            {
                ans[j]=f[x].first+1;
                pre[j]=f[x].second;
            }
            if (g.count(x+y) && g[x+y].first+1>ans[j])
            {
                ans[j]=g[x+y].first+1;
                pre[j]=g[x+y].second;
            }
            if (h.count(x-y) && h[x-y].first+1>ans[j])
            {
                ans[j]=h[x-y].first+1;
                pre[j]=h[x-y].second;
            }
        }
        for (int k=i;k<j;k++)
            tmp[k]=ans[k];
        int now=i;
        for (int k=i+1;k<j;k++)
        {
            if (tmp[now]+k-i>ans[k])
            {
                ans[k]=tmp[now]+k-i;
                to[k]=-now;
            }
            if (tmp[k]>tmp[now])
                now=k;
        }
        now=j-1;
        for (int k=j-2;k>=i;k--)
        {
            if (tmp[now]+j-k-1>ans[k])
            {
                ans[k]=tmp[now]+j-k-1;
                to[k]=now;
            }
            if (tmp[k]>tmp[now])
                now=k;
        }
        pos[a[i].first.first]=make_pair(i,j);
        for (int k=i;k<j;k++)
        {
            int x=a[k].first.second,y=a[k].first.first;
            f[x]=make_pair(ans[k],k);
            g[x+y]=make_pair(ans[k],k);
            h[x-y]=make_pair(ans[k],k);
        }
    }
    int best=0;
    for (int i=1;i<=n;i++)
        if (ans[i]>ans[best])
            best=i;
    printf("%d\n",ans[best]);
    vector <int> tmp;
    for (int i=best;i;i=pre[i])
    {
        tmp.push_back(i);
        if (to[i]==0)
            continue;
        int l=pos[a[i].first.first].first,r=pos[a[i].first.first].second;
        if (to[i]<0)
        {
            to[i]=-to[i];
            for (int j=i-1;j>to[i];j--)
                tmp.push_back(j);
            for (int j=l;j<=to[i];j++)
                tmp.push_back(j);
        }
        else
        {
            for (int j=i+1;j<to[i];j++)
                tmp.push_back(j);
            for (int j=r-1;j>=to[i];j--)
                tmp.push_back(j);
        }
        i=to[i];
    }
    reverse(tmp.begin(),tmp.end());
    for (int i=0;i<tmp.size();i++)
    {
        if (i)
            printf(" ");
        printf("%d",a[tmp[i]].second);
    }
    printf("\n");
    return(0);
}

