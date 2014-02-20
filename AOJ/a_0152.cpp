#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>
using namespace std;
pair <int,int> a[10010];
char buf[1000000];
int calc()
{
    gets(buf);
    stringstream sin(buf);
    vector <int> a;
    int x;
    while (sin>>x)
        a.push_back(x);
    int ret=0,t=0;
    for (int i=1;i<=10;i++)
    {
        ret+=a[t]+a[t+1];
        if (a[t]==10 || a[t]+a[t+1]==10)
            ret+=a[t+2];
        if (a[t]==10)
            t++;
        else
            t+=2;
    }
    return(ret);
}
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
            scanf("%d",&a[i].second);
            a[i].first=-calc();
        }
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++)
            printf("%d %d\n",a[i].second,-a[i].first);
    }
    return(0);
}

