#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool check(int x,int y,int z)
{
    if (x==y && x==z)
        return(true);
    int u=min(min(x,y),z),w=max(max(x,y),z),v=x+y+z-u-w;
    return(u+1==v && v+1==w);
}
bool dfs(const vector <int> &a)
{
    if (a.size()==2)
        return(a[0]==a[1]);
    for (int i=0;i<a.size();i++)
        for (int j=i+1;j<a.size();j++)
            for (int k=j+1;k<a.size();k++)
                if (check(a[i],a[j],a[k]))
                {
                    vector <int> b=a;
                    b.erase(b.begin()+k);
                    b.erase(b.begin()+j);
                    b.erase(b.begin()+i);
                    if (dfs(b))
                        return(true);
                }
    return(false);
}
int main()
{
    char buf[20];
    while (scanf("%s",buf)==1)
    {
        vector <int> a;
        for (int i=0;i<13;i++)
            a.push_back(buf[i]-'0');
        bool first=true;
        for (int i=1;i<=9;i++)
        {
            if (count(a.begin(),a.end(),i)==4)
                continue;
            a.push_back(i);
            if (dfs(a))
            {
                if (!first)
                    printf(" ");
                first=false;
                printf("%d",i);
            }
            a.pop_back();
        }
        if (first)
            printf("0");
        printf("\n");
    }
    return(0);
}

