#include "shell.h"

/**
 * _eputs - prints input string
 * @str: the string printed
 * return: 0
 */

void _eputs(char *str)

{

        int j = 0;


        if (!str)

                return;

        while (str[j] != '\0')

        {

                _eputchar(str[j]);

                j++;

        }

}


/**

 * _eputchar - writes character c to stderr
 * @c: character to print
 * Return: 1 if successful
 * On error, -1 returns errno set appropriately
 */

int _eputchar(char c)

{

        static int j;

        static char buf[WRITE_BUF_SIZE];


        if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)

        {

                write(2, buf, j);

                j = 0;

        }

        if (c != BUF_FLUSH)

                buf[j++] = c;

        return (1);

}


/**

 * _putfd - writes character c to fd
 * @c: character print
 * @fd: file descriptor to write 
 * Return: 1
 * On error, -1 is returns errno set appropriately
 */

int _putfd(char c, int fd)

{

        static int j;

        static char buf[WRITE_BUF_SIZE];


        if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)

        {

                write(fd, buf, j);

                j = 0;

        }

        if (c != BUF_FLUSH)

                buf[j++] = c;

        return (1);

}


/**
 * _putsfd - print input string
 * @str: string printed
 * @fd: file descriptor to write
 * Return: number of chars put
 */

int _putsfd(char *str, int fd)

{

        int j = 0;


        if (!str)

                return (0);

        while (*str)

        {

                j += _putfd(*str++, fd);

        }

        return (j);

}
