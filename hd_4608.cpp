#include <cstdio>
#include <cstring>
char buf[100010];
int len,a[100010];
void plus()
{
    a[1]++;
    for (int i=1;;i++)
    {
        if (a[i]<10)
           break;
        a[i+1]++;
        a[i]-=10;
        if (i+1>len)
            len=i+1;
    }
}
bool check()
{
    int sum=0;
    for (int i=1;i<=len;i++)
        sum+=a[i];
    return(sum%10==0);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",buf);
        len=strlen(buf);
        for (int i=1;i<=len;i++)
            a[i]=buf[len-i]-'0';
        for (int i=len+1;i<=len+3;i++)
            a[i]=0;
        while (1)
        {
            plus();
            if (check())
                break;
        }
        for (int i=len;i;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return(0);
}

