package pgrms;

class NewThread implements Runnable
{
	Thread t;
	NewThread()
	{
		t = new Thread(this,"Demo Thread");
		System.out.println("Child thred:"+t);
		t.start();
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		try
		{
			for(int i=5;i>0;i--)
			{
				System.out.println("Chiild Thread:"+i);
				Thread.sleep(500);
			}
		} catch(InterruptedException e)
		{
			System.out.println("child Interrupted");
		}
		System.out.println("Exiting child thread");
		
	}
	
}

public class ThreadDemo {
	public static void main(String args[])
	{
		new NewThread();
		
		try
		{
			for(int i=5;i>0;i--)
			{
				System.out.println("main thread:"+i);
				Thread.sleep(1000);
			}
		} catch (InterruptedException e)
		{
			System.out.println("Main thread interrupted");
		}
		System.out.println("main thread exiting");
	}

}
