#include &lt; stdio.h & gt;
#include &lt; stdlib.h & gt;
#include &lt; math.h & gt;

// Function to calculate the greatest common divisor
int gcd(int a, int b)
{
    while (b != 0)
    {

        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate (base^exponent) % modulus
long long mod_exp(long long base, long long exponent, long long modulus)
{
    long long result = 1;
    while (exponent & gt; 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }
    return result;
}

int main()
{
    long long p, q, n, phi, e, d;
    long long encrypted, decrypted;
    long long message;

    // Step 1: Ask user for two large prime numbers
    printf(&quot; Enter a large prime number p : &quot;);
    scanf(&quot; % lld & quot;, &amp; p);
    printf(&quot; Enter another large prime number q : &quot;);
    scanf(&quot; % lld & quot;, &amp; q);

    // Step 2: Calculate n = p * q
    n = p * q;

    // Step 3: Calculate the Euler&#39;s Totient Function, phi(n)
    phi = (p - 1) * (q - 1);

    // Step 4: Dynamically choose e such that 1 &lt; e &lt; phi and gcd(e, phi) = 1
    e = 2;
    while (gcd(e, phi) != 1)
    {
        e++;
    }

    printf(&quot; Chosen e = % lld\n & quot;, e);

    // Step 5: Compute d, the modular multiplicative inverse of e modulo phi
    // Using a brute force approach to find d such that (d * e) % phi = 1
    d = 0;
    while ((e * d) % phi != 1)
    {
        d++;
    }

    // Display public and private keys
    printf(&quot; Public Key(n = % lld, e = % lld)\n & quot;, n, e);
    printf(&quot; Private Key(n = % lld, d = % lld)\n & quot;, n, d);

    // Step 6: Get the message to encrypt (as an integer)
    do
    {
        printf(&quot; Enter a message to encrypt(as an integer, &lt; n = % d) : &quot;, n);
        scanf(&quot; % d & quot;, &amp; message);
    } while (message &gt; = n); // Ensure the message is smaller than n

    // Step 7: Encrypt the message using: encrypted = (message^e) % n
    encrypted = mod_exp(message, e, n);
    printf(&quot; Encrypted message : % lld\n & quot;, encrypted);

    // Step 8: Decrypt the message using: decrypted = (encrypted^d) % n
    decrypted = mod_exp(encrypted, d, n);
    printf(&quot; Decrypted message : % lld\n & quot;, decrypted);

    return 0;
}


/**
  Output:
Enter a large prime number p: 23
Enter another large prime number q: 29
Chosen e = 3
Public Key (n = 667, e = 3)
Private Key (n = 667, d = 411)
Enter a message to encrypt (as an integer, &lt; n = 667): 23
Encrypted message: 161
Decrypted message: 23
 */