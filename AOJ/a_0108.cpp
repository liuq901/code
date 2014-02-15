#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        vector <int> a(n);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int cnt=0;
        while (1)
        {
            map <int,int> M;
            for (int i=0;i<n;i++)
                M[a[i]]++;
            vector <int> b(n);
            for (int i=0;i<n;i++)
                b[i]=M[a[i]];
            if (a==b)
                break;
            cnt++;
            a=b;
        }
        printf("%d\n",cnt);
        for (int i=0;i<n;i++)
            printf("%d%c",a[i],i==n-1?'\n':' ');
    }
    return(0);
}

