#include <cstdio>
int sg[1010],idx[1010];
int calc(int x)
{
    if (x<=1000)
        return(sg[x]);
    return(sg[x%34+340]);
}
int main()
{
    sg[0]=sg[1]=0;
    for (int i=2;i<=1000;i++)
    {
        for (int j=0;j<=i-2;j++)
            idx[sg[j]^sg[i-j-2]]=i;
        for (int j=0;;j++)
            if (idx[j]!=i)
            {
                sg[i]=j;
                break;
            }
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ans^=calc(x);
        }
        printf("%s\n",ans?"Carol":"Dave");
    }
    return(0);
}

