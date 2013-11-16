#include <cstdio>
#include <cstring>
typedef unsigned long long ull;
const int lq=10007;
char s[50010];
ull c[26],a[50010],b[50010];
inline ull hash(int l,int r)
{
    return(a[r]-a[l-1]*b[r-l+1]);
}
int main()
{
    b[0]=1;
    for (int i=1;i<=50000;i++)
        b[i]=b[i-1]*lq;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        for (int i=1;i<=n;i++)
            a[i]=a[i-1]*lq+s[i]-'A';
        int ans=0,l=1,r=n;
        for (int i=1;i<=n;i++)
        {
            int len=i-l+1,t=r-len+1;
            if (i>=t)
                break;
            if (hash(l,i)==hash(t,r))
            {
                ans+=2;
                l=i+1;
                r=t-1;
            }
        }
        if (l<=r)
            ans++;
        static int id=0;
        printf("Case #%d: %d\n",++id,ans);
    }
    return(0);
}

