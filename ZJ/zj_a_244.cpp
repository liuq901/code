#include <cstdio>
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int op;
        ll x,y;
        scanf("%d%lld%lld",&op,&x,&y);
        switch (op)
        {
        case 1:
            printf("%lld\n",x+y);
            break;
        case 2:
            printf("%lld\n",x-y);
            break;
        case 3:
            printf("%lld\n",x*y);
            break;
        case 4:
            printf("%lld\n",x/y);
            break;
        }
    }
    return(0);
}

