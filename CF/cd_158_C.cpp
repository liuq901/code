#include <cstdio>
#include <vector>
#include <string>
using namespace std;
vector <string> ans;
char s[1000];
void print()
{
    printf("/");
    for (int i=0;i<ans.size();i++)
        printf("%s/",ans[i].c_str());
    printf("\n");
}
void work(string s)
{
    s+='/';
    string now;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='/')
        {
            if (now=="..")
                ans.pop_back();
            else if (now!="")
                ans.push_back(now);
            now="";
            continue;
        }
        now+=s[i];
    }
}
int main()
{
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        char op[10];
        scanf("%s",op);
        if (op[0]=='p')
            print();
        else
        {
            scanf("%s",s);
            if (s[0]=='/')
            {
                ans.clear();
                work(s+1);
            }
            else
                work(s);
        }
    }
    return(0);
}

