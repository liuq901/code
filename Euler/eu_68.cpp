#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int c[5][3]={{1,2,3},{4,3,5},{6,5,7},{8,7,9},{10,9,2}};
int a[20];
bool check()
{
    int sum=0;
    for (int i=0;i<3;i++)
        sum+=a[c[0][i]];
    for (int i=1;i<5;i++)
    {
        if (a[c[i][0]]<a[c[0][0]])
            return(false);
        int tmp=0;
        for (int j=0;j<3;j++)
            tmp+=a[c[i][j]];
        if (sum!=tmp)
            return(false);
    }
    return(true);
}
string get()
{
    string ret;
    for (int i=0;i<5;i++)
        for (int j=0;j<3;j++)
        {
            int x=a[c[i][j]];
            if (x==10)
                ret+="10";
            else
                ret+=x+'0';
        }
    if (ret.size()==17)
        ret="";
    return(ret);
}
int main()
{
    for (int i=1;i<=10;i++)
        a[i]=i;
    string ans;
    while (1)
    {
        if (check())
            ans=max(ans,get());
        if (!next_permutation(a+1,a+11))
            break;
    }
    printf("%s\n",ans.c_str());
    return(0);
}

