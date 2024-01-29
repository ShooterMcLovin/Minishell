/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpicard <alpicard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:46:09 by alpicard          #+#    #+#             */
/*   Updated: 2024/01/25 17:15:50 by alpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef BASE_LOW
#  define BASE_LOW "0123456789abcdef"
# endif

# ifndef BASE_UP
#  define BASE_UP "0123456789ABCDEF"
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
//libft
int					ft_isalnum(int an);
int					ft_isalpha(int a);
int					ft_isascii(int ac);
int					ft_isdigit(int d);
int					ft_isprint(int pr);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
int					ft_atoi(const char *nptr);
char				*ft_strdup(const char *s1);
char				*ft_strdup2(const char *s1);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *neo);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *neo);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
// get next line
char				*get_next_line(int fd);
int					ft_strchrgnl(char *str, int c);
char				*ft_strjoingnl(char *s1, char *s2);
char				*ft_substrgnl(char *save, int c);
void				*ft_free(void *p);
char				*ft_save(char *save);
char				*ft_read(int fd, char *save);
// printf
int					ft_printchar(char c);
int					ft_printstr(char *str);
int					ft_printptr(unsigned long long num);
int					ft_printnbr_base(unsigned int nb, char *base_ref,
						unsigned int base);
int					ft_printnbr(unsigned int nb);
int					ft_printf(const char *str, ...);
int					ft_strchr_switch(const char *str, int c);
// extra
void				ftpnb(int base, int nb);
//utils
int					dup_len(char *s1);
int					duplen_part2(const char *s1, int trigger, int j);
int					set_trigger_single(const char *s1, int j, int trigger);
int					set_trigger(const char *s1, int j, int trigger);
#endif
