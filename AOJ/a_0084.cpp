#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
vector <string> split(char *s)
{
    int len=strlen(s);
    string now;
    vector <string> ret;
    for (int i=0;i<len;i++)
        if (s[i]==' ' || s[i]==',' || s[i]=='.')
        {
            if (!now.empty())
                ret.push_back(now);
            now="";
        }
        else
            now+=s[i];
    if (!now.empty())
        ret.push_back(now);
    return(ret);
}
char s[1100];
int main()
{
    gets(s);
    vector <string> a=split(s);
    bool first=true;
    for (int i=0;i<a.size();i++)
        if (a[i].size()>=3 && a[i].size()<=6)
        {
            if (!first)
                printf(" ");
            first=false;
            printf("%s",a[i].c_str());
        }
    printf("\n");
    return(0);
}

