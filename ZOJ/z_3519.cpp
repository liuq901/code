#include <cstdio>
#include <set>
using namespace std;
multiset <int> a;
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        a.clear();
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a.insert(x);
        }
        while (!a.empty())
        {
            multiset <int>::iterator k=a.upper_bound(m);
            if (k==a.end())
                break;
            m+=2;
            a.erase(k);
        }
        m+=a.size();
        printf("%d\n",m);
    }
    return(0);
}

