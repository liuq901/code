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
        char a[30];
        for (int i=0;i<n;i++)
            a[i]=i+'A';
        a[n]='\0';
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=m;i++)
        {
            printf("%s\n",a);
            if (!next_permutation(a,a+n))
                break;
        }
    }
    return(0);
}

