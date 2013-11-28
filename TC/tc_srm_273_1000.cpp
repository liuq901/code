#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Equidistance
{
    ll minimumEffort(vector <int> a)
    {
        sort(a.begin(),a.end());
        int n=a.size();
        vector <ll> b(n);
        ll ans=1LL<<60;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            {
                if (i==j)
                    continue;
                ll d=(ll(a[j])-a[i])/(j-i);
                for (ll D=d-1;D<=d+1;D++)
                {
                    if (D==0)
                        continue;
                    b[i]=a[i];
                    for (int k=i-1;k>=0;k--)
                        b[k]=b[k+1]-D;
                    for (int k=i+1;k<n;k++)
                        b[k]=b[k-1]+D;
                    ll sum=0;
                    for (int k=0;k<n;k++)
                        sum+=abs(a[k]-b[k]);
                    ans=min(ans,sum);
                }
            }
        return(ans);
    }
};
int main(){}

