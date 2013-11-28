#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;
char a[10000],b[10000],s[10000];
set <string> S;
int main()
{
    scanf("%*s");
    while (1)
    {
        scanf("%s",s);
        if (s[0]=='#')
            break;
        int len=strlen(s);
        for (int i=0;i<len;i++)
            if (s[i]=='-')
                s[i]=' ';
        sscanf(s,"%s%s",a,b);
        S.insert(a);
        S.insert(b);
    }
    printf("%d\n",max(int(S.size())-1,0));
    return(0);
}

