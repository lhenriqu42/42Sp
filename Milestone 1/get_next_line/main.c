#include <stdio.h>	// FILE, fopen()
#include <stdio.h> // printf()
#include <stdlib.h> // free()

char	*g_file_name = "./example";
FILE	*g_fd;

char	*get_next_line(int fd);

int main()
{
	char	*linha;
	int		i = 0;

	g_fd = fopen(g_file_name, "r");
	
	while((linha = get_next_line(g_fd->_fileno)) != NULL)
	{
		printf("Line %i >>> %s", i++, linha);
		free(linha);
	}
	
	fclose(g_fd);
	return (0);
}