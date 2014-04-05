#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        static int id=0;
        printf("Case %d: ",++id);
        if (n==1 || m==1)
            printf("%d\n",n*m);
        else if (n==2 || m==2)
            printf("%d\n",n*m/8*4+min(n*m%8,4));
        else
            printf("%d\n",(n*m+1)/2);
    }
    return(0);
}

