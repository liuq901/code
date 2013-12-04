#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main()
{
    map <string,int> M;
    char s[10];
    while (scanf("%*d,%s",s)==1)
        M[s]++;
    printf("%d\n%d\n%d\n%d\n",M["A"],M["B"],M["AB"],M["O"]);
    return(0);
}

