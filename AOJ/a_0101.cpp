#include <cstdio>
#include <string>
using namespace std;
char buf[1000000];
int main()
{
    int T;
    scanf("%d",&T);
    gets(buf);
    while (T--)
    {
        gets(buf);
        string s=buf;
        for (int i=0;i<s.size();i++)
            if (s.substr(i,7)=="Hoshino")
            {
                printf("Hoshina");
                i+=6;
            }
            else
                printf("%c",s[i]);
        printf("\n");
    }
    return(0);
}

