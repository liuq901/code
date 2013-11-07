#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[40];
vector <int> b;
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        b.clear();
        int n1=n/2,n2=n-n1;
        for (int i=0;i<1<<n1;i++)
        {
            int sum=0;
            for (int j=1;j<=n1;j++)
                if (i>>j-1&1)
                    sum+=a[j];
            if (sum<=m)
                b.push_back(m-sum);
        }
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        int ans=m;
        for (int i=0;i<1<<n2;i++)
        {
            int sum=0;
            for (int j=n1+1;j<=n;j++)
                if (i>>j-n1-1&1)
                    sum+=a[j];
            int p=lower_bound(b.begin(),b.end(),sum)-b.begin();
            if (p!=b.size())
                ans=min(ans,b[p]-sum);
        }
        printf("%d\n",m-ans);
    }
    return(0);
}

