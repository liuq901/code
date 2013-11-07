#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
set <int> s;
int a[1010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s.insert(a[i]);
    }
    sort(a+1,a+n+1);
    bool flag=false;
    int x,y,z;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (s.count(a[j]*2-a[i]))
            {
                flag=true;
                x=a[i],y=a[j],z=a[j]*2-a[i];
                goto last;
            }
last:
    if (!flag)
        printf("Sequence is 3-free.\n");
    else
        printf("Sequence is not 3-free. Witness: %d,%d,%d.\n",x,y,z);
    return(0);
}

