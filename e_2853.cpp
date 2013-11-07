#include <cstdio>
#include <set>
using namespace std;
set <int> s,t;
int a[1010],b[1010];
void print()
{
    printf("{");
    bool first=true;
    for (set <int>::iterator k=s.begin();k!=s.end();k++)
    {
        if (!first)
            printf(",");
        first=false;
        printf("%d",*k);
    }
    printf("}\n");
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        t.insert(a[i]);
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        if (t.count(b[i]))
            s.insert(b[i]);
    }
    print();
    s.clear();
    for (int i=1;i<=n;i++)
        s.insert(a[i]);
    for (int i=1;i<=m;i++)
        s.insert(b[i]);
    print();
    for (int i=1;i<=n;i++)
        s.insert(a[i]);
    for (int i=1;i<=m;i++)
    {
        set <int>::iterator k=s.find(b[i]);
        if (k!=s.end())
            s.erase(k);
    }
    print();
    return(0);
}

