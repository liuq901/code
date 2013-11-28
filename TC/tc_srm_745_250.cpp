#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
int d[50];
struct Zoo
{
    ll theCount(vector <int> a)
    {
        for (int i=0;i<a.size();i++)
            d[a[i]]++;
        if (d[0]>2)
            return(0);
        for (int i=1;i<=40;i++)
            if (d[i]>d[i-1])
                return(0);
        ll ans=1;
        for (int i=0;i<=40;i++)
        {
            if (!d[i])
                break;
            if (d[i]==1)
            {
                ans<<=1;
                break;
            }
            ans<<=1;
        }
        return(ans);
    }
};
int main(){}

