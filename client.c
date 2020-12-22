#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int MAX_SIZE = 256;
int main()
{
    char input[MAX_SIZE];
    int response;
    // constantly asking user for input
    while (1)
    {
        // store the input in the input character array
        fgets(input, MAX_SIZE, stdin);
        int fd;
        // open the fifo "mario" in order to send input
        fd = open("./mario", O_WRONLY);
        write(fd, input, 4 * strlen(input));
        close(fd);
        // open the fifo "luigi" in order to receive response
        fd = open("./luigi", O_RDONLY);
        read(fd, &response, MAX_SIZE);
        printf("%d\n", response);
        close(fd);
    }
    return 0;
}
