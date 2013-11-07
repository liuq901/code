#include <cstdio>
#include <vector>
#include <string>
using namespace std;
vector <string> a[260];
char s[10];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s);
        a[s[0]].push_back(s);
    }
    scanf("%s",s);
    for (int i=0;i<a[s[0]].size();i++)
        printf("%s\n",a[s[0]][i].c_str());
    return(0);
}

