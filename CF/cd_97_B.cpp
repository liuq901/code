#include <cstdio>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
pair <int,int> a[10010];
set <pair <int,int> > s;
void work(int l,int r)
{
    if (l==r)
        return;
    int mid=l+r>>1;
    for (int i=l;i<=r;i++)
        s.insert(make_pair(a[mid].first,a[i].second));
    work(l,mid);
    work(mid+1,r);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].first,&a[i].second);
        s.insert(a[i]);
    }
    sort(a+1,a+n+1);
    work(1,n);
    printf("%d\n",s.size());
    for (set <pair <int,int> >::iterator k=s.begin();k!=s.end();k++)
        printf("%d %d\n",k->first,k->second);
    return(0);
}

