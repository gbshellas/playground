
using System;

namespace myapp 
{
		class MyClass1
		{
			///<c>int i=10;</c>
			///
			static void Main(string[] args)
			{
				sayHelloWorld();

				Console.WriteLine("{0}", Add(10,2));
#line 20013 "taskata.cs"
				#if DEBUG
				#error Manual test error produced!!!
				#endif
#line default
				for(int i=0; i < args.Length; i++) 
					Console.WriteLine("arg[{0, 9:D}] = {1, 10}", (i+1).ToString(), args[i].ToString());
				
				
				int @abstract = 10;
				Console.WriteLine("The @abstract variable is {0}", @abstract);
				
				return;
			}

			///
			public static void sayHelloWorld()
			{
				Console.WriteLine("Hello world C#");

				int a = 1234;
				int b;
				unsafe {
					b = &a;
					Console.WriteLine("In usafe block the value of a is {0} and the address of a is {1}", a, ((int) b) );

				}
			}

			///<summary>Concatenates x and y and returns the result</summary>
			///<returns>The result of the addition of x and y</returns>
			///<param name="x">First number to add</param>
			///<param name="y">Second number to add</param>
			public static int Add(int x, int y)
			{
				return x + y;
			}
		}
}