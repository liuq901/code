#include <cstdio>
#include <cstring>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
map <int,int> s;
pair <int,int> a[1010];
int b[1010];
bool check(int x0,int y0,int y1,int y2,int id)
{
    int x1=a[id].first,x2=a[id].second;
    x2-=x1,y2-=y1,x0-=x1,y0-=y1;
    return(x2*y0-x0*y2>0);
}
int main()
{
    while (1)
    {
        int n,m,x1,y1,x2,y2;
        scanf("%d",&n);
        if (!n)
            break;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].first,&a[i].second);
        a[++n]=make_pair(x1,x1);
        a[++n]=make_pair(x2,x2);
        sort(a+1,a+n+1);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x0,y0;
            scanf("%d%d",&x0,&y0);
            int l=1,r=n,ans;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (check(x0,y0,y1,y2,mid))
                    ans=mid,l=mid+1;
                else
                    r=mid-1;
            }
            b[ans]++;
        }
        s.clear();
        for (int i=1;i<=n;i++)
            if (b[i])
                s[b[i]]++;
        printf("Box\n");
        for (map <int,int>::iterator k=s.begin();k!=s.end();k++)
            printf("%d: %d\n",k->first,k->second);
    }
    return(0);
}

