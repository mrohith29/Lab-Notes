using System;
using System.Text;

class StringBuilderExample {
    static void Main(string[] args) {
        // Create a new StringBuilder instance with an initial string
        StringBuilder sb = new StringBuilder("Initial String: ");
        Console.WriteLine(sb);

        // Append strings to the StringBuilder
        sb.Append("Hello, ");
        sb.Append("World!");
        Console.WriteLine(sb);

        // Insert a string at a specific index
        sb.Insert(15, "C# ");
        Console.WriteLine(sb);

        // Replace a string within the StringBuilder
        sb.Replace("World", "StringBuilder");
        Console.WriteLine(sb);

        // Remove characters from the StringBuilder
        sb.Remove(0, 15); // Removes "Initial String: "

        // Convert the StringBuilder to a string and print it
        string result = sb.ToString();
        Console.WriteLine(sb);
        Console.WriteLine(result);
    }
}