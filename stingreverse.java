class stringreverse
{
	public static void main(String[] args) {
		StringBuffer str=new StringBuffer("Aloha");
		System.out.println(str);
		System.out.println("Length is:"+str.length());
		System.out.println("capacity is:"+str.capacity());

		System.out.println("after append:"+str.append("mora"));
		System.out.println("Start inserting :"+str.insert(2,"my"));
		System.out.println("after deleted"+str.delete(2,4));
		System.out.println(str.reverse());
	}
}
