#include <cstdio>
#include <map>
#include <set>
using namespace std;
char s[100000];
int main()
{
    map <int,int> M;
    while (1)
    {
        gets(s);
        int x;
        if (sscanf(s,"%d,%*d",&x)!=1)
            break;
        M[x]++;
    }
    set <int> S;
    int n;
    while (scanf("%d,%*d",&n)==1)
        if (M.count(n))
        {
            M[n]++;
            S.insert(n);
        }
    for (map <int,int>::iterator k=M.begin();k!=M.end();k++)
        if (S.count(k->first))
            printf("%d %d\n",k->first,k->second);
    return(0);
}

