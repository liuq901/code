#include <cstdio>
inline int sqr(int x)
{
    return(x*x);
}
int main()
{
    int a,b,c,s1,s2;
    s1=s2=0;
    while (scanf("%d,%d,%d",&a,&b,&c)==3)
    {
        s1+=sqr(a)+sqr(b)==sqr(c);
        s2+=a==b;
    }
    printf("%d\n%d\n",s1,s2);
    return(0);
}

