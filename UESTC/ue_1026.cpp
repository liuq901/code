#include <cstdio>
#include <algorithm>
using namespace std;
int W,L;
int calc(int x,int y)
{
    int u=x/(W+L),v=y/(W+L);
    x%=(W+L),y%=(W+L);
    return(u*v*L*L+min(x,L)*L*v+min(y,L)*L*u+min(x,L)*min(y,L));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d%d%d",&W,&L,&x1,&y1,&x2,&y2);
        x1++,y1++;
        int red=calc(x2,y2)-calc(x1-1,y2)-calc(x2,y1-1)+calc(x1-1,y1-1);
        printf("%d\n",(x2-x1+1)*(y2-y1+1)-red);
    }
    return(0);
}

