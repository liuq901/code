#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;
map <string,int> stu,pro;
char buf[1000];
string tmp[2010];
int num[2010],c[2010],a[2010][10],t[2010][10];
int hash(map <string,int> &M,const string &s)
{
    if (!M.count(s))
    {
        int id=M.size();
        M[s]=id;
    }
    return(M[s]);
}
int get(const string &s)
{
    if (s[0]=='A')
        return(95);
    else if (s[0]=='P')
        return(90);
    else if (s[0]=='W')
        return(70);
    else
        return(50);
}
inline bool cmp(int x,int y)
{
    return(num[x]<num[y]);
}
int main()
{
    int n;
    scanf("%d",&n);
    gets(buf);
    for (int i=1;i<=n;i++)
    {
        gets(buf);
        string s=buf;
        c[i]=i;
        for (int j=0;j<s.size();j++)
            if (s[j]=='_')
            {
                num[i]=atoi(s.substr(0,j).c_str());
                s.erase(0,j+1);
                break;
            }
        tmp[i]=s;
    }
    sort(c+1,c+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        string s=tmp[c[i]];
        int x,y,score;
        for (int i=s.size()-1;i>=0;i--)
            if (s[i]=='.')
            {
                s.erase(i);
                break;
            }
        for (int i=s.size()-1;i>=0;i--)
            if (s[i]=='_')
            {
                y=hash(pro,s.substr(i+1));
                s.erase(i);
                break;
            }
        for (int i=s.size()-1;i>=0;i--)
            if (s[i]=='_')
            {
                score=get(s.substr(i+1));
                s.erase(i);
                break;
            }
        x=hash(stu,s);
        if (a[x][y]==0 && score==95)
            score=100;
        a[x][y]=max(a[x][y],score);
    }
    for (map <string,int>::iterator k=stu.begin();k!=stu.end();k++)
    {
        int x=k->second;
        printf("%s %d\n",k->first.c_str(),accumulate(a[x],a[x]+6,0));
    }
    return(0);
}

