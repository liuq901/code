#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int c[260],d[260],f[4010][4010];
char a[4010],b[4010];
int main()
{
    int ti,td,tr,te;
    scanf("%d%d%d%d%s%s",&ti,&td,&tr,&te,a+1,b+1);
    int n=strlen(a+1),m=strlen(b+1);
    memset(f,63,sizeof(f));
    f[0][0]=0;
    for (int i=1;i<=n;i++)
        f[i][0]=i*td;
    for (int i=1;i<=m;i++)
        f[0][i]=i*ti;
    for (int i=1;i<=n;i++)
    {
        memset(d,0,sizeof(d));
        for (int j=1;j<=m;j++)
        {
            f[i][j]=min(min(f[i-1][j]+td,f[i][j-1]+ti),f[i-1][j-1]+tr*(a[i]!=b[j]));
            int x=c[b[j]],y=d[a[i]];
            if (x!=0 && y!=0)
                f[i][j]=min(f[i][j],f[x-1][y-1]+(i-x-1)*td+(j-y-1)*ti+te);
            d[b[j]]=j;
        }
        c[a[i]]=i;
    }
    printf("%d\n",f[n][m]);
    return(0);
}

