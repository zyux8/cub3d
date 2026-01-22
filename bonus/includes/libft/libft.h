/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:23:28 by ohaker            #+#    #+#             */
/*   Updated: 2025/12/02 20:23:31 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(LIBFT_H)
# define LIBFT_H
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*ft_append_str(char *dest, char *src);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);
void				*ft_bzero(void *s, unsigned long c);
void				*ft_calloc(size_t num, size_t size);
int					ft_chrnbr(char *str, char c);
int					ft_count_words(const char *str, char c);
int					ft_conv_to_neg(int x);
int					ft_conv_to_pos(int x);
void				ft_error(char *error_msg);
void				ft_free_split(char **split);
int					ft_intlen(int n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isint(char *s);
int					ft_isspace(int c);
int					ft_isprint(int c);
int					ft_isuppercase(char c);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_memchr(const void *str, int c, unsigned long n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *dest, const void *src, unsigned long n);
void				*ft_memmove(void *dest, const void *src, unsigned long n);
void				*ft_memset(void *s, int c, unsigned long n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *str, int fd);
int					ft_putnbry(int n, int y);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char *str, int fd);
int					ft_putstry(char *str, int y);
int					ft_putunsignbr(unsigned int n, int y);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
char				**ft_split(char const *str, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *str1, const char *str2);
char				*ft_strjoin_multi(const char *first, ...);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
int					ft_strlcpy(char *dest, const char *src, unsigned long n);
int					ft_strlen(const char *str);
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strndup(const char *s,
						long unsigned int amount_of_chars);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strrev(char *str);
char				*ft_strtrim(const char *str, const char *set);
char				*ft_substr(const char *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*get_next_line(int fd);

#endif
