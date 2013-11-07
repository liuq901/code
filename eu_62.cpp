#include <cstdio>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
map <vector <int>,int> M;
vector <int> calc(ll x)
{
    vector <int> a;
    a.resize(10);
    while (x)
    {
        a[x%10]++;
        x/=10;
    }
    return(a);
}
int main()
{
    for (int i=1;i<=10000;i++)
        M[calc(ll(i)*i*i)]++;
    for (int i=1;i<=10000;i++)
    {
        vector <int> t=calc(ll(i)*i*i);
        if (M[t]==5)
        {
            printf("%lld\n",ll(i)*i*i);
            break;
        }
    }
    return(0);
}

