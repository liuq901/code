#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
const string error[]={"Double declaration","Unknown variable","No such function","Invalid initialization"};
const string type_name[]={"int","real","string"};
struct function
{
    int ret;
    vector <int> arg;
    function(int ret,vector <int> arg):ret(ret),arg(arg){}
};
vector <function> a[110];
vector <string> print;
map <string,int> func,type,var;
char buf[100000];
void read()
{
    char ch;
    int len=0;
    while (1)
    {
        ch=getchar();
        if (isalpha(ch))
            break;
    }
    buf[len++]=ch;
    while ((ch=getchar())!=')')
        buf[len++]=ch;
    buf[len++]=ch;
    buf[len]='\0';
}
int Hash(const string &s)
{
    if (func.count(s))
        return(func[s]);
    int p=func.size();
    func[s]=p;
    return(p);
}
vector <string> getarg(char *buf,int l,int r)
{
    vector <string> ret;
    string tmp;
    for (int i=l;i<=r;i++)
    {
        if (isalpha(buf[i]))
        {
            tmp+=buf[i];
            continue;
        }
        if (tmp!="")
        {
            ret.push_back(tmp);
            tmp="";
        }
    }
    return(ret);
}
pair <int,int> main2()
{
    int n;
    scanf("%d",&n);
    type["int"]=0;
    type["real"]=1;
    type["string"]=2;
    for (int T=1;T<=n;T++)
    {
        read();
        int len=strlen(buf),l,r;
        for (int i=0;i<len;i++)
        {
            if (buf[i]=='(')
                l=i;
            if (buf[i]==')')
                r=i;
        }
        vector <string> now=getarg(buf,l+1,r);
        vector <int> tmp;
        for (int i=0;i<now.size();i++)
            tmp.push_back(type[now[i]]);
        string name;
        for (int i=0;i<l;i++)
            name+=buf[i];
        scanf("%*s%s",buf);
        int ret=type[buf];
        a[Hash(name)].push_back(function(ret,tmp));
    }
    scanf("%d",&n);
    for (int T=1;T<=n;T++)
    {
        scanf("%s",buf);
        string now_type=buf;
        scanf("%s%*s",buf);
        string name=buf;
        if (var.count(name))
            return(make_pair(T,0));
        read();
        int len=strlen(buf),l,r;
        for (int i=0;i<len;i++)
        {
            if (buf[i]=='(')
                l=i;
            if (buf[i]==')')
                r=i;
        }
        vector <string> now=getarg(buf,l+1,r);
        vector <int> tmp;
        for (int i=0;i<now.size();i++)
        {
            if (!var.count(now[i]))
                return(make_pair(T,1));
            tmp.push_back(var[now[i]]);
        }
        string funct;
        for (int i=0;i<l;i++)
            funct+=buf[i];
        if (!func.count(funct))
            return(make_pair(T,2));
        int fun=func[funct],k=-1;
        for (int i=0;i<a[fun].size();i++)
            if (a[fun][i].arg==tmp)
            {
                k=i;
                break;
            }
        if (k==-1)
            return(make_pair(T,2));
        int ret=a[fun][k].ret;
        if (now_type=="auto")
        {
            print.push_back(name);
            var[name]=ret;
        }
        else if (ret!=type[now_type])
            return(make_pair(T,3));
        else
            var[name]=ret;
    }
    return(make_pair(0,0));
}
int main()
{
    pair <int,int> op=main2();
    if (op.first==0)
        for (int i=0;i<print.size();i++)
            printf("%s : %s\n",print[i].c_str(),type_name[var[print[i]]].c_str());
    else
        printf("Error on line %d: %s\n",op.first,error[op.second].c_str());
    return(0);
}

