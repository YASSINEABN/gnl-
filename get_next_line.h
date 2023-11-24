# ifndef GET_NEXT_LINE
#  define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char* ft_substring(const char* str, int start, int length);
char *get_next_line(int fd);

#endif