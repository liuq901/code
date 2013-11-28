#include <cstdio>
#include <algorithm>
using namespace std;
bool f[5010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        f[x]=true;
    }
    printf("%d\n",count(f+1,f+n+1,false));
    return(0);
}

