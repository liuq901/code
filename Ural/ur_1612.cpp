#include <cstdio>
#include <string>
#include <map>
using namespace std;
int main()
{
    string s;
    char ch;
    map <string,int> M;
    while ((ch=getchar())!=EOF)
    {
        if (!isalpha(ch))
        {
            M[s]++;
            s="";
            continue;
        }
        s+=ch;
    }
    int a=M["tram"],b=M["trolleybus"];
    if (a>b)
        printf("Tram driver\n");
    else if (a<b)
        printf("Trolleybus driver\n");
    else
        printf("Bus driver\n");
    return(0);
}

