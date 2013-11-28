#include <cstdio>
#include <cstring>
int a[10010];
bool f[1000010];
void init()
{
    int n=32000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            a[++a[0]]=i;
}
int main()
{
    init();
    int l,r;
    while (scanf("%d%d",&l,&r)==2)
    {
        memset(f,0,sizeof(f));
        for (int i=1;i<=a[0];i++)
            for (int j=l/a[i];a[i]*j<=r;j++)
                if (a[i]*j>=l && j!=1)
                    f[a[i]*j-l]=true;
        if (l==1)
            f[0]=true;
        int ans=0;
        for (int i=l;i<=r;i++)
            ans+=1-f[i-l];
        printf("%d\n",ans);
    }
    return(0);
}

