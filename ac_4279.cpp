#include <cstdio>
int ans[1010];
int calc(int x)
{
    return(x*(x+1)>>1);
}
void init()
{
    for (int i=1;i<=1000;i++)
        ans[i]=ans[i-1]+calc(i);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        static int id=0;
        printf("%d: %d %d\n",++id,n,ans[n]);
    }
    return(0);
}

