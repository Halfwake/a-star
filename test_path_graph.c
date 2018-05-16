#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "path_node.h"
#include "path_graph.h"

void assert(int check, char * description) {
  printf("[%s] - %s\n", check ? "T" : "F", description);
}

void test_basic() {
  size_t size = 4;
  struct path_node node_buffer[4];
  node_buffer[0] = new_path_node(0, 0);
  node_buffer[1] = new_path_node(1, 0);
  node_buffer[2] = new_path_node(0, 1);
  node_buffer[3] = new_path_node(3, 3);
  bool edge_buffer[16];
  bool failure;

  printf("Test Basic Graph\n");
  
  struct path_graph graph = new_graph(size, node_buffer, edge_buffer);

  struct path_node node1 = new_path_node(0, 0);
  struct path_node node2 = new_path_node(1, 0);
  struct path_node node3 = new_path_node(0, 1);
  struct path_node node4 = new_path_node(3, 3);
  
  graph_set_adjacent(&graph, &node1, &node3, &failure);
  assert(!failure, "Did not fail.");
  graph_set_adjacent(&graph, &node1, &node2, &failure);
  assert(!failure, "Did not fail.");
  graph_set_adjacent(&graph, &node3, &node4, &failure);
  assert(!failure, "Did not fail.");
  graph_set_adjacent(&graph, &node2, &node4, &failure);
  assert(!failure, "Did not fail.");
  graph_set_adjacent(&graph, &node4, &node1, &failure);
  assert(!failure, "Did not fail.");

  assert(graph_is_adjacent(&graph, &node1, &node3, &failure),
	 "Is adjacaent.");
  assert(!failure, "Did not fail.");
  assert(graph_is_adjacent(&graph, &node3, &node1, &failure),
	 "Is adjacaent.");
  assert(!failure, "Did not fail.");

  assert(graph_is_adjacent(&graph, &node1, &node2, &failure),
	 "Is adjacaent.");
  assert(!failure, "Did not fail.");
  assert(graph_is_adjacent(&graph, &node2, &node1, &failure),
	 "Is adjacaent.");
  assert(!failure, "Did not fail.");

  assert(graph_is_adjacent(&graph, &node4, &node3, &failure),
	 "Is adjacaent.");
  assert(!failure, "Did not fail.");
  assert(graph_is_adjacent(&graph, &node3, &node4, &failure),
	 "Is adjacaent.");
  assert(!failure, "Did not fail.");

  assert(graph_is_adjacent(&graph, &node4, &node2, &failure),
	 "Is adjacaent.");
  assert(!failure, "Did not fail.");
  assert(graph_is_adjacent(&graph, &node2, &node4, &failure),
	 "Is adjacaent.");
  assert(!failure, "Did not fail.");

  assert(!graph_is_adjacent(&graph, &node2, &node3, &failure),
	 "Is not adjacaent.");
  assert(!failure, "Did not fail.");
  assert(!graph_is_adjacent(&graph, &node3, &node2, &failure),
	 "Is not adjacaent.");
  assert(!failure, "Did not fail.");
}

int main() {
  printf("Test Graph\n");
  test_basic();
  return 0;
}
