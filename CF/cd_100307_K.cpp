#include <cstdio>
#include <algorithm>
using namespace std;
int me,a[1000010],cnt[1000010];
bool ans[1000010];
bool calc(int c1,int c2,int ma)
{
    return(c1>c2 && c1-c2>ma);
}
bool solve(int c1,int c2,int x1,int k1,int x2,int k2,int hand,int cover)
{
    if (hand==cover)
        return(calc(c1,c2,k1));
    if (cover==me)
        c1--;
    if (hand==me)
        c1++;
    if (cover==x1)
        k1--;
    int ma=max(k1,k2);
    if (hand!=me)
        ma=max(ma,cnt[hand]+1);
    return(calc(c1,c2,ma));
}
int main()
{
    freopen("kabaleo.in","r",stdin);
    freopen("kabaleo.out","w",stdout);
    int n,P,C;
    scanf("%d%d%d%d",&n,&P,&C,&me);
    if (n==1)
    {
        for (int i=1;i<=P;i++)
            scanf("%*d");
        int x;
        scanf("%d",&x);
        if (x==me)
            printf("1\n1\n");
        else
            printf("0\n");
    }
    else
    {
        int c1=0,c2=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            c1+=a[i]==me;
            cnt[a[i]]++;
        }
        int hand;
        scanf("%d",&hand);
        for (int i=2;i<=P;i++)
        {
            int x;
            scanf("%d",&x);
            c2+=x!=me;
            cnt[x]++;
        }
        int x1=0,k1=0,x2=0,k2=0;
        for (int i=1;i<=C;i++)
        {
            if (i==me)
                continue;
            if (cnt[i]>k1)
            {
                x2=x1,k2=k1;
                x1=i,k1=cnt[i];
            }
            else if (cnt[i]>k2)
                x2=i,k2=cnt[i];
        }
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            ans[i]=solve(c1,c2,x1,k1,x2,k2,hand,a[i]);
            sum+=ans[i];
        }
        printf("%d\n",sum);
        bool first=true;
        for (int i=1;i<=n;i++)
            if (ans[i])
            {
                if (!first)
                    printf(" ");
                first=false;
                printf("%d",i);
            }
        if (!first)
            printf("\n");
    }
    return(0);
}

