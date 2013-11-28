#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        m--;
        vector <int> a;
        for (int i=1;i<=n;i++)
            a.push_back(i);
        while (a.size()>1)
        {
            rotate(a.begin(),a.begin()+m%a.size(),a.end());
            a.erase(a.begin());
        }
        printf("%d\n",a[0]);
    }
    return(0);
}

