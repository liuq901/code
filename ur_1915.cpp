#include <cstdio>
#include <vector>
using namespace std;
int m,a[10000010];
void copy()
{
    if (m>1000000)
        return;
    for (int i=1;i<=m;i++)
        a[i+m]=a[i];
    m<<=1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if (x>0)
            a[++m]=x;
        else if (x==-1)
            printf("%d\n",a[m--]);
        else
            copy();
    }
    return(0);
}

