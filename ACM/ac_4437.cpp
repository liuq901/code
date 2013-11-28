#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
using namespace std;
char b[260],s[10000];
int len,pos,tot,l[260],r[260];
map <char,int> a;
bool check(char c)
{
    return(c=='C' || c=='N' || c=='K' || c=='A' || c=='D' || c=='E' || c=='J');
}
int get()
{
    if (pos==len)
        throw("insufficient operands");
    int t=++tot;
    b[t]=s[pos++];
    if (islower(b[t]))
        return(t);
    else if (isupper(b[t]))
    {
        if (!check(b[t]))
            throw("invalid character");
        if (b[t]=='N')
            l[t]=get();
        else
        {
            l[t]=get();
            r[t]=get();
        }
    }
    else
        throw("invalid character");
    return(t);
}
bool calc(int x,int state)
{
    if (islower(b[x]))
        return(state>>a[b[x]]&1);
    if (b[x]=='N')
        return(!calc(l[x],state));
    bool p=calc(l[x],state),q=calc(r[x],state);
    if (b[x]=='C')
        return(p<=q);
    else if (b[x]=='K')
        return(p&q);
    else if (b[x]=='A')
        return(p|q);
    else if (b[x]=='D')
        return(!(p&q));
    else if (b[x]=='E')
        return(!(p^q));
    else
        return(p^q);
}
int main()
{
    while (1)
    {
        gets(s);
        len=strlen(s);
        if (len==0)
            break;
        try
        {
            pos=0;
            tot=0;
            get();
            if (pos!=len)
                throw("extraneous text");
        }
        catch (const char *S)
        {
            printf("%s is invalid: %s\n",s,S);
            continue;
        }
        int m=0;
        a.clear();
        for (int i=0;i<len;i++)
            if (islower(s[i]) && !a.count(s[i]))
                a[s[i]]=m++;
        int f1=0,f2=0;
        for (int i=0;i<1<<m;i++)
            if (calc(1,i))
                f1++;
            else
                f2++;
        printf("%s is valid: %s\n",s,f2==0?"tautology":f1==0?"contradiction":"contingent");
    }
    return(0);
}

