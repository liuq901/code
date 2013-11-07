#include <cstdio>
int main()
{
    int a[4],b[4];
    while (scanf("%d",&a[0])==1)
    {
        for (int i=1;i<4;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<4;i++)
            scanf("%d",&b[i]);
        int x,y;
        x=y=0;
        for (int i=0;i<4;i++)
        {
            x+=a[i]==b[i];
            for (int j=0;j<4;j++)
                y+=a[i]==b[j];
        }
        printf("%d %d\n",x,y-x);
    }
    return(0);
}

