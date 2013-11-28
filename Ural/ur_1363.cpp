#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[310][310],c[310][310],ans[310][310];
void modify(int x,int y,int value)
{
    for (int i=x;i<=n;i+=i&-i)
        for (int j=y;j<=m;j+=j&-j)
            c[i][j]+=value;
}
int get(int x,int y)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        for (int j=y;j;j-=j&-j)
            ret+=c[i][j];
    return(ret);
}
bool check()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int x1=max(i-10,1),y1=max(j-10,1),x2=min(i+10,n),y2=min(j+10,m);
            int sum=get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1);
            int num=(x2-x1+1)*(y2-y1+1);
            if (abs(sum)>20*num)
                return(false);
        }
    return(true);
}
bool work()
{
    memset(c,0,sizeof(c));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            ans[i][j]=rand()%255<=a[i][j]?255:0;
            modify(i,j,ans[i][j]-a[i][j]);
        }
    return(check());
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int t=max(j-10,1);
            int sum=get(i,j)-get(i-1,j)-get(i,t-1)+get(i-1,t-1);
            int s1=abs(sum+255-a[i][j]),s2=abs(sum-a[i][j]);
            ans[i][j]=s1<s2?255:0;
            modify(i,j,ans[i][j]-a[i][j]);
        }
    if (!check())
        while (!work());
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            printf("%d%c",ans[i][j],j==m?'\n':' ');
    return(0);
}

