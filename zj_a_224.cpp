#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
int a[26];
char buf[100000];
int main()
{
    while (scanf("%s",buf)==1)
    {
        int len=strlen(buf);
        memset(a,0,sizeof(a));
        for (int i=0;i<len;i++)
            if (isalpha(buf[i]))
                a[tolower(buf[i])-'a']++;
        int ans=0;
        for (int i=0;i<26;i++)
            ans+=a[i]&1;
        printf("%s\n",ans<=1?"yes !":"no...");
    }
    return(0);
}

