#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
bitset <16000000> f;
int main()
{
    int a,c,m,R;
    scanf("%d%d%d%d",&a,&c,&m,&R);
    while (!f[R])
    {
        f[R]=1;
        R=(a*R+c)%m;
    }
    int ans=0,last=-1;
    for (int i=0;i<m;i++)
        if (f[i])
        {
            if (last!=-1)
                ans=max(ans,i-last);
            last=i;
        }
    printf("%d\n",ans);
    return(0);
}

