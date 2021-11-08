import java.util.*;
class Result{
  static int balancedString(String s){
    Stack<Character> stk = new Stack<Character>();
    for(int i=0;i<s.length();i++){
      char c = s.charAt(i);
      if(c=='(' || c=='{' || c=='[')
        stk.push(c);
      else if((c==')' || c=='}' || c==']') && !stk.empty()){
        if(c==')' && stk.peek()=='(')
          stk.pop();
        else if(c=='}' && stk.peek()=='{')
          stk.pop();
        else if(c==']' && stk.peek()=='[')
          stk.pop();
        else
          return i;
      }
      else if(c==')' || c=='}' || c==']')
        return i;
    }
    if(!stk.empty())
      return s.length();
    return -1;
  }
}
class Main
{
  public static void main(String[] args){
    String s1;
    Scanner s=new Scanner(System.in);
    s1=s.nextLine();
    Result result = new Result();
    System.out.println(result.balancedString(s1));
  }
}
