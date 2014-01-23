#include <cstdio>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
char s[100];
int main()
{
    while (gets(s))
    {
        stringstream sin(s);
        string now;
        stack <double> a;
        while (sin>>now)
            if (now=="+")
            {
                double p=a.top();
                a.pop();
                a.top()+=p;
            }
            else if (now=="-")
            {
                double p=a.top();
                a.pop();
                a.top()-=p;
            }
            else if (now=="*")
            {
                double p=a.top();
                a.pop();
                a.top()*=p;
            }
            else if (now=="/")
            {
                double p=a.top();
                a.pop();
                a.top()/=p;
            }
            else
            {
                double p;
                sscanf(now.c_str(),"%lf",&p);
                a.push(p);
            }
        printf("%.10f\n",a.top());
    }
    return(0);
}

