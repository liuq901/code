#include <cstdio>
typedef long long ll;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ll sum=ll(n)*3;
    for (int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        sum-=x;
        if (sum<0)
        {
            printf("Free after %d times.\n",i);
            break;
        }
    }
    if (sum>=0)
        printf("Team.GOV!\n");
    return(0);
}

