#include <cstdio>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
int m,p[100010];
bool f[100010];
void init()
{
    int n=100000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[++m]=i;
}
set <int> a[100010];
pair <int,int> rad[100010];
int main()
{
    init();
    for (int i=1;i<=100000;i++)
    {
        for (int j=1;j<=m;j++)
            if (i%p[j]==0)
            {
                a[i]=a[i/p[j]];
                a[i].insert(p[j]);
                break;
            }
        rad[i]=make_pair(1,i);
        for (set <int>::iterator k=a[i].begin();k!=a[i].end();k++)
            rad[i].first*=*k;
    }
    sort(rad+1,rad+100001);
    printf("%d\n",rad[10000].second);
    return(0);
}

