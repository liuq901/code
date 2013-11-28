#include <cstdio>
#include <string>
using namespace std;
char buf[2010];
int main()
{
    scanf("%s",buf);
    string s=buf,tmp=s;
    int mid=(tmp.size()-1)/2;
    for (int i=0;i<=mid;i++)
        tmp[tmp.size()-i-1]=tmp[i];
    if (s<=tmp)
        printf("%s\n",tmp.c_str());
    else
    {
        for (int i=mid;i>=0;i--)
            if (s[i]!='9')
            {
                s[i]++;
                for (int j=i+1;j<=mid;j++)
                    s[j]='0';
                for (int j=0;j<=mid;j++)
                    s[s.size()-j-1]=s[j];
                break;
            }
        printf("%s\n",s.c_str());
    }
    return(0);
}

