/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:08:59 by smeftah-          #+#    #+#             */
/*   Updated: 2023/05/12 20:36:51 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include<unistd.h>
# include<stdlib.h>

typedef struct s_env
{
	char			*key;
	char			*val;
	int				index;
	struct s_env	*next;
}					t_env;

void	*ft_memcpy(void *dst, const void *src, size_t n);

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_isalpha(int c);
int		ft_strlen(char *s);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(char *s, int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strtrim(char *s1, char *set, int st);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(char *src);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_substr(char *s, int start, size_t len);
t_env	*ft_lstnew(char	*key, char *val, int index);
int		ft_lstsize(t_env *lst);
void	ft_lstadd_back(t_env **lst, t_env *new);
char	**ft_split(char *s, char c);
char	*ft_strjoin_e(char *s1, char *s2);
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strtrim_lib(char	*s1, char	*set);

#endif
