#include <cstdio>
#include <set>
using namespace std;
int a[30];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    set <int> S;
    for (int i=0;i<1<<n;i++)
    {
        int sum=0;
        for (int j=1;j<=n;j++)
            if (i>>j-1&1)
                sum+=a[j];
        S.insert(sum);
    }
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int x;
        scanf("%d",&x);
        printf("%s\n",S.count(x)?"yes":"no");
    }
    return(0);
}

