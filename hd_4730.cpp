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
        scanf("%s",buf);
        string s=buf;
        if (s.size()>=4 && s.substr(s.size()-4,4)=="desu")
            s=s.substr(0,s.size()-4)+"nanodesu";
        else
            s+="nanodesu";
        static int id=0;
        printf("Case #%d: %s\n",++id,s.c_str());
    }
    return(0);
}

