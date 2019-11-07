/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#include <my.h>
#include <stdlib.h>
#include <unistd.h>

static char *new_line(char *str, char c)
{
    int i = 0;
    char *newstr = malloc(sizeof(char) * (my_strlen(str) + 2));

    if (newstr == NULL)
        return (NULL);
    while (str[i]) {
        newstr[i] = str[i];
        i++;
    }
    newstr[i++] = c;
    newstr[i] = 0;
    free(str);
    return (newstr);
}

static char *reader(int fd, char *line, int i, int len)
{
    char c;

    while (i) {
        if ((i = read(fd, &c, 1)) == -1)
            return (NULL);
        len = len + 1;
        if (i == 0)
            return (NULL);
        if (len == 1 && c == '\n')
            return (line);
        if (c == '\n' || c == '\0')
            return (line);
        if ((line = new_line(line, c)) == NULL)
            return (NULL);
    }
    return (NULL);
}

char *my_getline(int fd)
{
    int i = 1;
    int len = 0;
    char *line = malloc(sizeof(char) * 2);

    if (line == NULL)
        return (NULL);
    line[0] = 0;
    return (reader(fd, line, i, len));
}
