#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char a[1010][1010];
inline double sqr(double x)
{
    return(x*x);
}
int main()
{
    int m,n,N;
    scanf("%d%d%d",&m,&n,&N);
    memset(a,'0',sizeof(a));
    for (int i=1;i<=N;i++)
    {
        int x,y,r,v;
        scanf("%d%d%d%d",&y,&x,&r,&v);
        x++,y++;
        for (int j=max(1,x-r);j<=min(n,x+r);j++)
        {
            int delta=int(sqrt(sqr(r)-sqr(j-x))+1e-8);
            int lower=max(1,y-delta),upper=min(m,y+delta);
            memset(a[j]+lower,v+'0',sizeof(char)*(upper-lower+1));
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            printf("%c",a[i][j]);
        printf("\n");
    }
    return(0);
}

