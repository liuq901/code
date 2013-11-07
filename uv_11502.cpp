#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
const double g=9.8;
vector <pair <int,double> > f;
inline bool cmp(const pair <int,double> &a,const pair <int,double> &b)
{
    return(a.first==b.first);
}
double integrate(double m,double t,double c)
{
    return((log(m)-log(m-c*t))/c);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        f.clear();
        f.push_back(make_pair(0,0));
        for (int i=1;i<=n;i++)
        {
            int S,L,T,C;
            scanf("%d%d%d%d",&S,&L,&T,&C);
            if (S>10000 || L>10000 || S+L>10000)
                continue;
            int tot=f.size();
            for (int j=0;j<tot;j++)
            {
                int mass=f[j].first;
                double tot=f[j].second;
                if (S+L+mass>10000)
                    continue;
                double t=double(L)/C;
                mass+=S+L;
                if (T*10<mass*98)
                    continue;
                double value=T*integrate(mass,t,C)-g*t;
                f.push_back(make_pair(mass,tot-value));
            }
            sort(f.begin(),f.end());
            f.erase(unique(f.begin(),f.end(),cmp),f.end());
        }
        double ans=0;
        for (int i=0;i<f.size();i++)
            ans=min(ans,f[i].second);
        printf("%.0f\n",-ans);
    }
    return(0);
}

