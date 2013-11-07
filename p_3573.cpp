#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
char buf[100001];
string a[30][30][100];
bool isword(const string &s)
{
    if (s.size()>=50)
        return(false);
    for (int i=0;i<s.size();i++)
        if (!isalpha(s[i]))
            return(false);
    if (s.size()==1)
        return(true);
    for (int i=1;i<s.size();i++)
        if (isupper(s[i])!=isupper(s[1]))
            return(false);
    if (islower(s[0]) && isupper(s[1]))
        return(false);
    return(true);
}
void dealword(const string &s)
{
    int len=s.size(),x=tolower(s[0])-'a',y=tolower(s[len-1])-'a';
    string p=s;
    for (int i=0;i<len;i++)
        p[i]=tolower(p[i]);
    if (a[x][y][len]=="")
        a[x][y][len]=p;
    else if (a[x][y][len]!=p)
        a[x][y][len]="-";
    printf("%s",s.c_str());
}
bool isabb(const string &s)
{
    if (s.size()<=2 || s.size()>4)
        return(false);
    int len=s.size();
    if (!isalpha(s[0]) || !isalpha(s[len-1]) || s[1]=='0')
        return(false);
    if (islower(s[0]) && isupper(s[len-1]))
        return(false);
    int now=0;
    for (int i=1;i<len-1;i++)
    {
        if (!isdigit(s[i]))
            return(false);
        now=now*10+s[i]-'0';
    }
    if (now<2 || now>30)
        return(false);
    return(true);
}
void dealabb(const string &s)
{
    int len=s.size(),x=tolower(s[0])-'a',y=tolower(s[len-1])-'a',now=0;
    for (int i=1;i<len-1;i++)
        now=now*10+s[i]-'0';
    now+=2;
    string p=a[x][y][now];
    if (p=="" || p=="-")
    {
        printf("%s",s.c_str());
        return;
    }
    if (isupper(s[0]))
        p[0]=toupper(p[0]);
    if (isupper(s[len-1]))
        for (int i=1;i<p.size();i++)
            p[i]=toupper(p[i]);
    printf("%s",p.c_str());
}
int main()
{
    while (gets(buf))
    {
        int len=strlen(buf);
        if (len==0)
            break;
        buf[len]='\n';
        string now;
        for (int i=0;i<=len;i++)
        {
            if (isalnum(buf[i]))
            {
                now+=buf[i];
                continue;
            }
            if (now!="")
            {
                if (isword(now))
                    dealword(now);
                else if (isabb(now))
                    dealabb(now);
                else
                    printf("%s",now.c_str());
                now="";
            }
            printf("%c",buf[i]);
        }
    }
    return(0);
}

