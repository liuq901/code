#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,K,L;
void work1()
{
    if (max(n,m)!=L-1)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                printf("A");
            printf("\n");
        }
    }
}
char ans[110][110];
void work2()
{
    if (L==2)
    {
        if (min(n,m)!=1)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=m;j++)
                    printf("%c",i+j&1?'A':'B');
                printf("\n");
            }
        }
        return;
    }
    bool transpose=false;
    if (n>m)
    {
        swap(n,m);
        transpose=true;
    }
    int sum='A'+'B';
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m-(L-1);j++)
        {
            if (j%4==1)
                ans[i][j]='A'+(i&1);
            if (j%4==2)
                ans[i][j]=sum-ans[i][j-1];
            if (j%4==3)
                ans[i][j]=ans[i][j-1];
            if (j%4==0)
                ans[i][j]=sum-ans[i][j-1];
        }
    for (int i=1;i<=n;i++)
    {
        ans[i][m-(L-1)+1]=m-(L-1)==0?'A':sum-ans[i][m-(L-1)];
        for (int j=m-(L-1)+2;j<=m;j++)
            ans[i][j]=ans[i][j-1];
    }
    printf("YES\n");
    if (!transpose)
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                printf("%c",ans[i][j]);
            printf("\n");
        }
    else
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
                printf("%c",ans[j][i]);
            printf("\n");
        }
}
void work3()
{
    if (L==2)
    {
        if (min(n,m)!=1)
            printf("NO\n");
        else
        {
            printf("YES\n");
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=m;j++)
                    printf("%c",i+j&1?'A':'B');
                printf("\n");
            }
        }
        return;
    }
    printf("YES\n");
    L--;
    for (int i=1;i<=n;i++)
    {
        int p=(i-1)/L&1;
        if (p==0)
            for (int j=1;j<=m;j++)
            {
                int q=(j-1)/L%3;
                printf("%c",'A'+q);
            }
        else
            for (int j=1;j<=m;j++)
            {
                int q=(j-1)%(3*L);
                if (q==0)
                    printf("B");
                else if (q<=L)
                    printf("C");
                else if (q<=2*L)
                    printf("A");
                else
                    printf("B");
            }
        printf("\n");
    }
}
void work()
{
    printf("YES\n");
    L--;
    for (int i=1;i<=n;i++)
    {
        int p=(i-1)/L&1;
        for (int j=1;j<=m;j++)
        {
            int q=(j-1)/L&1;
            printf("%c",'A'+2*p+q);
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&K,&L);
    if (max(n,m)<L-1)
        printf("NO\n");
    else if (K==1)
        work1();
    else if (K==2)
        work2();
    else if (K==3)
        work3();
    else
        work();
    return(0);
}

