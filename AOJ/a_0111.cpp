#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char a[][20]={"100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111",
    "1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
char s[1000000];
int main()
{
    while (gets(s))
    {
        string now;
        int len=strlen(s);
        for (int i=0;i<len;i++)
        {
            int tmp;
            if (isalpha(s[i]))
                tmp=s[i]-'A';
            else if (s[i]==' ')
                tmp=26;
            else if (s[i]=='.')
                tmp=27;
            else if (s[i]==',')
                tmp=28;
            else if (s[i]=='-')
                tmp=29;
            else if (s[i]=='\'')
                tmp=30;
            else
                tmp=31;
            for (int j=4;j>=0;j--)
                now+=char((tmp>>j&1)+'0');
        }
        for (int i=0;i<now.size();)
            if (now.substr(i,3)=="101")
            {
                printf(" ");
                i+=3;
            }
            else if (now.substr(i,6)=="000000")
            {
                printf("'");
                i+=6;
            }
            else if (now.substr(i,6)=="000011")
            {
                printf(",");
                i+=6;
            }
            else if (now.substr(i,8)=="10010001")
            {
                printf("-");
                i+=8;
            }
            else if (now.substr(i,6)=="010001")
            {
                printf(".");
                i+=6;
            }
            else if (now.substr(i,6)=="000001")
            {
                printf("?");
                i+=6;
            }
            else
            {
                bool flag=false;
                for (int j=0;j<26;j++)
                    if (now.substr(i,strlen(a[j]))==a[j])
                    {
                        printf("%c",j+'A');
                        i+=strlen(a[j]);
                        flag=true;
                        break;
                    }
                if (!flag)
                    break;
            }
        printf("\n");
    }
    return(0);
}

