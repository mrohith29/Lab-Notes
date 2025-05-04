#include <stdio.h>
#include <stdlib.h>
int main()
{
    int bucket_size = 10;                      // The maximum size of the bucket (token capacity)
    int tokens = 0;                            // Current number of tokens in the bucket
    int token_rate = 3;                        // Rate at which tokens are added (tokens per second)
    int no_of_queries = 6;                     // Number of incoming packets (queries)
    int input_pkt_size[] = {4, 6, 8, 2, 1, 5}; // Incoming packet sizes
    int required_tokens = 4;                   // Tokens required to process each packet
    int queue = 0;                             // Queue size for holding packets if tokens are insufficient
    int time_interval = 1;                     // Time interval for adding tokens (simulated as 1 second)
    for (int i = 0; i < no_of_queries; i++)
    {
        // Add tokens at a constant rate
        tokens += token_rate * time_interval;
        printf("no of tokens added:%d", tokens);
        if (tokens > bucket_size)
        {
            tokens = bucket_size; // Ensure tokens do not exceed bucket capacity
        }
        printf("\nTime: %d seconds\n", i + 1);
        printf("Incoming packet size: %d\n", input_pkt_size[i]);
        // If not enough tokens for current packet, queue it
        if (tokens < required_tokens)
        {
            printf("Not enough tokens! Queuing packet of size %d.\n", input_pkt_size[i]);
            queue += input_pkt_size[i]; // Add to the queue
        }
        else
        {
            // Process the packet if enough tokens are available
            tokens -= required_tokens;
            printf("Processed packet of size %d. Tokens remaining: %d\n", input_pkt_size[i], tokens);
            // If there is a queue, process the queued packets when tokens become available
            while (queue > 0 && tokens >= required_tokens)
            {
                printf("Processing queued packet of size %d\n", queue);
                tokens -= required_tokens;
                queue = 0; // Clear the queue after processing
            }
        }
        // Print current token and queue status
        printf("Tokens in bucket: %d\n", tokens);
        printf("Packets in queue: %d\n", queue);
    }

    return 0;
}