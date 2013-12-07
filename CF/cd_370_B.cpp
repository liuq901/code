#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        a[i].resize(m);
        for (int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
        sort(a[i].begin(),a[i].end());
    }
    for (int i=1;i<=n;i++)
    {
        bool flag=true;
        for (int j=1;j<=n;j++)
        {
            if (i==j)
                continue;
            if (includes(a[i].begin(),a[i].end(),a[j].begin(),a[j].end()))
            {
                flag=false;
                break;
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

