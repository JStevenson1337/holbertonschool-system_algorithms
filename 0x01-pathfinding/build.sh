

gcc -o 0-backtracking_array -Wall -Wextra -Werror -pedantic 0-main.c 0-backtracking_array.c libqueues.a -fPIE

gcc -o 1-backtracking_graph -Wall -Wextra -Werror -pedantic 1-main.c 1-backtracking_graph.c libqueues.a libgraphs.a -fPIE


gcc -o 2-dijkstra_graph -Wall -Wextra -Werror -pedantic 2-main.c 2-dijkstra_graph.c libqueues.a libgraphs.a -fPIE