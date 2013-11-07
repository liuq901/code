#include <cstdio>
#include <algorithm>
using namespace std;
int x[110],y[110];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (!n)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        x[0]=x[n],y[0]=y[n];
        int minx=1<<30,miny=1<<30,maxx=-1<<30,maxy=-1<<30;
        for (int i=1;i<=n;i++)
        {
            if (x[i]==x[i-1])
                if (y[i]>y[i-1])
                    maxx=max(maxx,x[i-1]);
                else
                    minx=min(minx,x[i-1]);
            else if (x[i-1]>x[i])
                maxy=max(maxy,y[i-1]);
            else
                miny=min(miny,y[i-1]);
        }
        static int id=0;
        printf("Floor #%d\n%s\n\n",++id,maxx<=minx && maxy<=miny?"Surveillance is possible.":"Surveillance is impossible.");
    }
    return(0);
}

