#include <cstdio>
int calc(int x)
{
    int ret=0,p=0;
    while (x)
    {
        ret|=x%10<<p;
        x/=10;
        p++;
    }
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b,c,d;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        int A,B,C,D;
        scanf("%d.%d.%d.%d",&A,&B,&C,&D);
        static int id=0;
        printf("Case %d: %s\n",++id,a==calc(A) && b==calc(B) && c==calc(C) && d==calc(D)?"Yes":"No");
    }
    return(0);
}

