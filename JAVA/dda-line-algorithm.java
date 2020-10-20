import java.awt.Canvas;
import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import static java.lang.Math.round;
import java.util.Random;
import java.util.concurrent.TimeUnit;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int x1,y1,x2,y2;
        
        Scanner input = new Scanner(System.in);
        System.out.println("koordinat 1");
        System.out.print("x1: ");
        x1 = input.nextInt();
        System.out.print("y1: ");
        y1 = input.nextInt();
        
        System.out.println("koordinat 2");
        System.out.print("x2: ");
        x2 = input.nextInt();
        System.out.print("y2: ");
        y2 = input.nextInt();
        
        Frame f = new Frame("DDA Line Algorithm");
        f.setLayout(null);
        f.setSize(800,800);
        f.setVisible(true);
        
        f.add(new MyCanvas(x1,y1,x2,y2));
    }
}

class MyCanvas extends Canvas{
int x1,y1,x2,y2;

    public MyCanvas(int x1,int y1, int x2, int y2) {
        this.x1 = x1;
        this.x2=x2;
        this.y1 = y1;
        this.y2 = y2;
        setBackground(Color.BLACK);
        setSize(800,800);
    }

    @Override
    public void paint(Graphics g) {       
           try {
              DDALine(g);
          } catch (InterruptedException ex) {
              System.out.println(ex.getMessage());
          }
    }

    private void DDALine(Graphics graphic) throws InterruptedException {
        Random rand = new Random();
        float r = rand.nextFloat();
        float g = rand.nextFloat();
        float b = rand.nextFloat();
        
        Color randomColor = new Color(r, g, b);
        graphic.setColor(randomColor);
        
        int dx, dy ;
        float steps,x,y, incX,incY;
        
        dx = x2-x1;
        dy = y2-y1;
        
        if(Math.abs(dx) > Math.abs(dy)){
            steps = Math.abs(dx);
        } else {
            steps = Math.abs(dy);
        }
        
        incX = dx /(float) steps;
        incY = dy /(float) steps;
        x = x1;
        y = y1;
        
        graphic.drawLine(round(x),round(y),round(x),round(y));
        
        for(int k = 0; k<steps;k++){
            x += incX;
            y += incY;
            TimeUnit.MILLISECONDS.sleep(10);
            graphic.drawLine(round(x),round(y),round(x),round(y));
        }
    }
  
}
