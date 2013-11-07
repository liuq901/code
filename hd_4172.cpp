#include <cstdio>
#include <vector>
#include <string>
#include <utility>
using namespace std;
char buf[1000];
vector <pair <string,string> > a;
bool check(const string s)
{
    if (s.empty())
        return(true);
    for (int i=0;i<a.size();i++)
    {
        int k=s.find(a[i].first);
        if (k!=string::npos)
            return(check(s.substr(0,k)+a[i].second+s.substr(k+a[i].first.size())));
    }
    return(false);
}
void init()
{
    a.push_back(make_pair("aa",""));
    a.push_back(make_pair("bb",""));
    a.push_back(make_pair("cc",""));
    a.push_back(make_pair("abab","baba"));
    a.push_back(make_pair("acac","caca"));
    a.push_back(make_pair("bcbc","cbcb"));
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",buf);
        string s=buf;
        printf("%s\n",check(s)?"closed":"open");
    }
    return(0);
}

