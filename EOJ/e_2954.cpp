#include <cstdio>
#include <algorithm>
char buf[1010];
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,ans=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            ans+=count(buf,buf+m,'.');
        }
        static int id=0;
        printf("case #%d:\n%d\n",id++,ans);
    }
    return(0);
}

