exec:
	@cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o exec
	@./exec || (echo "Execution failed; removing exec." && rm -f exec)
	@rm -f exec

nf:
	@cc -D BUFFER_SIZE=4 main.c get_next_line.c get_next_line_utils.c -o exec
	@./exec || (echo "Execution failed; removing exec." && rm -f exec)
	@rm -f exec

detailed:
	cc -D BUFFER_SIZE=4 main.c get_next_line.c get_next_line_utils.c -o exec -g3