#include <cstdio>
#include <algorithm>
using namespace std;
const int mod=1743;
FILE *in,*out;
short a[4000010];
int f(int x)
{
    return((132LL*x%mod*x%mod*x%mod+77LL*x%mod*x%mod+1345LL*x+1577)%mod);
}
int main()
{
    in=fopen("kth.in","r");
    out=fopen("kth.out","w");
    int n,K;
    fscanf(in,"%d%d",&n,&K);
    for (int i=1;i<=n;i++)
        a[i]=f(i);
    nth_element(a+1,a+K,a+n+1);
    fprintf(out,"%d\n",a[K]);
    return(0);
}

