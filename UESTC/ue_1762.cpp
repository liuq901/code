#include <cstdio>
#include <cmath>
const double eps=1e-8;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;;i++)
        {
            n-=int(log10(double(i))+1+eps);
            if (n<=0)
            {
                printf("%d\n",n==0?i:-1);
                break;
            }
        }
    }
    return(0);
}

