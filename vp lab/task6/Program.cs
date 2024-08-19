using System;
using System.Text;

class Program {
    public static void Main(String[] args) {
        StringBuilder sb = new StringBuilder("Initial String : ");
        sb.Append("Rohith"); // Append
        sb.Append(" Mariyala");
        Console.WriteLine(sb);

        sb.Insert(15, "C#"); // Insert
        Console.WriteLine(sb);

        sb.Replace("Mariyala", "Student"); // Replace
        Console.WriteLine(sb);

        sb.Remove(0, 15); // Remove
        Console.WriteLine(sb);

        string str = sb.ToString(); // ToString
        Console.WriteLine(str);

        string first = "Rohith ";
        string last = "Mariyala ";

        string name = string.Concat(last, first); // Concat
        Console.WriteLine(name);

        Console.WriteLine("Length of first name is "+ first.Length); // Length

        Console.WriteLine("Comparing two strings: "+ first.CompareTo(last)); // CompareTo

        Console.WriteLine("Using trim finction: "+ first.Trim('R')); // Trim

        Console.WriteLine("Using SubString function: "+ last.Substring(3, 5)); // Substring

        Console.WriteLine("Using equal() function: "+ first.Equals(last)); // Equals

        Console.WriteLine("Using Replace function: "+ first.Replace("R", "M")); // Replace
    }
}