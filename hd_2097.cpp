#include <cstdio>
bool check(int n)
{
    int a,b,c;
    a=b=c=0;
    for (int i=n;i;i/=10)
        a+=i%10;
    for (int i=n;i;i/=16)
        b+=i%16;
    for (int i=n;i;i/=12)
        c+=i%12;
    return(a==b && a==c);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        printf("%d is%sa Sky Number.\n",n,check(n)?" ":" not ");
    }
    return(0);
}

