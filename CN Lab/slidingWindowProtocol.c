#include <stdio.h>
int main()
{
    int total_frames, windowsize, sent = 0, ack = 0, i;
    int frame_start = 0; // Start of the window
    printf("Enter the total number of frames to be sent: ");
    scanf("%d", &total_frames);
    printf("Enter the window size: ");
    scanf("%d", &windowsize);
    if (windowsize <= 0 || total_frames <= 0 || windowsize > total_frames)
    {
        printf("Invalid window size or number of frames.\n");
        return 1;
    }
    while (sent < total_frames)
    {
        // Transmit frames within the window
        for (i = 0; i < windowsize && (frame_start + i) < total_frames; i++)
        {

            printf("Frame %d has been transmitted.\n", frame_start + i);
        }
        // Prompt for the last acknowledgment received
        printf("\nPlease enter the last Acknowledgement received (0 to %d): ", frame_start + i - 1);
        scanf("%d", &ack);
        if (ack < frame_start || ack > frame_start + i - 1)
        {
printf("Invalid acknowledgment. Please enter a valid acknowledgment within the transmittedwindow.\n");
        }
        else if (ack >= total_frames)
        {
printf("Acknowledgment %d is beyond the total number of frames. Please enter a validacknowledgment.\n", ack);
        }
        else
        {
            printf("Acknowledgment %d received.\n", ack);
            // Move the window to start after the last acknowledged frame
            frame_start = ack + 1;
            // Update the `sent` variable to ensure frames are transmitted correctly
            sent = frame_start;
            // Adjust the end of the window
            int end_frame = frame_start + windowsize;
            if (end_frame > total_frames)
                end_frame = total_frames;
        }
    }
    printf("All frames have been transmitted and acknowledged.\n");
    return 0;
}