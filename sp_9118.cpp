#include <cstdio>
#include <cstdlib>
char a[1010],b[1010];
int f[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d%s%s",&n,a,b);
        bool flag=false;
        for (int i=-n;i<=n;i++)
        {
            f[0]=0;
            for (int j=0;j<n;j++)
            {
                if (i+j>=n)
                    break;
                if (i+j<0)
                {
                    f[j]=0;
                    continue;
                }
                f[j+1]=abs(a[i+j]-b[j])<=1?f[j]+1:0;
                if (f[j+1]<<1>=n)
                {
                    flag=true;
                    break;
                }
            }
            if (flag)
                break;
        }
        printf("%s\n",flag?"POSITIVE":"NEGATIVE");
    }
    return(0);
}

