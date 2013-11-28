#include <cstdio>
#include <cstring>
const int c[3]={5,7,5};
bool check(char c)
{
    return(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
int calc(char *s)
{
    int len=strlen(s),ret=0;
    for (int i=0;i<len;i++)
        ret+=check(s[i]);
    return(ret);
}
char s[110];
int main()
{
    bool flag=true;
    for (int i=0;i<3;i++)
    {
        gets(s);
        if (calc(s)!=c[i])
        {
            flag=false;
            break;
        }
    }
    printf("%s\n",flag?"YES":"NO");
    return(0);
}

