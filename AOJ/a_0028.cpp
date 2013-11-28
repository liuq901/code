#include <cstdio>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
    int x;
    while (scanf("%d",&x)==1)
        a[x]++;
    int p=*max_element(a,a+101);
    for (int i=0;i<=100;i++)
        if (a[i]==p)
            printf("%d\n",i);
    return(0);
}

