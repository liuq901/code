#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int xmin,ymin,zmin,xmax,ymax,zmax;
        xmin=ymin=zmin=-1;
        xmax=ymax=zmax=1<<30;
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x1,y1,z1,x2,y2,z2;
            scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
            xmin=max(xmin,x1),ymin=max(ymin,y1),zmin=max(zmin,z1);
            xmax=min(xmax,x2),ymax=min(ymax,y2),zmax=min(zmax,z2);
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (xmin>xmax || ymin>ymax || zmin>zmax)
            printf("0\n");
        else
            printf("%d\n",(xmax-xmin)*(ymax-ymin)*(zmax-zmin));
    }
    return(0);
}

