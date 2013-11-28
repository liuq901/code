#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010],b[1010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for (int i=1;i<=n;i++)
        a[i-1]++,a[i]++;
    sort(b+1,b+m+1);
    bool flag=true;
    for (int i=1;i<=m;i++)
    {
        int x=b[i];
        if (x>=1 && a[x]>=1 && a[x-1]>=1)
            a[x]--,a[x-1]--;
        else if (x<n && a[x]>=1 && a[x+1]>=1)
            a[x]--,a[x+1]--;
        else
        {
            flag=false;
            break;
        }
    }
    printf("%s\n",flag?"YES":"NO");
    return(0);
}

