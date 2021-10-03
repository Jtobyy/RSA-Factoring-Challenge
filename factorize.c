#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void factor(unsigned long long int n);

/**
 *main - Factorize as many numbers as possible into a product
 *of two smaller numbers'''
 *
 *@argc: length of command line arguments
 *@argv: array of cmd line args
 */
int main(int argc, char *argv[])
{
  int fd;
  int rd;
  int fd_count;
  int i;
  unsigned long long int n;
  int j;
  int k;
  char *ns;
  char *endptr;
  char *buf = NULL;
  if (argc != 2)
    {
    printf("Usage: factors <file>\n");
    return (1);
    }
  fd = open(argv[1], O_RDONLY);
  if (fd == -1)
    {
    printf("Error: could not open file\n");
    return (1);
    }
  fd_count = 0;
  buf = malloc(sizeof(*buf) * 500);
  if (buf == NULL)
    {
      printf("Error: malloc failed\n");
      return (1);
    }
  do {
    rd = read(fd, buf, 500);
    if (rd == -1)
      {
	printf("Error: read failed\n");
	return (1);
      }
    fd_count += rd;
  } while (rd != 0);
  if (fd_count > 500)
    {
      buf = realloc(buf, fd_count);
      lseek(fd, 0, SEEK_SET);
      rd = read(fd, buf, fd_count);
      if (rd == -1)
	{
	  printf("Error: read failed\n");
	  return (1);
	}
    }
  j = 0;
  for (i = 0; buf[i] != '\n', i < fd_count ; i = j + 1)
    {
      for (j = i, k = 0; buf[j] != '\n' ; j++)
	k++;
      ns = malloc(sizeof(*ns) * (k + 1));
      if (ns == NULL)
	{
	printf("Error: malloc failed");
	return (1);
	}
      for (j = i, k = 0; buf[j] != '\n' ; j++, k++)
	  ns[k] = buf[j];
      ns[k] = '\0';
      n = strtoull(ns, &endptr, 10);
      factor(n);
      free(ns);
    }
  free(buf);
  close(fd);
  return (0); 
}

/**
 * factor - prints out the factor of an integer
 * @n: integer
 * Return: void
 */
void factor(unsigned long long int n)
{
  long long int i;
  for(i = 2; i < n; i++)
    {
      if (n % i == 0)
	{
	  printf("%llu=%llu*%llu\n", n, n / i, i);
	  break;
	}
    }
  return;
}
