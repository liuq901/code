#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1010;
char a[N],b[N];
int v[N];
multiset <int> big,small,same;
vector <int> c;
ll calc()
{
    ll ans=0;
    int i=0;
    for (multiset <int>::iterator k=big.begin();k!=big.end();k++)
        ans+=ll(*k)*(big.size()-i++);
    i=0;
    for (multiset <int>::iterator k=small.begin();k!=small.end();k++)
        ans+=ll(*k)*(small.size()-1-i++);
    for (multiset <int>::iterator k=same.begin();k!=same.end();k++)
        ans+=ll(*k)*(big.size()+small.size());
    return(ans);    
}
inline void del(multiset <int> &a,int x)
{
    a.erase(a.find(x));
}
inline void add(multiset <int> &a,int x)
{
    a.insert(x);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        scanf("%s%s",a+1,b+1);
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        small.clear();
        big.clear();
        same.clear();
        c.clear();
        for (int i=1;i<=n;i++)
        {
            if (a[i]=='1' && b[i]=='0')
                small.insert(v[i]);
            if (a[i]=='0' && b[i]=='1')
                big.insert(v[i]);
            if (a[i]=='1' && b[i]=='1')
            {
                same.insert(v[i]);
                c.push_back(v[i]);
            }
        }
        sort(c.begin(),c.end());
        reverse(c.begin(),c.end());
        ll ans=calc();
        for (int i=0;i<c.size();i++)
        {
            int x=c[i];
            del(same,x);
            add(small,x);
            add(big,x);
            ans=min(ans,calc());
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

