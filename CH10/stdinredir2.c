/* stdinredir2.c
 * 	shows two more methods for redirecting standard input
 *	use #define to set one or the other
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int newfd;
    char line[100];

    /* read and print three lines */

    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(line, 100, stdin);
    printf("%s", line);

    /* redirect input */
    fd = open("Makefile", O_RDONLY); /* open the disk file	*/

    close(0);
    newfd = dup(fd); /* copy open fd to 0	*/

    if (newfd != 0)
    {
        fprintf(stderr, "Could not duplicate fd to 0\n");
        exit(1);
    }
    close(fd); /* close original fd	*/

    /* read and print three lines */

    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(line, 100, stdin);
    printf("%s", line);

    return EXIT_SUCCESS;
}
