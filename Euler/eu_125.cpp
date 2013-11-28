#include <cstdio>
#include <set>
#include <numeric>
using namespace std;
bool check(int p)
{
    int m=0,a[10];
    while (p)
    {
        a[++m]=p%10;
        p/=10;
    }
    for (int i=1;i<=m/2;i++)
        if (a[i]!=a[m-i+1])
            return(false);
    return(true);
}
int main()
{
    set <int> s;
    for (int i=1;i<=10000;i++)
    {
        int sum=0;
        for (int j=i;j<=10000;j++)
        {
            sum+=j*j;
            if (sum>100000000)
                break;
            if (i!=j && check(sum))
                s.insert(sum);
        }
    }
    printf("%lld\n",accumulate(s.begin(),s.end(),0LL));
    return(0);
}

