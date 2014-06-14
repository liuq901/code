#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[100010],ans[100010];
bool less(int n)
{
    for (int i=1;i<=n;i++)
        if (a[i]!=ans[i])
            return(a[i]<ans[i]);
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a+1);
        int n=strlen(a+1);
        static int id=0;
        printf("Case %d: ",++id);
        if (count(a+1,a+n+1,'9')==n)
        {
            printf("1");
            for (int i=1;i<n;i++)
                printf("0");
            printf("1\n");
        }
        else
        {
            int m=n+1>>1;
            for (int i=1;i<=m;i++)
                ans[i]=a[i];
            for (int i=m+1;i<=n;i++)
                ans[i]=ans[n-i+1];
            ans[n+1]='\0';
            if (less(n))
                printf("%s\n",ans+1);
            else
            {
                ans[m]++;
                for (int i=m;i;i--)
                {
                    if (ans[i]<='9')
                        break;
                    ans[i-1]++;
                    ans[i]-=10;
                }
                for (int i=m+1;i<=n;i++)
                    ans[i]=ans[n-i+1];
                printf("%s\n",ans+1);
            }
        }
    }
    return(0);
}

