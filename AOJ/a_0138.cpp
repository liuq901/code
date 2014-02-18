#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
pair <double,int> a[10],b[10];
int main()
{
    for (int i=1;i<=3;i++)
    {
        for (int j=1;j<=8;j++)
            scanf("%d%lf",&a[j].second,&a[j].first);
        sort(a+1,a+9);
        for (int j=1;j<=2;j++)
            printf("%d %.2f\n",a[j].second,a[j].first);
        b[i]=a[3];
    }
    sort(b+1,b+4);
    for (int i=1;i<=2;i++)
        printf("%d %.2f\n",b[i].second,b[i].first);
    return(0);
}

