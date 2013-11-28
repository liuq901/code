#include <cstdio>
int main()
{
    int B,R,Y,K;
    scanf("%d%d%d%d",&B,&R,&Y,&K);
    int ans=1;
    for (int i=1;i<=K;i++)
    {
        char buf[10];
        scanf("%s",buf);
        if (buf[0]=='B')
            ans*=B;
        else if (buf[0]=='R')
            ans*=R;
        else
            ans*=Y;
    }
    printf("%d\n",ans);
    return(0);
}

