/*
** ETNA PROJECT, 31/10/2019 by courta_f
** c:\Users\Fr4nck\Desktop\group-716039
** File description:
**
*/

#ifndef _MY_H_
#define _MY_H_

typedef enum e_bool {
    e_false,
    e_true
} bool_t;

char *my_getline(int fd);
int my_getnbr(const char *str);
long long my_getnbrll(const char *str);
double my_getnbr_double(const char *str);
float my_getnbr_float(const char *str);
unsigned int my_isalnum(char c);
unsigned int my_isalpha(char c);
unsigned int my_isdigit(char c);
unsigned int my_isprintable(char c);
unsigned int my_isspace(char c);
unsigned int my_long_nbrlen(long n);
void my_long_nbrlen_base(long n, const char *base, unsigned int *buffer);
char my_lowcase(char c);
unsigned int my_nbrlen(int n);
void my_nbrlen_base(int n, const char *base, unsigned int *buffer);
int my_pow(int nb, int pow);
void my_put_nbr_double(double n);
void my_put_nbr_float(float n);
int my_printf(const char *format, ...);
void my_putchar(char c);
void my_putnbr(int n);
void my_putnbr_base(int n, const char *base);
void my_put_long_nbr(long n);
void my_put_long_nbr_base(long n, const char *base);
void my_put_un_long_nbr(unsigned long n);
void my_put_un_nbr(unsigned int n);
void my_put_un_nbr_base(unsigned int n, const char *base);
void my_putstr(const char *str);
char *my_strcat(char *dest, const char *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strncpy(char *dest, const char *src, unsigned int n);
char *my_strrcpy(char *dest, const char *src, unsigned int r);
char *my_strdup(const char *src);
char *my_strndup(char *str, unsigned int n);
char *my_strrdup(char *str, unsigned int r);
unsigned int my_strlen(const char *str);
char *my_strcpy(char *dest, const char *src);
char *my_trim(const char *str);
unsigned int my_un_nbrlen(unsigned int n);
void my_un_nbrlen_base(unsigned int n, const char *base, unsigned int *buffer);

#endif /* _MY_H */
