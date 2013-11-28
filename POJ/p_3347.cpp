#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=60;
int X[N],Y[N],l[N],a[100000],id[100000];
bool f[N];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        memset(a,0,sizeof(a));
        int len=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&l[i]);
            X[i]=Y[i]=l[i];
            for (int j=0;j<i;j++)
                X[i]=max(X[i],X[j]+2*min(l[i],l[j]));
            for (int j=X[i]-l[i];j<X[i]+l[i];j++)
                if (Y[i]>a[j])
                {
                    a[j]=Y[i];
                    id[j]=i;
                }
            len=max(len,X[i]+l[i]);
        }
        memset(f,0,sizeof(f));
        for (int i=0;i<len;i++)
            f[id[i]]=true;
        bool first=true;
        for (int i=1;i<=n;i++)
            if (f[i])
            {
                if (!first)
                    printf(" ");
                first=false;
                printf("%d",i);
            }
        printf("\n");
    }
    return(0);
}

