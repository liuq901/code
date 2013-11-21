#include <cstdio>
#include <numeric>
using namespace std;
int a[20];
int main()
{
    while (scanf("%d",&a[1])==1)
    {
        for (int i=2;i<=10;i++)
            scanf(",%d",&a[i]);
        int v1,v2;
        scanf(",%d,%d",&v1,&v2);
        int sum=accumulate(a+1,a+11,0);
        double t=double(sum)/(v1+v2);
        int cnt=0;
        for (int i=1;i<=10;i++)
        {
            cnt+=a[i];
            if (t*v1<=cnt)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return(0);
}

