#include <cstdio>
#include <cstdlib>
int main()
{
    int l1,l2,n1,n2;
    scanf("%d%d%d%d",&l1,&l2,&n1,&n2);
    printf("%d\n",abs((n2-n1-1)*(l1+2*l2)+2*l2));
    return(0);
}

