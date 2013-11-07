#include <cstdio>
#include <cstring>
char s[1000000];
int main()
{
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    int ans=0,left=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        if (len+1<=left)
            left-=len+1;
        else
        {
            ans++;
            left=w-len;
        }
    }
    printf("%d\n",(ans+h-1)/h);
    return(0);
}

