#include <cstdio>
int n,x,y,ans,a[20];
bool flag[20];
void search(int t)
{
    if (t>n)
    {
        ans++;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                printf("%c",j==a[i]?'Q':'x');
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (flag[i] || x>>t-i+n-1&1 || y>>t+i-2&1)
            continue;
        flag[i]=true;
        x^=1<<t-i+n-1;
        y^=1<<t+i-2;
        a[t]=i;
        search(t+1);
        flag[i]=false;
        x^=1<<t-i+n-1;
        y^=1<<t+i-2;
    }
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        x=y=ans=0;
        for (int i=1;i<=n;i++)
        {
            flag[i]=true;
            x^=1<<n-i;
            y^=1<<i-1;
            a[1]=i;
            search(2);
            flag[i]=false;
            x^=1<<n-i;
            y^=1<<i-1;
        }
        printf("%d\n\n",ans);
    }
    return(0);
}

