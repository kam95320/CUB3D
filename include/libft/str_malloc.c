
#include "libft.h"

char	*str_malloc(int size)
{
    char *mal;
    mal =  malloc(sizeof(char) * size);
    if(!mal)
    {
        return(NULL);
    }
    return(mal);
}