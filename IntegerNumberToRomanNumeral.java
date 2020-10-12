public class IntegerToRoman {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		int n=s.nextInt();
		String answer= IntegerToRoman(n);
		System.out.println(answer);
		

	}
	public static String IntegerToRoman(int num)
	{
		 String m[] = {"", "M", "MM", "MMM"}; 
	        String c[] = {"", "C", "CC", "CCC", "CD", "D",  
	                            "DC", "DCC", "DCCC", "CM"}; 
	        String x[] = {"", "X", "XX", "XXX", "XL", "L",  
	                            "LX", "LXX", "LXXX", "XC"}; 
	        String i[] = {"", "I", "II", "III", "IV", "V",  
	                            "VI", "VII", "VIII", "IX"};
	        String thousands = m[num/1000]; 
	        String hundereds = c[(num%1000)/100]; 
	        String tens = x[(num%100)/10]; 
	        String ones = i[num%10]; 
	              
	        String ans = thousands + hundereds + tens + ones; 
	              
	        return ans;
	}

}
