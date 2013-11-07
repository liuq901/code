#include <cstdio>
#include <cstring>
int a[110],b[110],ans[210];
char s[110];
void read(int *a)
{
    scanf("%s",s);
    a[0]=strlen(s);
    for (int i=1;i<=a[0];i++)
        a[i]=s[a[0]-i]-'0';
}
void multi()
{
    memset(ans,0,sizeof(ans));
    ans[0]=a[0]+b[0];
    for (int i=1;i<=a[0];i++)
        for (int j=1;j<=b[0];j++)
        {
            ans[i+j-1]+=a[i]*b[j];
            ans[i+j]+=ans[i+j-1]/10;
            ans[i+j-1]%=10;
        }
    while (ans[0]>1 && !ans[ans[0]])
        ans[0]--;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        read(a);
        read(b);
        multi();
        for (int i=ans[0];i;i--)
            printf("%d",ans[i]);
        printf("\n");
    }
    return(0);
}

