#include <cstdio>
#include <string>
using namespace std;
char buf[100000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d%s",&n,buf);
        string s=buf;
        s.erase(n-1,1);
        static int id=0;
        printf("%d %s\n",++id,s.c_str());
    }
    return(0);
}

