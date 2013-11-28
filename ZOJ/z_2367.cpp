#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
#include <sstream>
#include <map>
#include <stack>
using namespace std;
const bool c[9][9]={
    {0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,1,0,1,1,1,1,1,1},
    {0,1,0,1,1,0,0,0,0},
    {0,1,0,1,1,0,0,0,0},
    {0,1,0,1,1,1,1,0,1},
    {0,1,0,1,1,1,1,0,1},
    {0,1,0,1,1,1,1,0,1},
    {0,1,0,1,1,1,1,0,1}};
char s[1000000];
map <string,string> a;
stack <int> num,op;
bool check(char c)
{
    return(c=='(' || c==')' || c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%');
}
string find(const string &p)
{
    if (a.find(p)==a.end())
        return(p);
    return(a[p]=find(a[p]));
}
int get(const string &p)
{
    string now=find(p);
    int ret=0;
    for (int i=0;i<now.size();i++)
    {
        if (!isdigit(now[i]))
            return(0);
        ret=ret*10+now[i]-'0';
    }
    return(ret);
}
int sign(int x)
{
    return(x<0?-1:x>0);
}
int power(int x,int y)
{
    if (x==0)
        return(0);
    if (x==1 || y==0)
        return(1);
    if (x==-1)
        return(y&1?-1:1);
    int ret=1;
    for (int i=1;i<=y;i++)
        ret*=x;
    return(ret);
}
bool work()
{
    int opt=op.top();
    op.pop();    
    if (opt==0)
        return(false);
    int x=num.top(),y;
    num.pop();
    if (opt!=2)
        y=num.top();
    if (opt==2)
        num.push(-x);
    else if (opt==3)
        num.top()=y+x;
    else if (opt==4)
        num.top()=y-x;
    else if (opt==5)
        num.top()=y*x;
    else if (opt==6)
        num.top()=y/x;
    else if (opt==7)
        num.top()=power(y,x);
    else if (opt==8)
        num.top()=sign(x)*sign(y)*(abs(y)%abs(x));
    return(true);
}
int calc(int l,int r)
{
    string tmp;
    while (!num.empty())
        num.pop();
    for (int i=l;i<=r;i++)
    {
        if (s[i]==' ')
            continue;
        if (!check(s[i]))
        {
            tmp+=s[i];
            continue;
        }
        if (tmp!="")
        {
            num.push(get(tmp));
            tmp="";
        }
        int now;
        if (s[i]=='(')
            now=0;
        else if (s[i]==')')
            now=1;
        else if (s[i]=='-')
            now=i==l || check(s[i-1]) && s[i-1]!=')'?2:4;
        else if (s[i]=='+')
            now=i==l || check(s[i-1]) && s[i-1]!=')'?-1:3;
        else if (s[i]=='*')
            now=5;
        else if (s[i]=='/')
            now=6;
        else if (s[i]=='^')
            now=7;
        else if (s[i]=='%')
            now=8;
        else
            now=-1;
        if (now==-1)
            continue;
        while (!op.empty() && c[op.top()][now])
            if (!work())
                break;
        if (now!=1)
            op.push(now);
    }
    if (tmp!="")
        num.push(get(tmp));
    while (!op.empty())
        work();
    return(num.top());
}
void define(const string &p,const string &q)
{
    if (a.find(p)==a.end() && p!=find(q))
        a[p]=q;
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(s);
    gets(s);
    while (T--)
    {
        a.clear();
        while (gets(s))
        {
            int len=strlen(s);
            if (len==0)
                break;
            for (int i=0;i<len;i++)
                s[i]=tolower(s[i]);
            if (s[0]=='p')
                printf("%d\n",calc(6,len-1));
            else
            {
                stringstream sin(s);
                string p,q;
                sin>>p>>p>>q;
                define(p,q);
            }
        }
        if (T)
            printf("\n");
    }
    return(0);
}

