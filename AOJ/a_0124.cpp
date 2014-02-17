#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
pair <pair <int,int>,string> a[10000];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            char buf[100];
            int x,y,z;
            scanf("%s%d%d%d",buf,&x,&y,&z);
            a[i]=make_pair(make_pair(-x*3-z,i),buf);
        }
        sort(a+1,a+n+1);
        static bool first=true;
        if (!first)
            printf("\n");
        first=false;
        for (int i=1;i<=n;i++)
            printf("%s,%d\n",a[i].second.c_str(),-a[i].first.first);
    }
    return(0);
}

