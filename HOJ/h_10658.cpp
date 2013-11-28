#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int a[30];
char s[100000];
bool cmp(const pair <int,char> &a,const pair <int,char> &b)
{
    return(a.first>b.first || a.first==b.first && a.second<b.second);
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(s);
    while (T--)
    {
        gets(s);
        int n=strlen(s);
        for (int i=0;i<n;i++)
            if (isalpha(s[i]))
                a[tolower(s[i])-'a']++;
    }
    vector <pair <int,char> > ans;
    for (int i=0;i<26;i++)
        if (a[i])
            ans.push_back(make_pair(a[i],i+'A'));
    sort(ans.begin(),ans.end(),cmp);
    for (int i=0;i<ans.size();i++)
        printf("%c %d\n",ans[i].second,ans[i].first);
    return(0);
}

