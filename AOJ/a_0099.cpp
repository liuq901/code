#include <cstdio>
#include <set>
#include <utility>
using namespace std;
int a[1000010];
int main()
{
    set <pair <int,int> > s;
    int n,Q;
    scanf("%d%d",&n,&Q);
    while (Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        s.erase(make_pair(a[x],x));
        a[x]-=y;
        s.insert(make_pair(a[x],x));
        printf("%d %d\n",s.begin()->second,-s.begin()->first);
    }
    return(0);
}

