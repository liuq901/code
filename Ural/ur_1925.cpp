#include <cstdio>
int main()
{
    int n,sum;
    scanf("%d%d",&n,&sum);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        sum+=x-(y+2);
    }
    if (sum>=2)
        printf("%d\n",sum-2);
    else
        printf("Big Bang!\n");
    return(0);
}

