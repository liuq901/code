/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String args[]) throws Exception
    {
        new Main().run();
    }
    void run() throws Exception
    {
        Scanner in=new Scanner(new File("derangements.in"));
        int n=in.nextInt();
        BigInteger a[]=new BigInteger[210];
        a[1]=BigInteger.ONE;
        a[2]=BigInteger.valueOf(5);
        for (int i=3;i<=n;i++)
            a[i]=a[i-1].add(a[i-2].add(a[i-1]).multiply(BigInteger.valueOf(i-1)).shiftLeft(1));
        PrintWriter out=new PrintWriter(new File("derangements.out"));
        out.println(a[n]);
        out.close();
    }
}
*/
int main(){}

