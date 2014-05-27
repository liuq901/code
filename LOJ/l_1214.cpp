#include <cstdio>
#include <cstring>
typedef long long ll;
char a[210];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll x;
        scanf("%s%lld",a,&x);
        if (x<0)
            x*=-1;
        int start=0;
        if (a[0]=='-')
            start=1;
        ll now=0;
        int len=strlen(a);
        for (int i=start;i<len;i++)
            now=(now*10+a[i]-'0')%x;
        static int id=0;
        printf("Case %d: %sdivisible\n",++id,now==0?"":"not ");
    }
    return(0);
}

