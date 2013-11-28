#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;
const string name[4]={"Slytherin","Hufflepuff","Gryffindor","Ravenclaw"};
char buf[100000];
char s[1010][1010];
map <string,int> M;
vector <int> a[4];
int main()
{
    int n;
    scanf("%d",&n);
    gets(buf);
    for (int i=0;i<4;i++)
        M[name[i]]=i;
    for (int i=1;i<=n;i++)
    {
        gets(s[i]);
        gets(buf);
        a[M[buf]].push_back(i);
    }
    for (int i=0;i<4;i++)
    {
        printf("%s:\n",name[i].c_str());
        for (int j=0;j<a[i].size();j++)
            printf("%s\n",s[a[i][j]]);
        printf("\n");
    }
    return(0);
}

