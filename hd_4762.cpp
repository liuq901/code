/*
Java:
import java.io.*;
import java.math.*;
import java.util.*;
public class Main
{
    class fact
    {
        BigInteger a,b;
        fact(BigInteger _a,BigInteger _b)
        {
            a=_a;
            b=_b;
            BigInteger p=a.gcd(b);
            a=a.divide(p);
            b=b.divide(p);
        }
        void print()
        {
            System.out.println(a+"/"+b);
        }
    }
    public static void main(String args[])
    {
        new Main().run();
    }
    void run()
    {
        Scanner in=new Scanner(System.in);
        int T=in.nextInt();
        while (T-->0)
        {
            int m=in.nextInt(),n=in.nextInt();
            fact ans=new fact(BigInteger.valueOf(n),power(m,n-1));
            ans.print();
        }
    }
    BigInteger power(int m,int n)
    {
        BigInteger ret=BigInteger.ONE;
        for (int i=1;i<=n;i++)
            ret=ret.multiply(BigInteger.valueOf(m));
        return(ret);
    }
}
*/
int main(){}

