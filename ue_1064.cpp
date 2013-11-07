#include <cstdio>
bool f[110][110];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        int x=(i+m)%n;
        if (!f[i][x])
        {
            f[i][x]=f[x][i]=true;
            printf("(%d,%d) ",i+1,x+1);
        }
    }
    printf("\n");
    return(0);
}

