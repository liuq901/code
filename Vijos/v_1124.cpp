#include <iostream>
#include <utility>
#include <string>
#include <set>
using namespace std;
pair <string,string> a[10];
set <string> S;
string T;
int n,ans=11;
void dfs(const string &s,int dep)
{
    if (s.size()<=10 && S.count(s))
        return;
    if (s.size()>=30)
        return;
    if (dep==ans)
        return;
    S.insert(s);
    if (s==T)
    {
        ans=dep;
        return;
    }
    for (int i=0;i<s.size();i++)
        for (int j=0;j<n;j++)
            if (s.substr(i,a[j].first.size())==a[j].first)
                dfs(s.substr(0,i)+a[j].second+s.substr(i+a[j].first.size()),dep+1);
}
int main()
{
    string S;
    cin>>S>>T;
    while (cin>>a[n].first>>a[n].second)
        n++;
    dfs(S,0);
    if (ans==11)
        cout<<"NO ANSWER!"<<endl;
    else
        cout<<ans<<endl;
    return(0);
}

