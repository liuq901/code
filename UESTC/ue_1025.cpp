#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    while (1)
    {
        int n,l,v;
        scanf("%d%d%d",&n,&l,&v);
        if (n==0 && l==0 && v==0)
            break;
        int sum=0,ma=0;
        for (int i=1;i<=n;i++)
        {
            char ch;
            int x;
            scanf("%d %*c %c",&x,&ch);
            if (ch=='E')
                x=l-x;
            sum+=x;
            ma=max(ma,x);
        }
        printf("%.2f %d.00\n",double(ma)/v,sum);
    }
    return(0);
}

