#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int pos[300010],b[300010],a[300010][2];
bool cap[300010];
set <int> s;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n*3;i++)
    {
        scanf("%d",&b[i]);
        pos[b[i]]=i;
    }
    for (int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if (pos[x]>pos[y])
            swap(x,y);
        if (pos[x]>pos[z])
            swap(x,z);
        a[x][0]=y,a[x][1]=z;
        cap[x]=true;
    }
    int K;
    scanf("%d",&K);
    if (!cap[K])
    {
        for (int i=1;i<=3*n;i++)
        {
            if (i==K)
                continue;
            if (i!=1)
                printf(" ");
            printf("%d",i);
        }
        printf("\n");
    }
    else
    {
        for (int i=1;i<pos[K];i++)
        {
            int x=b[i];
            if (cap[x])
            {
                s.insert(x);
                s.insert(a[x][0]);
                s.insert(a[x][1]);
            }
        }
        s.insert(a[K][0]);
        s.insert(a[K][1]);
        int M=max(a[K][0],a[K][1]);
        bool first=true;
        for (set <int>::iterator k=s.begin();k!=s.end();k++)
        {
            if (*k>M)
                continue;
            if (!first)
                printf(" ");
            first=false;
            printf("%d",*k);
        }
        s.erase(s.upper_bound(M),s.end());
        for (int i=1;i<=3*n;i++)
        {
            if (i==K || s.count(i))
                continue;
            if (!first)
                printf(" ");
            first=false;
            printf("%d",i);
        }
        printf("\n");
    }
    return(0);
}

