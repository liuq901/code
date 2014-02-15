#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    char s[100];
    int x;
    map <string,vector <int> > M;
    while (scanf("%s%d",s,&x)==2)
        M[s].push_back(x);
    for (map <string,vector <int> >::iterator k=M.begin();k!=M.end();k++)
    {
        printf("%s\n",k->first.c_str());
        sort(k->second.begin(),k->second.end());
        for (int i=0;i<k->second.size();i++)
            printf("%d%c",k->second[i],i==k->second.size()-1?'\n':' ');
    }
    return(0);
}

