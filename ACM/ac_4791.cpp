#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double eps=1e-8;
const int N=110;
struct point 
{
    int x,y;
};
struct state
{
    int x,y,opt;
    state(){}
    state(int x,int y,int opt):x(x),y(y),opt(opt){}
};
inline int sqr(int x)
{
    return(x*x);
}
inline double dist(const point &a,const point &b)
{
    return(sqrt(double(sqr(a.x-b.x)+sqr(a.y-b.y))));
}
inline int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
double d[N][N],f[N][N][2];
state pre[N][N][2];
point p[N];
vector <int> up,down;
void update(int i,int j,int k,int x,int y,int z,double value)
{
    if (f[x][y][z]>1e9 || sign(f[x][y][z]+value-f[i][j][k])>=0)
        return;
    f[i][j][k]=f[x][y][z]+value;
    pre[i][j][k]=state(x,y,z);
}
void print(int x0,int y0,int z0)
{
    if (x0==0 && y0==0)
        return;
    int x=pre[x0][y0][z0].x,y=pre[x0][y0][z0].y,z=pre[x0][y0][z0].opt;
    if (y==y0)
        up.push_back(x0);
    else
        down.push_back(y0);
    print(x,y,z);
}
int main()
{
    while (1)
    {
        int n,b1,b2;
        scanf("%d%d%d",&n,&b1,&b2);
        if (n==0 && b1==0 && b2==0)
            break;
        if (b1>b2)
            swap(b1,b2);
        for (int i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                d[i][j]=dist(p[i],p[j]);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for (int k=0;k<=1;k++)
                    f[i][j][k]=1e10;
        f[0][0][0]=0;
        update(1,0,0,0,0,0,d[0][1]);
        if (b1!=1)
            update(1,0,1,0,0,0,d[0][1]);
        for (int i=2;i<n;i++)
            for (int j=0;j<i;j++)
                for (int k=0;k<=1;k++)
                {
                    if (i!=b1 && i!=b2 || i==b1 && k==0 || i==b2 && k==1)
                    {
                        update(i,j,k,i-1,j,k,d[i][i-1]);
                        update(i,i-1,k,j,i-1,k,d[i][j]);
                    }
                    if (i!=b1 && i!=b2 || i==b1 && k==1 || i==b2 && k==0)
                    {
                        update(j,i,k,j,i-1,k,d[i][i-1]);
                        update(i-1,i,k,i-1,j,k,d[i][j]);
                    }
                }
        for (int i=0;i<n;i++)
            for (int k=0;k<=1;k++)
            {
                update(n-1,n-1,0,i,n-1,k,d[i][n-1]);
                update(n-1,n-1,0,n-1,i,k,d[i][n-1]);
            }
        up.clear();
        down.clear();
        print(n-1,n-1,0);
        static int id=0;
        printf("Case %d: %.2f\n",++id,f[n-1][n-1][0]);
        printf("0");
        reverse(up.begin(),up.end());
        for (int i=0;i<up.size();i++)
            printf(" %d",up[i]);
        for (int i=1;i<down.size();i++)
            printf(" %d",down[i]);
        printf(" 0\n");
    }
    return(0);
}

