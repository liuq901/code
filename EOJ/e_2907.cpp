#include <cstdio>
bool prime(int n)
{
    for (int i=2;i*i<=n;i++)
        if (n%i==0)
            return(false);
    return(true);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
        printf("%s\n",n==4 || n!=1 && prime(n)?"NO":"YES");
    return(0);
}

