#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
int f[1010];
pair <int,int> a[1010];
inline bool cmp(const pair <int,int> &a,const pair <int,int> &b)
{
    return(a.first+a.second<b.first+b.second);
}
int main()
{
    int n,m,K;
    scanf("%d%d%d",&n,&m,&K);
    for (int i=1;i<=K;i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+K+1,cmp);
    int ans=0;
    for (int i=1;i<=K;i++)
    {
        f[i]=1;
        for (int j=1;j<i;j++)
            if (a[j].first<a[i].first && a[j].second<a[i].second)
                f[i]=max(f[i],f[j]+1);
        ans=max(ans,f[i]);
    }
    printf("%.0f\n",100.0*(n+m-ans*(2-sqrt(2.0))));
    return(0);
}

