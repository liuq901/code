#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000010];
int main()
{
    scanf("%s",s);
    int len=strlen(s),cnt=count(s,s+len,'0');
    if (cnt==len-4)
    {
        printf("1869");
        for (int i=0;i<cnt;i++)
            printf("0");
        printf("\n");
    }
    else
    {
        int pos[10];
        for (int i=0;i<len;i++)
            if (s[i]=='1')
            {
                swap(s[i],s[len-4]);
                break;
            }
        for (int i=0;i<len;i++)
            if (s[i]=='6')
            {
                swap(s[i],s[len-3]);
                break;
            }
        for (int i=0;i<len;i++)
            if (s[i]=='8')
            {
                swap(s[i],s[len-2]);
                break;
            }
        for (int i=0;i<len;i++)
            if (s[i]=='9')
            {
                swap(s[i],s[len-1]);
                break;
            }
        for (int i=0;i<len;i++)
            if (s[i]!='0')
            {
                swap(s[0],s[i]);
                break;
            }
        int sum=0;
        for (int i=0;i<len-4;i++)
            sum=(sum*10+s[i]-'0')%7;
        while (1)
        {
            int tmp=sum;
            for (int i=len-4;i<len;i++)
                tmp=(tmp*10+s[i]-'0')%7;
            if (tmp==0)
            {
                printf("%s\n",s);
                break;
            }
            next_permutation(s+len-4,s+len);
        }
    }
    return(0);
}

