#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;
char buf[110];
string read()
{
    gets(buf);
    int len=strlen(buf);
    string ret;
    for (int i=0;i<len;i++)
        if (isalpha(buf[i]))
            ret+=tolower(buf[i]);
    sort(ret.begin(),ret.end());
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(buf);
    while (T--)
    {
        static int id=0;
        printf("Case %d: %s\n",++id,read()==read()?"Yes":"No");
    }
    return(0);
}

