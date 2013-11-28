#include <cstdio>
#include <set>
using namespace std;
int a[1010];
set <int> s;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        s.clear();
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s.insert(a[i]);
        }
        bool flag=false;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                if (s.count(-(a[i]+a[j])))
                {
                    flag=true;
                    goto last;
                }
last:
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

