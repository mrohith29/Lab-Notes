#include <stdio.h>
#include <stdbool.h>
#define MAX_FRAMES 10
void transmit_frames(int start, int end)
{
    for (int i = start; i < end; i++)
    {
        printf("Frame %d has been transmitted.\n", i);
    }
}
int main()
{
    int total_frames, window_size, i;
    bool ack_received[MAX_FRAMES] = {false};
    int sent_start = 0;
    int ack;
    // Input for total frames and window size
    printf("Enter the total number of frames to be sent (max %d): ", MAX_FRAMES);
    scanf("%d", &total_frames);
    printf("Enter the window size: ");
    scanf("%d", &window_size);
    if (window_size <= 0 || total_frames <= 0 || window_size > total_frames)
    {
        printf("Invalid window size or number of frames.\n");
        return 1;
    }
    while (sent_start < total_frames)
    {
        // Determine the end of the current window
        int end = sent_start + window_size;
        if (end > total_frames)
            end = total_frames;
        // Transmit frames within the window
        transmit_frames(sent_start, end);
        // Prompt for acknowledgments
        printf("\nPlease enter the acknowledgments received (enter -1 to finish):\n");
        for (i = sent_start; i < end; i++)
        {
            printf("Enter acknowledgment for frame %d: ", i);
            scanf("%d", &ack);
            if (ack == -1)
            {
                printf("No acknowledgment for frame %d. Will retransmit.\n", i);
            }
            else if (ack >= sent_start && ack < end)
            {
                ack_received[ack] = true;
                printf("Acknowledgment %d received.\n", ack);
            }
            else
            {
                printf("Invalid acknowledgment. It should be within the transmitted window.\n");
            }
        }
        // Retransmit only the frames that need it
        printf("\nRetransmitting unacknowledged frames...\n");
        for (i = sent_start; i < end; i++)
        {
            if (!ack_received[i])
            {
                printf("Retransmitting frame %d.\n", i);
                transmit_frames(i, i + 1);
            }
        }
        // Move the window forward
        while (sent_start < total_frames && ack_received[sent_start])
        {
            sent_start++;
        }
        // Adjust window end to include new frames that come after the last acknowledged frame
        int new_end = sent_start + window_size;
        if (new_end > total_frames)
            new_end = total_frames;
        // Transmit new frames if there are any
        if (sent_start < total_frames && new_end > sent_start)
        {
            transmit_frames(sent_start, new_end);
        }
    }
    printf("All frames have been transmitted and acknowledged.\n");
    return 0;
}