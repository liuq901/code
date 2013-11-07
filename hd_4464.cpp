#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;
char buf[100000];
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            ans=max(ans,accumulate(buf,buf+strlen(buf),0));
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

