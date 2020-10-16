import java.util.Scanner;
import java.util.ArrayList;
import java.io.File;
import java.io.PrintStream;



class GraphPath{
    static Scanner sc;
    public static void main(String args[]){
        
        try{
            File file = new File("C:\\Users\\Tanisha\\Desktop\\inputGraph2.txt");
            sc = new Scanner(file);
            

        }
        catch(Exception e){
            System.out.println("Error");
            System.out.println(e.getMessage());
        }
        
        String initialInfo;
        if(sc.hasNextLine())
        initialInfo = sc.next();
        else initialInfo = "";
        String[] arr = initialInfo.split(",");
        int n = Integer.parseInt(arr[0]);

        ArrayList<Integer>[] graph = new ArrayList[n];
        for(int i=0; i<n; i++) {
            graph[i] = new ArrayList<>();
        }
        sc.next();
        if(arr[1].equals("u")){
            while (sc.hasNext()){
                String s = sc.next();
                String[] arr1 = s.split(",");
                if(!sc.hasNext()) {
                	boolean[] vis = new boolean[graph.length];
                	
                	try{
                        PrintStream ps = new PrintStream(new File("out2.txt"));
                        PrintStream console = System.out; 
                        System.setOut(ps);
                        System.out.println((hasPath((Integer.parseInt(arr1[0])),(Integer.parseInt(arr1[arr1.length-1])),vis,"",graph)?1:0 +" "));
                    }
                    catch(Exception e){
                        System.out.println(e.getMessage());
                    }
                	
                }
                graph[Integer.parseInt(arr1[0])-1].add(Integer.parseInt(arr1[1]));
                graph[Integer.parseInt(arr1[1])-1].add(Integer.parseInt(arr1[0]));
            }
        }
        else if(arr[1].equals("d")){
            while (sc.hasNext()){
                String s = sc.next();
                String[] arr1 = s.split(",");
                if(!sc.hasNext()) {
                	boolean[] vis = new boolean[graph.length];
                	try{
                        PrintStream ps = new PrintStream(new File("graph_Path_out.txt"));
                        PrintStream console = System.out; 
                        System.setOut(ps);
                        System.out.println((hasPath((Integer.parseInt(arr1[0])),(Integer.parseInt(arr1[arr1.length-1])),vis,"",graph)?1:0 +" "));
                    }
                    catch(Exception e){
                        System.out.println(e.getMessage());
                    }
                }
                graph[Integer.parseInt(arr1[0])-1]
                
                		.add(Integer.parseInt(arr1[1]));
            }
        }
        
        //System.out.println(hasPath(1,4,vis,"",graph));
    }

    
    
    public static boolean hasPath(int src, int desti, boolean[] vis, String ans, ArrayList<Integer>[] graph) {
    	
            if (src == desti){
                //System.out.println(ans + " " + desti);
                return true;
            }
            vis[src] = true;
            boolean res = false;
            for (int edge : graph[src]){
                if (!vis[edge])
                    res = res || hasPath(edge, desti, vis, ans + src + " ", graph);
            }

            return res;

    }
        
}