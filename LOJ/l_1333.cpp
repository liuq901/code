#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000000;
int power(int x,int y)
{
    int ret=1;
    for (;y;y>>=1)
    {
        if (y&1)
            ret=ll(ret)*x%mod;
        x=ll(x)*x%mod;
    }
    return(ret);
}
pair <int,int> a[510];
int idx,vis[1000010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,K,B;
        scanf("%d%d%d%d",&n,&m,&K,&B);
        vector <int> X;
        for (int i=1;i<=B;i++)
        {
            scanf("%d%d",&a[i].first,&a[i].second);
            X.push_back(a[i].first);
            if (a[i].first<n)
                X.push_back(a[i].first+1);
        }
        X.push_back(1);
        X.push_back(n);
        sort(X.begin(),X.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        sort(a+1,a+B+1);
        int ans=1,prev=0,block=m,t=1;
        idx++;
        for (int i=1;i<=m;i++)
            vis[i]=idx;
        int tmp=power(K-1,m);
        for (int i=0;i<X.size();i++)
        {
            idx++;
            int cnt=0;
            while (t<=B && a[t].first==X[i])
            {
                cnt++;
                if (vis[a[t].second]==idx-1)
                    block--;
                vis[a[t].second]=idx;
                t++;
            }
            if (prev!=X[i]-1)
                block=0;
            ans=ll(ans)*power(K-1,m-cnt-block)%mod*power(K,block)%mod*power(tmp,X[i]-prev-1)%mod;
            prev=X[i];
            block=cnt;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

