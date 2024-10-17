#include <stdio.h>	// FILE, fopen()
#include <stdio.h> // printf()
#include <stdlib.h> // free()

char	*g_file_name = "./example2";
FILE	*g_fd;

char	*get_next_line(int fd);

#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int main()
{
    char	*linha;
    int		i = 0;

    g_fd = fopen(g_file_name, "r");
    
    while((linha = get_next_line(g_fd->_fileno)) != NULL)
    {
        // ANSI escape codes for coloring
        const char *color_start = "\033[1;32m"; // Bright green
        const char *color_end = "\033[0m"; // Reset color

        printf("%sLine %i >>>%s %s", color_start, i++, color_end, linha);
        free(linha);
        // if(i == 20)
        //     break;
    }
    
    fclose(g_fd);
    return (0);
}