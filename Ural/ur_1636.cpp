#include <cstdio>
int main()
{
    int a,b,s=0;
    scanf("%d%d",&a,&b);
    for (int i=1;i<=10;i++)
    {
        int x;
        scanf("%d",&x);
        s+=x*20;
    }
    printf("%s\n",b-s>=a?"No chance.":"Dirty debug :(");
    return(0);
}

