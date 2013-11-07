#include <cstdio>
#include <string>
using namespace std;
string s[210];
char buf[100];
int main()
{
    int n,K,tot=0;
    scanf("%*d%d%d",&n,&K);
    gets(buf);
    for (int i=1;i<=n;i++)
    {
        gets(buf);
        s[i]=buf;
        for (int j=0;j<s[i].size();j++)
            if (s[i][j]=='#')
            {
                s[i].erase(j-1);
                break;
            }
        bool flag=true;
        for (int j=1;j<i;j++)
            if (s[i]==s[j])
            {
                flag=false;
                break;
            }
        tot+=flag;
        if (tot==K+1)
        {
            printf("%s\n",buf);
            break;
        }
    }
    return(0);
}

