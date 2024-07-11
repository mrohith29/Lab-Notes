using System;
using System.Threading;

class Program {
    // Method for thread 1
    public static void ThreadMethod1() {
        for (int i = 0; i < 5; i++) {
            Console.WriteLine($"Thread 1 executing iteration {i}");
            // Sleep for 500 milliseconds
            Thread.Sleep(500);
        }
    }

    // Method for thread 2
    public static void ThreadMethod2() {
        for (int i = 0; i < 5; i++) {
            Console.WriteLine($"Thread 2 executing iteration {i}");
            // Sleep for 500 milliseconds
            Thread.Sleep(500);
        }
    }

    static void Main(string[] args) {
        // Creating the first thread
        Thread thread1 = new Thread(new ThreadStart(ThreadMethod1));

        // Creating the second thread
        Thread thread2 = new Thread(new ThreadStart(ThreadMethod2));

        // Starting both threads
        thread1.Start();
        thread2.Start();

        // Joining both threads to ensure they finish before Main thread ends
        thread1.Join();
        thread2.Join();

        Console.WriteLine("Both threads have finished executing.");
    }
}