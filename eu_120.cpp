#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int power(int x,int y,int mod)
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
int main()
{
    int sum=0;
    for (int i=3;i<=1000;i++)
    {
        int ans=0;
        for (int j=1;j<=10000;j++)
            ans=max(ans,(power(i-1,j,i*i)+power(i+1,j,i*i))%(i*i));
        sum+=ans;
    }
    printf("%d\n",sum);
    return(0);
}

