#include <cstdio>
#include <cstring>
char a[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d%s",&n,a+1);
        a[++n]='#';
        int ans=0;
        for (int i=2;i<=n;i++)
            if (a[i-1]=='.')
            {
                ans++;
                a[i-1]=a[i]=a[i+1]='#';
            }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

