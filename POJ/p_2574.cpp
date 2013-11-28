#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
const double eps=1e-8;
int x[110],y[110];
pair <double,double> a[10000];
double calc(int x1,int y1,int x2,int y2,int x0)
{
    double t=double(x0-x1)/(x2-x1);
    return(y1+(y2-y1)*t);
}
int main()
{
    int n=0;
    while (scanf("%d%d",&x[0],&y[0])==2)
        x[++n]=x[0],y[n]=y[0];
    ll ans=0;
    for (int i=0;i<100000;i++)
    {
        int m=0;
        for (int j=1;j<=n;j++)
            if (min(x[j],x[j-1])<=i && max(x[j],x[j-1])>i)
            {
                double y1=calc(x[j],y[j],x[j-1],y[j-1],i);
                double y2=calc(x[j],y[j],x[j-1],y[j-1],i+1);
                a[++m]=make_pair(y1,y2);
            }
        sort(a+1,a+m+1);
        for (int j=2;j<=m;j+=2)
            ans+=max(0,int(min(a[j].first,a[j].second)+eps)-int(max(a[j-1].first,a[j-1].second)+1-eps));
    }
    cout<<ans<<endl;
}

