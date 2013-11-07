#include <cstdio>
typedef long long ll;
int main()
{
    int n;
    scanf("%d",&n);
    int m=3*n-2;
    int ans=ll(1+m)*m/2+ll(n)*(n-1)/2*3;
    printf("%d\n",ans);
    return(0);
}

