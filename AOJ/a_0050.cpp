#include <cstdio>
#include <string>
using namespace std;
char buf[100000];
int main()
{
    gets(buf);
    string s=buf;
    for (int i=0;i<s.size();i++)
        if (s.substr(i,5)=="apple")
        {
            printf("peach");
            i+=4;
        }
        else if (s.substr(i,5)=="peach")
        {
            printf("apple");
            i+=4;
        }
        else
            printf("%c",s[i]);
    printf("\n");
    return(0);
}

