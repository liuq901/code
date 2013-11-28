#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
using namespace std;
struct data
{
    bool error;
    vector <string> a;
    data(char c)
    {
        error=false;
        a.clear();
        if (c=='E')
            error=true;
        else if (c=='A')
        {
            a.push_back("//");
            a.push_back("/+");
        }
        else
        {
            a.push_back("--");
            a.push_back("--");
        }
    }
    int height() const
    {
        return(a.size());
    }
    void print() const
    {
        if (error)
        {
            printf("error\n");
            return;
        }
        for (int i=0;i<a.size();i++)
            printf("%s\n",a[i].c_str());
    }
};
string s;
data turn(const data &a)
{
    if (a.error)
        return(data('E'));
    data ret('E');
    ret.error=false;
    for (int i=0;i<a.a[0].size();i++)
    {
        string now;
        for (int j=a.a.size()-1;j>=0;j--)
        {
            char ch=a.a[j][i];
            if (ch=='/')
                ch='\\';
            else if (ch=='\\')
                ch='/';
            else if (ch=='-')
                ch='|';
            else if (ch=='|')
                ch='-';
            now+=ch;
        }
        ret.a.push_back(now);
    }
    return(ret);
}
data dfs(int l,int r)
{
    if (l==r)
        return(data(s[l]));
    if (s[l]=='t')
        return(turn(dfs(l+5,r-1)));
    int now=0,pos;
    for (int i=l;i<=r;i++)
    {
        if (s[i]=='(')
            now++;
        if (s[i]==')')
            now--;
        if (now==1 && s[i]==',')
        {
            pos=i;
            break;
        }
    }
    data a=dfs(l+4,pos-1),b=dfs(pos+1,r-1);
    if (a.error || b.error || a.height()!=b.height())
        return(data('E'));
    for (int i=0;i<a.height();i++)
        a.a[i]+=b.a[i];
    return(a);
}
void work()
{
    static int id=0;
    printf("Quilt %d:\n",++id);
    dfs(0,s.size()-1).print();
}
int main()
{
    char ch;
    while ((ch=getchar())!=EOF)
    {
        if (ch==';')
        {
            work();
            s="";
            continue;
        }
        if (!isspace(ch))
            s+=ch;
    }
    return(0);
}

