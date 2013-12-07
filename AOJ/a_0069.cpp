#include <cstdio>
char a[100][100];
bool check(int n,int m,int S,int T)
{
    int now=S;
    for (int i=1;i<=n;i++)
        if (a[i][now-1]=='1')
            now--;
        else if (a[i][now]=='1')
            now++;
    return(now==T);
}
void work(int n,int m,int S,int T)
{
    if (check(n,m,S,T))
    {
        printf("0\n");
        return;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<m;j++)
        {
            if (a[i][j]=='1' || a[i][j-1]=='1' || a[i][j+1]=='1')
                continue;
            a[i][j]='1';
            if (check(n,m,S,T))
            {
                printf("%d %d\n",i,j);
                return;
            }
            a[i][j]='0';
        }
    printf("1\n");
}
int main()
{
    int n,S,T,m;
    while (scanf("%d%d%d%d",&m,&S,&T,&n)==4)
    {
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        work(n,m,S,T);
    }
    return(0);
}

