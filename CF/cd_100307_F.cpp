#include <cstdio>
bool ans[1010];
char a[1010][20];
bool check(char a[],char b[])
{
    for (int i=0;i<9;i++)
        if (a[i]!=b[i] && a[i]!='*')
            return(false);
    return(true);
}
int main()
{
    freopen("fraud.in","r",stdin);
    freopen("fraud.out","w",stdout);
    int n;
    scanf("%s%d",a[0],&n);
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%s",a[i]);
        ans[i]=check(a[0],a[i]);
        cnt+=ans[i];
    }
    printf("%d\n",cnt);
    for (int i=1;i<=n;i++)
        if (ans[i])
            printf("%s\n",a[i]);
    return(0);
}

