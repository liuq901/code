#include <cstdio>
int a[6],b[6],c[6];
void calc(int n,int *a)
{
    for (int i=0;i<6;i++)
    {
        a[i]=n&1;
        n>>=1;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        calc(h,a);
        calc(m,b);
        calc(s,c);
        static int id=0;
        printf("%d ",++id);
        for (int i=5;i>=0;i--)
            printf("%d%d%d",a[i],b[i],c[i]);
        printf(" ");
        for (int i=5;i>=0;i--)
            printf("%d",a[i]);
        for (int i=5;i>=0;i--)
            printf("%d",b[i]);
        for (int i=5;i>=0;i--)
            printf("%d",c[i]);
        printf("\n");
    }
    return(0);
}

