/*
Java:
import java.io.*;
import java.math.*;
import java.util.*;
public class Main
{
    static public void main(String args[])
    {
        new Main().run();
    }
    void run()
    {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt(),a[]=new int[n*2+10];
        for (int i=1;i<=2*n;i++)
            a[i]=in.nextInt();
        BigInteger ans=BigInteger.ZERO;
        boolean reverse=false;
        for (int i=1;i<=n;i++)
        {
            boolean flag=a[2*i-1]<a[2*i];
            if (reverse)
                flag=!flag;
            BigInteger p=BigInteger.ONE.shiftLeft(n-i+1).subtract(BigInteger.valueOf(2));
            if (flag)
            {
                ans=ans.add(p).add(BigInteger.valueOf(2));
                reverse=true;
            }
            else if (i==n)
                ans=ans.add(BigInteger.valueOf(3));
            else
            {
                ans=ans.add(p.multiply(BigInteger.valueOf(2))).add(BigInteger.valueOf(4));
                reverse=false;
            }
        }
        System.out.println(ans);
    }
}
*/
int main(){}

