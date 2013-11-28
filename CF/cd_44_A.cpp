#include <cstdio>
#include <string>
#include <utility>
#include <set>
using namespace std;
set <pair <string,string> > S;
char s1[10000],s2[10000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s%s",s1,s2);
        S.insert(make_pair(string(s1),string(s2)));
    }
    printf("%d\n",S.size());
    return(0);
}

