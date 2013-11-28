#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector <char> a,b;
char s[10000];
bool isvar(char ch)
{
    return(ch>='p' && ch<='t');
}
bool isop(char ch)
{
    return(ch=='K' || ch=='A' || ch=='C' || ch=='E');
}
int main()
{
    while (1)
    {
        scanf("%s",s);
        if (strcmp(s,"0")==0)
            break;
        int len=strlen(s),cnt=0;
        a.clear();
        b.clear();
        for (int i=0;i<len;i++)
        {
            if (isvar(s[i]))
                a.push_back(s[i]);
            if (s[i]=='N')
                cnt++;
            if (isop(s[i]))
                b.push_back(s[i]);
        }
        if (a.empty())
            printf("no WFF possible\n");
        else
        {
            for (int i=1;i<=cnt;i++)
                printf("N");
            int n=min(b.size(),a.size()-1);
            for (int i=0;i<n;i++)
                printf("%c%c",b[i],a[i]);
            printf("%c\n",a[n]);
        }
    }
    return(0);
}

