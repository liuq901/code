#include <cstdio>
double oil[1000],dis[1000];
int main()
{
    int len;
    scanf("%d",&len);
    int n=0;
    oil[0]=dis[0]=0;
    while (1)
    {
        n++;
        dis[n]=dis[n-1]+500.0/(2*n-1);
        oil[n]=oil[n-1]+500;
        if (dis[n]>=len)
            break;
    }
    n--;
    for (int i=n;i;i--)
        printf("%.2f ",len-dis[i]);
    printf("\n");
    for (int i=n;i;i--)
        printf("%.2f ",oil[i]);
    printf("\n");
    return(0);
}

