#include <cstdio>
int main()
{
    int a,b,ans=0;
    scanf("%d%d",&a,&b);
    while (a!=b)
    {
        if (b%a!=0)
        {
            ans=-1;
            break;
        }
        b/=a;
        ans++;
    }
    if (ans==-1)
        printf("NO\n");
    else
        printf("YES\n%d\n",ans);
    return(0);
}

