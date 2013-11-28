#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
struct KingdomXCitiesandVillages
{
    double determineLength(vector <int> cx,vector <int> cy,vector <int> vx,vector <int> vy)
    {
        double ans=0;
        for (int i=0;i<vx.size();i++)
        {
            vector <pair <double,bool> > a;
            for (int j=0;j<cx.size();j++)
                a.push_back(make_pair(dist(vx[i],vy[i],cx[j],cy[j]),true));
            for (int j=0;j<vx.size();j++)
            {
                if (i==j)
                    continue;
                a.push_back(make_pair(dist(vx[i],vy[i],vx[j],vy[j]),false));
            }
            sort(a.begin(),a.end());
            for (int j=0;j<a.size();j++)
            {
                if (a[j].second)
                {
                    ans+=a[j].first/(j+1);
                    break;
                }
                ans+=a[j].first/(j+1)/(j+2);
            }
        }
        return(ans);
    }
    double sqr(double x)
    {
        return(x*x);
    }
    double dist(double x1,double y1,double x2,double y2)
    {
        return(sqrt(sqr(x1-x2)+sqr(y1-y2)));
    }
};
int main(){}

