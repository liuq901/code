#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int a[10],b[10],c[510];
queue <int> P,Q;
bool win(int n,int *a,int *b)
{
    while (!P.empty())
        P.pop();
    while (!Q.empty())
        Q.pop();
    for (int i=1;i<=n;i++)
    {
        P.push(a[i]);
        Q.push(b[i]);
    }
    while (!P.empty() && !Q.empty())
    {
        int x=P.front(),y=Q.front();
        P.pop(),Q.pop();
        if (x<y)
            Q.push(x),Q.push(y);
        if (x>y)
            P.push(y),P.push(x);
    }
    return(!P.empty() && Q.empty());
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    if (n>=5)
    {
        printf("YES\n");
        for (int i=1;i<=n-5;i++)
            printf("%d ",c[i]);
        int t=0;
        for (int i=n-4;i<=n;i++)
        {
            a[++t]=c[i];
            b[t]=c[i];
        }
        sort(b+1,b+6);
        while (1)
        {
            if (win(5,b,a))
            {
                for (int i=1;i<=5;i++)
                    printf("%d%c",b[i],i==5?'\n':' ');
                break;
            }
            next_permutation(b+1,b+6);
        }
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
            a[i]=c[i];
            b[i]=i;
        }
        bool flag=false;
        while (1)
        {
            if (win(n,b,a))
            {
                printf("YES\n");
                for (int i=1;i<=n;i++)
                    printf("%d%c",b[i],i==n?'\n':' ');
                flag=true;
                break;
            }
            if (!next_permutation(b+1,b+n+1))
            {
                flag=false;
                break;
            }
        }
        if (!flag)
            printf("NO\n");
    }
    return(0);
}

