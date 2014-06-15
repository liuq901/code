#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int X[710],Y[710];
inline int sqr(int x)
{
    return(x*x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        vector <int> value;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                value.push_back(sqr(X[i]-X[j])+sqr(Y[i]-Y[j]));
        sort(value.begin(),value.end());
        value.erase(unique(value.begin(),value.end()),value.end());
        static int id=0;
        printf("Case %d: %d\n",++id,value.size()+1);
    }
    return(0);
}

