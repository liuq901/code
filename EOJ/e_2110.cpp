#include <cstdio>
#include <map>
using namespace std;
map <int,int> M;
int a[10][10];
void dfs(int l,int sum)
{
    if (l==10)
    {
        M[sum]++;
        return;
    }
    for (int i=l;i<10;i++)
    {
        dfs(i+1,sum+a[l][i]);
        if (l!=1)
            dfs(i+1,sum-a[l][i]);
    }
}
void init()
{
    for (int i=1;i<10;i++)
    {
        a[i][i]=i;
        for (int j=i+1;j<10;j++)
            a[i][j]=a[i][j-1]*10+j;
    }
    dfs(1,0);
}
int main()
{
    init();
    int n;
    while (scanf("%d",&n)==1)
        printf("%d\n",M[n]);
    return(0);
}

