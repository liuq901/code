#include <cstdio>
int a[1010],s[1010],f[1010];
int main()
{
    while (1)
    {
        int n,root;
        scanf("%d%d",&n,&root);
        if (n==0 && root==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s[i]=1;
        }
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            f[y]=x;
        }
        int ans=0;
        for (int i=1;i<n;i++)
        {
            double ma=0;
            int k;
            for (int j=1;j<=n;j++)
                if (double(a[j])/s[j]>ma && j!=root)
                {
                    ma=double(a[j])/s[j];
                    k=j;
                }
            for (int j=1;j<=n;j++)
                if (f[j]==k)
                    f[j]=f[k];
            ans+=a[k]*s[f[k]];
            a[f[k]]+=a[k];
            s[f[k]]+=s[k];
            a[k]=0;
        }
        printf("%d\n",ans+a[root]);
    }
    return(0);
}

