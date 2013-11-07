#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m,a[10010],b[110][110];
bool check()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (i>1 && abs(b[i][j]-b[i-1][j])==1)
                return(false);
            if (j>1 && abs(b[i][j]-b[i][j-1])==1)
                return(false);
        }
    return(true);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n*m;i++)
        a[i]=i;
    bool flag=false;
    for (int T=0;T<=1000;T++)
    {
        random_shuffle(a+1,a+n*m+1);
        int t=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                b[i][j]=a[++t];
        if (check())
        {
            flag=true;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                    printf("%d%c",b[i][j],j==m?'\n':' ');
            break;
        }
    }
    if (!flag)
        printf("-1\n");
    return(0);
}

