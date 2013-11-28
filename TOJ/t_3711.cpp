#include <cstdio>
const int a[][2]={{220,284},{1184,1210},{2620,2924},{5020,5564},{6232,6368},{10744,10856},{12285,14595},{17296,18416},{63020,76084}};
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;;i++)
    {
        if (a[i][0]>=n)
        {
            printf("%d %d\n",a[i][0],a[i][1]);
            break;
        }
        if (a[i][1]>=n)
        {
            printf("%d %d\n",a[i][1],a[i][0]);
            break;
        }
    }
    return(0);
}

