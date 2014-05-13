#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1>x2)
            swap(x1,x2);
        if (y1>y2)
            swap(y1,y2);
        static int id=0;
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%s\n",x>x1 && x<x2 && y>y1 && y<y2?"Yes":"No");
        }
    }
    return(0);
}

