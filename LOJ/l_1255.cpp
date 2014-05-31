#include <cstdio>
#include <cstring>
typedef unsigned long long ull;
const int lq=1000000007;
char a[1000010],b[1000010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%s",a,b);
        int n=strlen(a),m=strlen(b);
        ull now=0,tmp=1;
        for (int i=0;i<m;i++)
        {
            now=now*lq+b[i];
            tmp*=lq;
        }
        int ans=0;
        ull t=0;
        for (int i=0;i<n;i++)
        {
            t=t*lq+a[i];
            if (i>=m)
                t-=a[i-m]*tmp;
            ans+=t==now;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

