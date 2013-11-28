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
        n+=2;
        m--;
        vector <int> a;
        for (int i=1;i<=n;i++)
            a.push_back(i);
        while (a.size()>2)
        {
            rotate(a.begin(),a.begin()+m%a.size(),a.end());
            a.erase(a.begin());
        }
        printf("%d %d\n",min(a[0],a[1]),max(a[0],a[1]));
    } 
    return(0);
}

