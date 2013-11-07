#include <cstdio>
#include <map>
using namespace std;
map <int,int> M;
int main()
{
    for (int i=0;i<=1000;i++)
        for (int j=0;j<=1000;j++)
            M[4*i+3*j]++;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,ans=0;
        scanf("%d",&n);
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
            {
                int p=n-2*i-j;
                if (M.count(p))
                    ans+=M[p];
            }
        printf("%d\n",ans);
    }
    return(0);
}

