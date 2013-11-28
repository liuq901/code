#include <cstdio>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%s\n",n*m&1?"[second]=:]":"[:=[first]");
    return(0);
}

