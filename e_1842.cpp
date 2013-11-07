#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
bool f[1000010];
vector <int> prime;
int main()
{
    for (int i=2;i*i<=1000000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=1000000;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=1000000;i++)
        if (!f[i])
            prime.push_back(i);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        vector <int>::iterator upper=lower_bound(prime.begin(),prime.end(),n),lower;
        lower=upper==prime.begin()?upper:upper-1;
        printf("%d\n",abs(*lower-n)<=abs(*upper-n)?*lower:*upper);
    }
    return(0);
}

