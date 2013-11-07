#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
map <string,int> M;
char buf[10000];
int main()
{
    int cnt=0;
    string ans1,ans2;
    while (scanf("%s",buf)==1)
    {
        if (++M[buf]>cnt)
        {
            cnt=M[buf];
            ans1=buf;
        }
        if (strlen(buf)>ans2.size())
            ans2=buf;
    }
    printf("%s %s\n",ans1.c_str(),ans2.c_str());
    return(0);
}

