using System;
using System.Threading;

namespace t1 
{
	class EntryPoint
	{

		static int Main(string[] args)
		{
			WorkerClass1 wc1 = new WorkerClass1();
			Thread w = new Thread(wc1.DoTheWork);
            w.Priority = ThreadPriority.Normal;
			w.Start();
            ConsoleKey k;
			while( ((k = Console.ReadKey(false).Key)) != ConsoleKey.Escape )
			{
                if (k == ConsoleKey.DownArrow) wc1.Step += -1;
				if (k == ConsoleKey.UpArrow ) wc1.Step += 1;
				if (k == ConsoleKey.PageDown) wc1.Step += -5;
				if (k == ConsoleKey.PageUp) wc1.Step += 5;
                if (k == ConsoleKey.F12)
                {
                    if (w.ThreadState == ThreadState.Suspended) w.Resume();
                    if (w.ThreadState == ThreadState.Running) w.Suspend();

                }

                Console.Write("[key pressed]                        \r");
            }

			wc1.StopFlag = true;

			return 0;
		}
	}

	class CoreClass
	{
		public CoreClass()
		{

		}

		private int counter = 0;
		public int Counter
		{
			get { return counter; }
			set	{ counter = value; }
		}
	}

	class WorkerClass1 
	{
		public WorkerClass1()
		{

		}

		public void DoTheWork()
		{
            int i = Environment.TickCount;
            while (!stopflag) {
				IncreaseCounter();

                if (Environment.TickCount > i + 500)
                {
                    Console.Write(" step {0}   counter {1}                             \r", step, counter);
                    i = Environment.TickCount;
                }                
			}
		}

		private int step=1;
		public int Step {
			get {return step;}
			set {step=value;}
		}

		private int counter = 0;
		public int Counter 
		{
			get { return counter; }
			set	{ counter=value; }
		}

		public void IncreaseCounter()
		{
			counter+=step;
		}

		private bool stopflag = false;
		public bool StopFlag {
			get { return stopflag; }
			set { stopflag = value; }
		}

	}
}