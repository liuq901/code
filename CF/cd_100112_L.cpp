#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair <double,double> > s,ans;
double x[1010];
int main()
{
    int n;
    double L;
    scanf("%d%lf",&n,&L);
    for (int i=1;i<=n;i++)
        scanf("%lf",&x[i]);
    sort(x+1,x+n+1);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            for (int k=1;;k++)
            {
                double l=(x[j]-x[i])/(k*L+1),r=(x[j]-x[i])/(k*L-1);
                if (l>10)
                    continue;
                if (r<0.1)
                    break;
                s.push_back(make_pair(l,r));
            }
            if (x[j]-x[i]<10)
                s.push_back(make_pair(x[j]-x[i],1e10));
        }
    sort(s.begin(),s.end());
    for (int i=0;i<s.size();i++)
        if (ans.empty() || ans.back().second<s[i].first)
            ans.push_back(s[i]);
        else
            ans.back().second=max(ans.back().second,s[i].second);
    double V;
    if (ans.empty() || ans.back().second<10)
        V=10;
    else
    {
        V=ans.back().first;
        if (V<0.1)
            V=-1;
    }
    if (V<0)
        printf("no fika\n");
    else
        printf("%.15f\n",V);
    return 0;
}

