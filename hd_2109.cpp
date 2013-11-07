#include <cstdio>
#include <algorithm>
using namespace std;
int a[110],b[110];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        int x=0,y=0;
        for (int i=1;i<=n;i++)
            if (a[i]<b[i])
                y+=2;
            else if (a[i]==b[i])
                x++,y++;
            else
                x+=2;
        printf("%d vs %d\n",x,y);
    }
    return(0);
}

