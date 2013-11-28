#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int K,a[20];
    scanf("%d",&K);
    for (int i=1;i<=12;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+13);
    reverse(a+1,a+13);
    a[0]=0;
    int ans=-1;
    for (int i=0;i<=12;i++)
    {
        K-=a[i];
        if (K<=0)
        {
            ans=i;
            break;
        }
    }
    printf("%d\n",ans);
    return(0);
}

