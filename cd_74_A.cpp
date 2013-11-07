#include <cstdio>
char s[60][10000];
int main()
{
    int ans=-1<<30,k,n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%s%d%d",s[i],&x,&y);
        int sum=100*x-50*y;
        for (int j=1;j<=5;j++)
        {
            int t;
            scanf("%d",&t);
            sum+=t;
        }
        if (sum>ans)
            ans=sum,k=i;
    }
    printf("%s\n",s[k]);
    return(0);
}

