#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const char *a[]={"abcde","fghij","klmno","pqrst","uvwxy","z.?! "};
char buf[100000];
string trans(char *s)
{
    int len=strlen(s);
    if (len&1)
        return("NA");
    string ret;
    for (int i=0;i<len;i+=2)
    {
        int x=s[i]-'0',y=s[i+1]-'0';
        if (x<1 || x>6 || y<1 || y>5)
            return("NA");
        ret+=a[x-1][y-1];
    }
    return(ret);
}
int main()
{
    while (scanf("%s",buf)==1)
        printf("%s\n",trans(buf).c_str());
    return(0);
}

