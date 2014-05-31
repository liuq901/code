#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,ans=0;
        scanf("%d",&n);
        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            ans^=x;
            if (x>1)
                flag=false;
        }
        static int id=0;
        printf("Case %d: %s\n",++id,flag && ans==0 || !flag && ans>0?"Alice":"Bob");
    }
    return(0);
}

