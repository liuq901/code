#include <cstdio>
#include <cstring>
char s[100010];
int a[100010];
int main()
{
    int n,K;
    scanf("%d%d%s",&n,&K,s);
    for (int i=1;i<=n;i++)
        a[i]=s[i-1]-'0';
    int t=1;
    while (K)
    {
        if (t<=n-2 && t%2==1 && a[t]==4 && (a[t+1]==4 || a[t+1]==7) && a[t+2]==7)
        {
            if (K%2==1)
                a[t+1]=11-a[t+1];
            break;
        }
        if (t==n)
            break;
        if (a[t]==4 && a[t+1]==7)
        {
            if (t%2==1)
                a[t+1]=4;
            else
                a[t]=7;
            K--;
        }
        t++;
    }
    for (int i=1;i<=n;i++)
        printf("%d",a[i]);
    printf("\n");
    return(0);
}

