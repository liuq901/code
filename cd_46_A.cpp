#include <cstdio>
int main()
{
    int n,now=0;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        now=(now+i)%n;
        printf("%d%c",now+1,i==n-1?'\n':' ');
    }
    return(0);
}

