#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
struct UnitsMoving
{
    int n,b[60],a[60][60];
    bool f[60];
    double bestTime(vector <string> start,vector <string> finish)
    {
        n=start.size();
        double x1[60],y1[60],v[60],x2[60],y2[60];
        for (int i=1;i<=n;i++)
        {
            sscanf(start[i-1].c_str(),"%lf%lf%lf",&x1[i],&y1[i],&v[i]);
            sscanf(finish[i-1].c_str(),"%lf%lf",&x2[i],&y2[i]);
        }
        double l=0,r=1e10;
        for (int T=1;T<=1000;T++)
        {
            double mid=(l+r)/2;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    a[i][j]=dist(x1[i],y1[i],x2[j],y2[j])<=mid*v[i];
            int ans=0;
            memset(b,0,sizeof(b));
            for (int i=1;i<=n;i++)
            {
                memset(f,0,sizeof(f));
                ans+=hungary(i);
            }
            if (ans!=n)
                l=mid;
            else
                r=mid;
        }
        return((l+r)/2);
    }
    double dist(double x1,double y1,double x2,double y2)
    {
        return(sqrt(sqr(x1-x2)+sqr(y1-y2)));
    }
    double sqr(double x)
    {
        return(x*x);
    }
    bool hungary(int x)
    {
        if (!x)
            return(true);
        for (int i=1;i<=n;i++)
        {
            if (!a[x][i] || f[i])
                continue;
            f[i]=true;
            if (hungary(b[i]))
            {
                b[i]=x;
                return(true);
            }
        }
        return(false);
    }
};
int main(){}

