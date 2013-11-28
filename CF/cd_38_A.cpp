#include <cstdio>
int s[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        s[i]=s[i-1]+x;
    }
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",s[b]-s[a]);
    return(0);
}

