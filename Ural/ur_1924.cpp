#include <cstdio>
int a[60];
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for (int i=1;i<=n;i++)
        sum+=i;
    printf("%s\n",sum&1?"grimy":"black");
    return(0);
}

