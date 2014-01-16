#include <cstdio>
#include <algorithm>
using namespace std;
int d[100010],b[100010],a[200010][3];
void dfs(int x,int father)
{
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        d[y]=d[x]+a[i][1];
        dfs(y,x);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++,y++;
        a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
        a[i+n][0]=x,a[i+n][1]=z,a[i+n][2]=b[y],b[y]=i+n;
    }
    dfs(1,0);
    int k=max_element(d+1,d+n+1)-d;
    d[k]=0;
    dfs(k,0);
    printf("%d\n",*max_element(d+1,d+n+1));
    return(0);
}

