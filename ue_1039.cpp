#include <cstdio>
#include <string>
using namespace std;
char buf[1000];
int main()
{
    gets(buf);
    string s=buf;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%s\n",s.substr(x,y).c_str());
    }
    return(0);
}

