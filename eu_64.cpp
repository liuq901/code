#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
set <pair <pair <int,int>,int> > s;
bool work(int n)
{
    int a=1,b=0,c=1,ret=0;
    double x=sqrt(double(n));
    while (1)
    {
        if (c==0)
            return(false);
        int t=int((a*x+b)/c);
        b-=c*t;
        int tmp=a*a*n-b*b;
        a=a*c,b=-b*c,c=tmp;
        int p=__gcd(__gcd(abs(a),abs(b)),abs(c));
        a/=p,b/=p,c/=p;
        if (s.count(make_pair(make_pair(a,b),c)))
            return(ret&1);
        ret++;
        s.insert(make_pair(make_pair(a,b),c));
    }
}
int main()
{
    int ans=0;
    for (int i=2;i<=10000;i++)
    {
        s.clear();
        ans+=work(i);
    }
    printf("%d\n",ans);
    return(0);
}

