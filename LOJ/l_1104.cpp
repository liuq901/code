#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        double p=1;
        for (int i=1;;i++)
        {
            p*=double(n-i)/n;
            if (p<=0.5)
            {
                static int id=0;
                printf("Case %d: %d\n",++id,i,2);
                break;
            }
        }
    }
    return(0);
}

