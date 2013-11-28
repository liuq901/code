#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef unsigned long long ull;
const int lq=10007;
inline ull hash(const string &s)
{
    ull ret=0;
    for (int i=0;i<s.size();i++)
        ret=ret*lq+s[i];
    return(ret);
}
char buf[1000000];
vector <string> split(const string &s)
{
    vector <string> ret;
    string now;
    int cnt=0;
    for (int i=0;i<s.size();i++)
    {
        cnt+=s[i]=='"';
        if ((s[i]==' ' || s[i]=='\t') && cnt%2==0)
        {
            if (!now.empty())
                ret.push_back(now);
            now="";
        }
        else
            now+=s[i];
    }
    if (!now.empty())
        ret.push_back(now);
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        gets(buf);
        map <ull,string> variable,constant;
        bool flag=true,end=false;
        for (int i=1;i<=n;i++)
        {
            gets(buf);
            if (end)
                continue;
            string s;
            int len=strlen(buf),cnt=0;
            for (int i=0;i<len;i++)
            {
                cnt+=buf[i]=='"';
                if (buf[i]=='=' && cnt%2==0)
                    s+=" = ";
                else
                    s+=buf[i];
            }
            vector <string> a=split(s);
            switch (a.size())
            {
            case 1:
                printf("Script was KILLED.\n");
                end=true;
                break;
            case 2:
                if (a[0]=="Errmsg")
                    flag=a[1]=="ON";
                else if (a[0]=="Print")
                {
                    ull now=hash(a[1]);
                    map <ull,string> &M=a[1][0]=='$'?variable:constant;
                    if (M.count(now))
                    {
                        string tmp=M[now];
                        printf("%s\n",tmp[0]=='"'?tmp.substr(1,tmp.size()-2).c_str():tmp.c_str());
                    }
                    else if (a[1][0]=='$')
                    {
                        printf("NULL\n");
                        if (flag)
                            printf("NOTICE: Undefined Variable %s.\n",a[1].c_str());
                    }
                    else
                    {
                        printf("%s\n",a[1].c_str());
                        if (flag)
                            printf("NOTICE: Undefined Constant %s.\n",a[1].c_str());
                    }
                }
                else
                {
                    ull now=hash(a[1]);
                    map <ull,string> &M=a[1][0]=='$'?variable:constant;
                    if (M.count(now))
                    {
                        string tmp=M[now];
                        if (tmp[0]=='"')
                            printf("string: %s\n",tmp.c_str());
                        else
                            printf("integer: %s\n",tmp.c_str());
                    }
                    else if (a[1][0]=='$')
                    {
                        printf("NULL\n");
                        if (flag)
                            printf("NOTICE: Undefined Variable %s.\n",a[1].c_str());
                    }
                    else
                    {
                        printf("string: \"%s\"\n",a[1].c_str());
                        if (flag)
                            printf("NOTICE: Undefined Constant %s.\n",a[1].c_str());
                    }
                }
                break;
            case 3:
                ull now=hash(a[0]);
                map <ull,string> &M=a[0][0]=='$'?variable:constant;
                if (a[0][0]=='$' || !M.count(now))
                    M[now]=a[2];
                else if (flag)
                    printf("WARNING: Constant %s Already Defined!\n",a[0].c_str());
                break;
            }
        }
        if (T)
            printf("\n");
    }
    return(0);
}

