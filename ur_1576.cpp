#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n1,n2,n3,c1,c2,t,n;
    scanf("%d%d%d%d%d%d%d",&n1,&c1,&n2,&t,&c2,&n3,&n);
    int tot=0;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d:%d",&x,&y);
        if (x==0 && y<=6)
            y=0;
        if (y!=0)
            x++;
        tot+=x;
    }
    printf("Basic:     %d\nCombined:  %d\nUnlimited: %d\n",n1+tot*c1,n2+c2*max(0,tot-t),n3);
    return(0);
}

