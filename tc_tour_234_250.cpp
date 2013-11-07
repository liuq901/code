#include <algorithm>
using namespace std;
struct FruitTrees
{
    int ab[2010],ac[2010],bc[2010];
    int maxDist(int a,int b,int c)
    {
        deal(ab,a,b);
        deal(ac,a,c);
        deal(bc,b,c);
        int ans=0;
        for (int i=0;i<b;i++)
            for (int j=0;j<c;j++)
            {
                int x=(j-i)%c;
                if (x<0)
                    x+=c;
                ans=max(ans,min(min(ab[i],ac[j]),bc[x]));
            }
        return(ans);
    }
    void deal(int *a,int n,int m)
    {
        for (int i=0;i<m;i++)
        {
            a[i]=1<<30;
            for (int j=0;j<=n;j++)
            {
                int pos=i+j*m;
                a[i]=min(a[i],min(pos%n,n-pos%n));
            }
        }
    }
};
int main(){}

