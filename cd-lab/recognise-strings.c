// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// void main()
// {
//     char s[20], c;
//     int state = 0, i = 0;
//     printf("\n Enter a string:");
//     gets(s);
//     while (s[i] != '\0')
//     {
//         switch (state)
//         {
//         case 0:
//             c = s[i++];
//             if (c == 'a')
//                 state = 1;
//             else if (c == 'b')
//                 state = 2;
//             else
//                 state = 6;
//             break;
//         case 1:
//             c = s[i++];
//             if (c == 'a')
//                 state = 3;
//             else if (c == 'b')
//                 state = 4;
//             else
//                 state = 6;
//             break;
//         case 2:
//             c = s[i++];
//             if (c == 'a')
//                 state = 6;
//             else if (c == 'b')
//                 state = 2;
//             else
//                 state = 6;
//             break;
//         case 3:
//             c = s[i++];
//             if (c == 'a')
//                 state = 3;
//             else if (c == 'b')
//                 state = 2;
//             else
//                 state = 6;
//             break;
//         case 4:
//             c = s[i++];
//             if (c == 'a')
//                 state = 6;
//             else if (c == 'b')
//                 state = 5;
//             else
//                 state = 6;
//             break;
//         case 5:
//             c = s[i++];
//             if (c == 'a')
//                 state = 6;
//             else if (c == 'b')
//                 state = 2;
//             else
//                 state = 6;
//             break;
//         case 6:
//             printf("\n %s is not recognised.", s);
//             exit(0);
//         }
//     }
//     if (state == 1)
//         printf("\n %s is accepted under rule 'a'", s);
//     else if ((state == 2) || (state == 4))
//         printf("\n %s is accepted under rule 'a*b+'", s);
//     else if (state == 5)
//         printf("\n %s is accepted under rule 'abb'", s);
// }


#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';  // remove newline

    int i = 0;
    int a_count = 0, b_count = 0;

    // Count all leading 'a's
    while (s[i] == 'a') {
        a_count++;
        i++;
    }

    // Count all remaining 'b's
    while (s[i] == 'b') {
        b_count++;
        i++;
    }

    // If we reached end of string
    if (s[i] == '\0') {
        if (a_count == 1 && b_count == 0)
            printf("%s is accepted under rule 'a'\n", s);
        else if (b_count >= 1)
            printf("%s is accepted under rule 'a*b+'\n", s);
        else if (a_count == 1 && b_count == 2)
            printf("%s is accepted under rule 'abb'\n", s);
        else
            printf("%s is not recognised.\n", s);
    } else {
        printf("%s is not recognised.\n", s);
    }

    return 0;
}
