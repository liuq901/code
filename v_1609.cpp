#include <cstdio>
#include <algorithm>
using namespace std;
int a[1510];
int main()
{
    int n,K;
    scanf("%d%d%d",&n,&a[1],&K);
    for (int i=2;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    bool flag=true;
    for (int i=2;i<=n;i++)
        if (a[i]-a[i-1]>K)
        {
            flag=false;
            break;
        }
    printf("%s\n",flag?"Yes":"No");
    return(0);
}

