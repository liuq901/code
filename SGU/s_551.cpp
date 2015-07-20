#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,t1,t2;
    scanf("%d%d%d",&n,&t1,&t2);
    int l=0,r=1<<30,ans;
    while (l<=r)
    {
        int mid=l+r>>1;
        if (mid/t1+mid/t2>=n)
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    int x=(ans+t1-1)/t1,y=(ans+t2-1)/t2;
    printf("%d %d\n",x+y,max(x*t1,y*t2));
    return(0);
}

