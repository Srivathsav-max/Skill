#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
/********************************************************************/
main ()
{
 int fd;
 char str[100];
 mkfifo ("aPipe", 0660); /* Create named pipe */
 fd = open ("aPipe", O_RDONLY); /* Open it for reading */
  while (readLine (fd, str)) /* Display received messages */
   printf ("%s\n", str);
  close (fd); /* Close pipe */
}
/********************************************************************/
readLine (fd, str)
int fd;
char* str;
/* Read a single NULL-terminated line into str from fd */
/* Return 0 when the end-of-input is reached and 1 otherwise */
{
 int n;
  do /* Read characters until NULL or end-of-input */
   {
     n = read (fd, str, 1); /* Read one character */
   }
 while (n > 0 && *str++ != 0);
 return (n > 0); /* Return false if end-of-input */
}

