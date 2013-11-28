#include <cstdio>
#include <algorithm>
using namespace std;
bool f[10010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        fill(f+l,f+r+1,true);
    }
    printf("%d\n",count(f,f+n+1,false));
    return(0);
}

