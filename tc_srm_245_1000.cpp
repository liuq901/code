#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct HairCuts
{
    int a[60];
    double maxCut(vector <string> enter,string lastExit)
    {
        int now=get(9,0),x,y;
        for (int i=0;i<enter.size();i++)
        {
            sscanf(enter[i].c_str(),"%d:%d",&x,&y);
            a[i]=get(x,y);
        }
        sscanf(lastExit.c_str(),"%d:%d",&x,&y);
        int last=get(x,y),n=enter.size();
        sort(a,a+n);
        for (int i=0;i<n;i++)
            now=max(now,a[i])+5;
        if (now>last)
            return(-1);
        double ans=1e10;
        for (int i=0;i<n;i++)
            ans=min(ans,double(last-a[i])/(n-i));
        return(ans);
    }
    int get(int x,int y)
    {
        if (x<9)
            x+=12;
        return(x*60+y);
    }
};
int main(){}

