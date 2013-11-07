#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const double eps=1e-8;
vector <int> from[60];
vector <double> amount[60];
int f[60];
int main()
{
    int n,w,m;
    scanf("%d%d%d",&n,&w,&m);
    double v=n*w/double(m),s=0;
    int now=0;
    for (int i=1;i<=m;i++)
    {
        double x=v;
        if (fabs(s)<eps)
        {
            now++;
            s=w;
        }
        while (fabs(x)>eps)
        {
            if (s<=x)
            {
                from[i].push_back(now);
                amount[i].push_back(s);
                x-=s;
                s=w;
                f[now]++;
                now++;
                continue;
            }
            f[now]++;
            from[i].push_back(now);
            amount[i].push_back(x);
            s-=x;
            x=0;
        }
    }
    bool flag=true;
    for (int i=1;i<=n;i++)
        if (f[i]>2)
        {
            flag=false;
            break;
        }
    if (!flag)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (int i=1;i<=m;i++)
        {
            for (int j=0;j<from[i].size();j++)
            {
                if (j)
                    printf(" ");
                printf("%d %.10f",from[i][j],amount[i][j]);
            }
            printf("\n");
        }
    }
    return(0);
}

