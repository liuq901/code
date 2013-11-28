#include <cstdio>
int main()
{
    int k;
    scanf("%d",&k);
    double sum=0;
    for (int i=1;;i++)
    {
        sum+=1.0/i;
        if (sum>k)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

