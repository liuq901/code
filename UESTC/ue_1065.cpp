#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
    void in()
    {
        scanf("%d%d",&x,&y);
    }
    void print()
    {
        printf("(%d,%d) ",x,y);
    }
};
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x || a.x==b.x && a.y<b.y);
}
point a[1000000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        a[i].in();
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        a[i].print();
    printf("\n");
    for (int i=n;i;i--)
        a[i].print();
    printf("\n");
    return(0);
}

