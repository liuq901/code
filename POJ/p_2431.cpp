#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
priority_queue <int> q;
pair <int,int> a[10010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    int L,now;
    scanf("%d%d",&L,&now);
    for (int i=1;i<=n;i++)
        a[i].first=L-a[i].first;
    a[++n]=make_pair(L,0);
    sort(a+1,a+n+1);
    a[0].first=0;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int len=a[i].first-a[i-1].first;
        while (now<len)
        {
            if (q.empty())
            {
                printf("-1\n");
                goto last;
            }
            now+=q.top();
            q.pop();
            ans++;
        }
        q.push(a[i].second);
        now-=len;
    }
    printf("%d\n",ans);
last:
    return(0);
}

