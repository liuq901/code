#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
typedef int array[100010];
multiset <int> S;
array type,f,h,cnt,pos,value;
void del(int x)
{
    multiset <int>::iterator k=S.find(x);
    S.erase(k);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        S.clear();
        memset(cnt,0,sizeof(cnt));
        int l=1,r=0,now=1,n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int height;
            scanf("%d%d",&type[i],&height);
            if (++cnt[type[i]]==2)
            {
                while (type[now]!=type[i])
                    cnt[type[now++]]--;
                cnt[type[now++]]--;
                while (l<=r && pos[l]<now)
                    del(value[l++]);
            }
            while (l<=r && h[r]<=height)
                del(value[r--]);
            if (l<=r)
            {
                del(value[l]);
                value[l]=h[l]+f[now-1];
                S.insert(value[l]);
            }
            pos[++r]=i;
            h[r]=height;
            if (l==r)
                value[r]=height+f[now-1];
            else
                value[r]=height+f[pos[r-1]];
            S.insert(value[r]);
            f[i]=*S.begin();
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n]);
    }
    return(0);
}

