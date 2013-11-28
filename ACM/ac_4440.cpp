#include <cstdio>
#include <cmath>
#include <algorithm>
#define y0 __y0__
#define SQR(x) ((x)*(x))
using namespace std;
const double X=10/sqrt(2.0),c[8][2]={{10,0},{X,-X},{0,-10},{-X,-X},{-10,0},{-X,X},{0,10},{X,X}};
double x0,y0,ans;
double dist(double x1,double y1,double x2,double y2)
{
    return(sqrt(SQR(x1-x2)+SQR(y1-y2)));
}
void dfs(int dep,double x,double y,int op)
{
    ans=min(ans,dist(x0,y0,x,y));
    if (dep==0)
        return;
    dfs(dep-1,x+c[op][0],y+c[op][1],op);
    if (op!=7)
        dfs(dep-1,x,y,op+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d%lf%lf",&n,&x0,&y0);
        ans=1e100;
        dfs(n,0,0,0);
        printf("%.6f\n",ans);
    }
    return(0);
}

