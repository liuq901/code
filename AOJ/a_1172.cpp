#include <cstdio>
#include <vector>
using namespace std;
vector <int> prime;
bool f[300000];
int main()
{
    for (int i=2;i*i<=123456*2;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=123456*2;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=123456*2;i++)
        if (!f[i])
            prime.push_back(i);
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        int ans=0;
        for (int i=0;i<prime.size();i++)
            if (prime[i]>n && prime[i]<=2*n)
                ans++;
        printf("%d\n",ans);
    }
    return(0);
}

