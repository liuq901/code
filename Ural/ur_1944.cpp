#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int l,r,u,d,a[260],b[260];
char ans[1000][1000];
inline void draw(int x,int y,char ch)
{
    ans[y-d][x-l]=ch;
}
void print()
{
    for (int i=u-d;i>=0;i--)
    {
        for (int j=0;j<=r-l;j++)
            printf("%c",ans[i][j]);
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        l=min(l,a[i]);
        r=max(r,a[i]);
        u=max(u,b[i]);
        d=min(d,b[i]);
    }
    memset(ans,'.',sizeof(ans));
    for (int i=l;i<=r;i++)
        draw(i,0,'-');
    for (int i=d;i<=u;i++)
        draw(0,i,'|');
    draw(0,0,'+');
    for (int i=1;i<=n;i++)
        draw(a[i],b[i],'*');
    print();
    return(0);
}

