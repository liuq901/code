#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
struct person
{
    string name;
    int num,penalty;
    person(string name,int n,int p):name(name),num(n),penalty(p){}
};
inline bool operator <(const person &a,const person &b)
{
    return(a.num>b.num || a.num==b.num && (a.penalty<b.penalty || a.penalty==b.penalty && a.name<b.name));
}
vector <person> a;
char buf[1000];
int main()
{
    int n,v;
    scanf("%d%d",&n,&v);
    while (scanf("%s",buf)==1)
    {
        string name=buf;
        int num=0,penalty=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            stringstream sin(buf);
            int t;
            sin>>t;
            if (t>0)
            {
                num++;
                penalty+=t;
            }
            char ch;
            if (sin>>ch>>t)
                penalty+=t*v;
        }
        a.push_back(person(name,num,penalty));
    }
    sort(a.begin(),a.end());
    for (int i=0;i<a.size();i++)
        printf("%-10s %2d %4d\n",a[i].name.c_str(),a[i].num,a[i].penalty);
    return(0);
}

