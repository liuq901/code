#include <cstdio>
#include <cstdlib>
#include <cstring>
bool f[3010];
int a[3010];
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(f,0,sizeof(f));
        for (int i=2;i<=n;i++)
        {
            int x=abs(a[i]-a[i-1]);
            if (x>=1 && x<n)
                f[x]=true;
        }
        bool flag=true;
        for (int i=1;i<=n-1;i++)
            if (!f[i])
            {
                flag=false;
                break;
            }
        printf("%s\n",flag?"Jolly":"Not jolly");
    }
    return(0);
}

