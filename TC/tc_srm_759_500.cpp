#include <vector>
using namespace std;
typedef long long ll;
struct ConvexSequence
{
    long long getMinimum(vector <int> b)
    {
        if (b.size()<=2)
            return(0);
        vector <ll> a(b.begin(),b.end());
        int n=a.size();
        ll ans=0;
        while (1)
        {
            bool flag=true;
            for (int i=1;i<=n-2;i++)
            {
                ll p=a[i-1]+a[i+1];
                if (2*a[i]<=p)
                    continue;
                flag=false;
                ll x=p/2;
                ans+=(a[i]-x);
                a[i]=x;
            }
            if (flag)
                break;
        }
        return(ans);
    }
};
int main(){}
