
package commandpro;

import java.util.Scanner;

public class CommandPro {

    public static void main(String[] args) 
    {
        String [] command={"echo","for","while","split","break","try","catch","new","if","return"};
        
        Scanner scan = new Scanner(System.in);
        
        System.out.print("Input Command PHP : ");
        String InputCommand=scan.nextLine();
        
        System.out.println("");
        System.out.print(InputCommand.charAt(0));
        for (int i = 1; i < InputCommand.length(); i++) 
        {
            System.out.print(","+InputCommand.charAt(i));
        }
        System.out.println("");
        System.out.println("___________________________");
        
        for (int i = 0; i < command.length; i++) 
        {
            int cek=0;
            String [] simpan=command[i].split("");
            String [] cekinput=InputCommand.split("");
            if(simpan.length==cekinput.length)
            {
                for (int j = 0; j < simpan.length; j++) 
                {
                    if(simpan[j].equals(cekinput[j]))
                    {
                        cek++;
                    }
                }
            }
            
            if(cek==simpan.length)
            {
                System.out.println("Syntax Found ");
                break;
            }
            if(i==command.length-1)
            {
                System.out.println("Syntax Not Found");
            }
        }
    }
    
}
