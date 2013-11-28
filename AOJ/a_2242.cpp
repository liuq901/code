#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[1010];
string s[1010];
char buf[100000];
int c[1010];
inline bool cmp(int x,int y)
{
    return(a[x]<a[y]);
}
int main()
{
    while (1)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        if (n==0 && Q==0)
            break;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%s%d%d",buf,&x,&y);
            s[i]=buf;
            c[i]=i;
            a[i]=make_pair(y,y-x+1);
        }
        sort(c+1,c+n+1,cmp);
        while (Q--)
        {
            int x;
            scanf("%d",&x);
            a[0]=make_pair(x,0);
            int t=lower_bound(c+1,c+n+1,0,cmp)-c;
            if (t<=n && a[c[t]].second<=x)
                printf("%s %d\n",s[c[t]].c_str(),x-a[c[t]].second+1);
            else
                printf("Unknown\n");
        }
    }
    return(0);
}

