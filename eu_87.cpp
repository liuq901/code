#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=50000000;
int m,p[10010];
bool f[10010];
void init()
{
    int n=10000;
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
int main()
{
    init();
    vector <int> a;
    for (int i=1;i<=m;i++)
    {
        ll now=ll(p[i])*p[i];
        if (now>N)
            break;
        for (int j=1;j<=m;j++)
        {
            ll here=now+ll(p[j])*p[j]*p[j];
            if (here>N)
                break;
            for (int k=1;k<=m;k++)
            {
                ll tmp=here+ll(p[k])*p[k]*p[k]*p[k];
                if (tmp>N)
                    break;
                a.push_back(tmp);
            }
        }
    }
    sort(a.begin(),a.end());
    printf("%d\n",unique(a.begin(),a.end())-a.begin());
    return(0);
}

