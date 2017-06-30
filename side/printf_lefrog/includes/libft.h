/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/includes/libft.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:26:47 by amulin            #+#    #+#             */
/*   Updated: 2016/03/24 14:34:05 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 32
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <wchar.h>

/*
**	Lists
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstappend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**	Writing
*/
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_puthex(unsigned int n, char *mode);

/*
**	Strings
*/
int					get_next_line(int const fd, char **line);

char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *hay, const char *needle);
char				*ft_strnstr(const char *hay, const char *needle, size_t n);

size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

/*
**	Conversion
*/
int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);

/*
**	ASCII
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**	Memory
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_print_memory(const void *addr, size_t size);

/*
**	Mine
*/
int					ft_abs(int i);
long long			ft_abs_ll(long long i);

int					ft_tabmax(int *tab, int siz);
int					ft_tabmin(int *tab, int siz);

unsigned int		ft_endian_swap(unsigned int input);
unsigned int		ft_uni_to_utf8(wchar_t codepoint);
int					ft_putbin(unsigned long long n, int sizeof_type);

int					ft_putwchar(wchar_t c);
int					ft_putwstr(wchar_t const *wstr);
size_t				ft_wchar_utf8len(wchar_t const wchar);
size_t				ft_wstr_utf8len(wchar_t const *wstr);
size_t				ft_wstr_memsize(wchar_t const *wstr);
size_t				ft_wcslen(const wchar_t *s);
wchar_t				*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n);
wchar_t				*ft_utf8ncpy(wchar_t *dst, const wchar_t *src, size_t n);

int					ft_ishexa(int c);
int					ft_hexchartoi(char c);
int					ft_hexbytetoi(char *hexbyte);

/*
**	Made for ft_printf
*/
int					ft_getmax(int a, int b);
void				ft_puthex_ull(unsigned long long int n, char *mode);
void				ft_putoctal(unsigned long long n);
void				ft_putnbr_ull(unsigned long long int n);
void				ft_putnbr_ll(long long n);
char				*ft_itoa_ll(long long int n, unsigned int base);
char				*ft_itoa_ull(unsigned long long n, unsigned int base);

#endif
