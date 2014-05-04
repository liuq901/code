#include <cstdio>
#include <algorithm>
using namespace std;
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
        int a[3];
        for (int i=0;i<3;i++)
            scanf("%d",&a[i]);
        sort(a,a+3);
        static int id=0;
        printf("Case %d: %s\n",++id,sqr(a[0])==sqr(a[2])-sqr(a[1])?"yes":"no");
    }
    return(0);
}

