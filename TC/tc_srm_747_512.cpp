#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct SubFibonacci
{
    vector <int> a;
    int f[41];
    int maxElements(vector <int> S)
    {
        f[0]=0,f[1]=1;
        for (int i=2;i<=40;i++)
            f[i]=f[i-1]+f[i-2];
        a=S;
        int ans=0;
        sort(a.begin(),a.end());
        for (int i=0;i<a.size();i++)
            ans=max(ans,solve(0,i)+solve(i+1,a.size()-1));
        return(ans);
    }
    int solve(int l,int r)
    {
        if (r-l<2)
            return(r-l+1);
        int ret=0;
        for (int i=l;i<r;i++)
            for (int j=i+1;j<=r;j++)
                for (int k=0;k<40;k++)
                {
                    ll tmp=a[j]-a[i]*ll(f[k]);
                    if (tmp<=0 || tmp%f[k+1]!=0)
                        continue;
                    int p=tmp/f[k+1],t=a[i],now=1;
                    while (p<=a[j])
                    {
                        now+=p>a[i] && binary_search(a.begin(),a.end(),p);
                        int x=t+p;
                        t=p,p=x;
                    }
                    ret=max(ret,now);
                }
        return(ret);
    }
};
int main(){}

