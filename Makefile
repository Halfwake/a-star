CFLAGS=-Wall

test: test_path_queue.out test_path_dict.out test_path_set.out test_path_graph.out test_path_node_dict.out test_path_find.out test_path_array.out
	./test_path_dict.out
	./test_path_set.out
	./test_path_graph.out
	./test_path_node_dict.out
	./test_path_find.out
	./test_path_array.out
#	./test_path_queue.out

test_path_find.out: test_path_find.c path_node_dict.o path_set.o path_dict.o path_find.o path_node.o
	gcc $(CFLAGS) test_path_find.c path_node_dict.o path_set.o path_dict.o path_find.o path_node.o path_graph.o path_array.o -o test_path_find.out

test_path_node_dict.out: test_path_node_dict.c path_node_dict.o
	gcc $(CFLAGS) test_path_node_dict.c path_node_dict.o  path_node.o -o test_path_node_dict.out

test_path_dict.out: test_path_dict.c path_queue.o path_node.o path_set.o path_dict.o
	gcc $(CFLAGS) test_path_dict.c path_queue.o path_node.o path_set.o path_dict.o -o test_path_dict.out

test_path_set.out: test_path_set.c path_queue.o path_node.o path_set.o path_dict.o
	gcc $(CFLAGS) test_path_set.c path_queue.o path_node.o path_set.o path_dict.o -o test_path_set.out

test_path_queue.out: test_path_queue.c path_queue.o path_node.o path_set.o path_dict.o
	gcc $(CFLAGS) test_path_queue.c path_queue.o path_node.o path_set.o path_dict.o -o test_path_queue.out

test_path_graph.out: test_path_graph.c path_graph.o path_node.o
	gcc $(CFLAGS) test_path_graph.c path_graph.o path_node.o -o test_path_graph.out

test_path_array.out: test_path_array.c path_array.o path_node.o
	gcc $(CFLAGS) test_path_array.c path_array.o path_node.o -o test_path_array.out

path_array.o: path_array.c path_array.h
	gcc $(CFLAGS) -c path_array.c

path_node_dict.o: path_node_dict.c path_node_dict.h
	gcc $(CFLAGS) -c path_node_dict.c

path_graph.o: path_graph.c path_graph.h
	gcc $(CFLAGS) -c path_graph.c

path_dict.o: path_dict.c path_dict.h
	gcc $(CFLAGS) -c path_dict.c

path_set.o: path_set.c path_set.h
	gcc $(CFLAGS) -c path_set.c

path_queue.o: path_queue.c path_queue.h
	gcc $(CFLAGS) -c path_queue.c

path_node.o: path_node.c path_node.h
	gcc $(CFLAGS) -c path_node.c
