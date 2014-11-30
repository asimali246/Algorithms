import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.Character;
class Main
{ 
	BigInteger a[]=new BigInteger[310];
	BigInteger b[]=new BigInteger[310];
	public static void main(String args[])
	{
		Main ob=new Main();
		ob.solver();
	}
	void solver()
	{
		try{
		BufferedReader obj=new BufferedReader(new InputStreamReader(System.in));
		Scanner in=new Scanner(System.in);
		a[1]=new BigInteger("1");
		b[1]=new BigInteger("1");
		for(int i=2;i<=301;++i)
			{a[i]=new BigInteger("0");
			 b[i]=new BigInteger(String.valueOf(i)).multiply(b[i-1]);}
		while(true)
		{
			int n=Integer.parseInt(obj.readLine());
			if(n==0)break;
			System.out.println(calc(n).multiply(b[n]));
		}
		}catch(Exception e){};	
	}
	BigInteger calc(int n)
	{
		if(n==1)return a[n];
		else
		if(a[n].compareTo(new BigInteger("0"))!=0)return a[n];
		else 
		{
			BigInteger t=new BigInteger(String.valueOf(2*(n-1)+1));
			t=t.multiply(new BigInteger(String.valueOf(2*(n-1)+2)));
			t=t.multiply(calc(n-1));
			t=t.divide(new BigInteger(String.valueOf(n)));
			t=t.divide(new BigInteger(String.valueOf(n+1)));
			return a[n]=t;
		}
	}
}