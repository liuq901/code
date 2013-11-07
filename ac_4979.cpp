#include <cstdio>
#include <algorithm>
using namespace std;
const int c[4][2]={{0,1},{1,0},{1,1},{1,-1}};
char a[10][10];
int get(int x0,int y0,int p)
{
    int x=x0,y=y0;
    for (int i=1;i<=3;i++)
    {
        if (a[x][y]!=a[x0][y0])
            return(0);
        x+=c[p][0],y+=c[p][1];
    }
    return(a[x0][y0]=='A'?1:-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=5;i++)
            scanf("%s",a[i]+1);
        int ma=0,mi=0;
        for (int i=1;i<=5;i++)
            for (int j=1;j<=3;j++)
            {
                int t=get(i,j,0);
                ma=max(ma,t);
                mi=min(mi,t);
            }
        for (int i=1;i<=3;i++)
            for (int j=1;j<=5;j++)
            {
                int t=get(i,j,1);
                ma=max(ma,t);
                mi=min(mi,t);
            }
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
            {
                int t=get(i,j,2);
                ma=max(ma,t);
                mi=min(mi,t);

            }
        for (int i=1;i<=3;i++)
            for (int j=3;j<=5;j++)
            {
                int t=get(i,j,3);
                ma=max(ma,t);
                mi=min(mi,t);
            }
        if (ma==1 && mi==-1 || ma==0 && mi==0)
            printf("draw\n");
        else if (ma==1)
            printf("A wins\n");
        else
            printf("B wins\n");
    }
    return(0);
}

