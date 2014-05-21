#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
struct RadioRange
{
    double RadiusProbability(vector <int> X,vector <int> Y,vector <int> R,int Z)
    {
        int n=X.size();
        vector <pair <double,double> > a;
        for (int i=0;i<n;i++)
        {
            pair <double,double> tmp=calc(X[i],Y[i],R[i],Z);
            a.push_back(tmp);
        }
        sort(a.begin(),a.end());
        double ans=0,last=0;
        for (int i=0;i<a.size();i++)
        {
            ans+=max(0.0,a[i].first-last);
            last=max(last,a[i].second);
        }
        ans+=Z-last;
        return(ans/Z);
    }
    double dist(double x,double y)
    {
        return(sqrt(x*x+y*y));
    }
    pair <double,double> calc(int x,int y,int R,int Z)
    {
        double l,r;
        l=max(0.0,dist(x,y)-R);
        r=min(double(Z),dist(x,y)+R);
        if (l<=r)
            return(make_pair(l,r));
        else
            return(make_pair(0,0));
    }
};
int main(){}

