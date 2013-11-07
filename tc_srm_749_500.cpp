#include <vector>
using namespace std;
double f[1310][1310],p[1310][1310];
bool vis[1310][1310];
struct PerfectMemory
{
    double getExpectation(int N,int M)
    {
        int n=N*M/2;
        p[0][0]=1;
        for (int i=0;i<n;i++)
            for (int j=0;j<=n;j++)
            {
                int x=n-i-j;
                if (x<0)
                    break;
                int y=x+x+j;
                if (j>=1)
                {
                    f[i+1][j-1]+=(f[i][j]+p[i][j])*j/y;
                    p[i+1][j-1]+=p[i][j]*j/y;
                }
                if (x>=1 && j>=1)
                {
                    f[i+1][j]+=(f[i][j]+2*p[i][j])*2*x/y*j/(y-1);
                    p[i+1][j]+=p[i][j]*2*x/y*j/(y-1);
                }
                if (x>=1)
                {
                    double P=(2.0*x)/y*(2*x-1)/(y-1),pp=2.0*x/y/(y-1);
                    f[i+1][j]+=(f[i][j]+p[i][j])*pp;
                    p[i+1][j]+=p[i][j]*pp;
                    f[i][j+2]+=(f[i][j]+p[i][j])*(P-pp);
                    p[i][j+2]+=p[i][j]*(P-pp);
                }
            }
        return(f[n][0]);
    }
};
int main(){}

