#include <cstdio>
#include <string>
using namespace std;
char s[100000];
const char *calc(string s)
{
    if (s.size()<=3)
        return("NA");
    if (s.substr(0,2)==">'")
    {
        if (s.substr(s.size()-1,1)!="~")
            return("NA");
        s=s.substr(2,s.size()-3);
        if (s.size()%2==0 || s.size()==1)
            return("NA");
        int p=s.size()/2;
        if (s[p]!='#')
            return("NA");
        for (int i=0;i<p;i++)
            if (s[i]!='=' || s[p+i+1]!='=')
                return("NA");
        return("A");
    }
    if (s.substr(0,2)==">^")
    {
        if (s.substr(s.size()-2,2)!="~~")
            return("NA");
        s=s.substr(2,s.size()-4);
        if (s.size()%2==1 || s.size()==0)
            return("NA");
        for (int i=0;i<s.size();i+=2)
            if (s[i]!='Q' || s[i+1]!='=')
                return("NA");
        return("B");
    }
    return("NA");
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        printf("%s\n",calc(s));
    }
    return(0);
}
