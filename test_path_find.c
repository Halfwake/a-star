#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "path_node.h"
#include "path_graph.h"
#include "path_find.h"

void assert(int check, char * description) {
  printf("[%s] - %s\n", check ? "T" : "F", description);
}

void test_basic() {
  printf("Test Path Basic Find\n");
  
  size_t size = 4;
  struct path_node node_buffer[4];
  node_buffer[0] = new_path_node(0, 0);
  node_buffer[1] = new_path_node(1, 0);
  node_buffer[2] = new_path_node(0, 1);
  node_buffer[3] = new_path_node(3, 3);
  bool edge_buffer[16];
  bool failure;

  size_t array_size = 16;
  struct path_node array_buffer[16];
  struct path_array return_array = new_array(array_size, array_buffer);

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

  path_find(&graph, node2, node3, &return_array);
  struct path_node expected[3];
  expected[0] = new_path_node(1, 0);
  expected[1] = new_path_node(0, 0);
  expected[2] = new_path_node(0, 1);
  for (size_t i = 0; i < return_array.size; i++) {
    struct path_node node = return_array.buffer[i];
    assert(node_equal(node, expected[2 - i]), "Expected Node");
  }

  return_array = new_array(array_size, array_buffer);
  path_find(&graph, node1, node3, &return_array);
  for (size_t i = 0; i < return_array.size; i++) {
    struct path_node node = return_array.buffer[i];
    assert(node_equal(node, expected[2 - i]), "Expected Node");
  }

  return_array = new_array(array_size, array_buffer);
  path_find(&graph, node3, node3, &return_array);
  for (size_t i = 0; i < return_array.size; i++) {
    struct path_node node = return_array.buffer[i];
    assert(node_equal(node, expected[2 - i]), "Expected Node");
  }
}

void test_real() {
  bool edge_buffer[1024/*32 ^ 2*/];
  bool failure;

  size_t array_size = 256;
  struct path_node array_buffer[256];
  struct path_array return_array = new_array(array_size, array_buffer);
  
  // Create Nodes
  struct path_node node00 = new_path_node(0, 0);
  struct path_node node10 = new_path_node(1, 0);
  struct path_node node20 = new_path_node(2, 0);
  struct path_node node30 = new_path_node(3, 0);
  struct path_node node40 = new_path_node(4, 0);
  struct path_node node50 = new_path_node(5, 0);
  struct path_node node60 = new_path_node(6, 0);
  struct path_node node70 = new_path_node(7, 0);

  struct path_node node01 = new_path_node(0, 1);
  struct path_node node11 = new_path_node(1, 1);
  struct path_node node21 = new_path_node(2, 1);
  struct path_node node31 = new_path_node(3, 1);
  struct path_node node41 = new_path_node(4, 1);
  struct path_node node51 = new_path_node(5, 1);
  struct path_node node61 = new_path_node(6, 1);
  struct path_node node71 = new_path_node(7, 1);

  struct path_node node02 = new_path_node(0, 2);
  struct path_node node12 = new_path_node(1, 2);
  struct path_node node22 = new_path_node(2, 2);
  struct path_node node32 = new_path_node(3, 2);
  struct path_node node42 = new_path_node(4, 2);
  struct path_node node52 = new_path_node(5, 2);
  struct path_node node62 = new_path_node(6, 2);
  struct path_node node72 = new_path_node(7, 2);

  struct path_node node03 = new_path_node(0, 3);
  struct path_node node13 = new_path_node(1, 3);
  struct path_node node23 = new_path_node(2, 3);
  struct path_node node33 = new_path_node(3, 3);
  struct path_node node43 = new_path_node(4, 3);
  struct path_node node53 = new_path_node(5, 3);
  struct path_node node63 = new_path_node(6, 3);
  struct path_node node73 = new_path_node(7, 3);

  size_t size = 32;
  struct path_node node_buffer[32];
  node_buffer[0] = node00;
  node_buffer[1] = node10;
  node_buffer[2] = node20;
  node_buffer[3] = node30;
  node_buffer[4] = node40;
  node_buffer[5] = node50;
  node_buffer[6] = node60;
  node_buffer[7] = node70;
  node_buffer[8] = node01;
  node_buffer[9] = node11;
  node_buffer[10] = node21;
  node_buffer[11] = node31;
  node_buffer[12] = node41;
  node_buffer[13] = node51;
  node_buffer[14] = node61;
  node_buffer[15] = node71;
  node_buffer[16] = node02;
  node_buffer[17] = node12;
  node_buffer[18] = node22;
  node_buffer[19] = node32;
  node_buffer[20] = node42;
  node_buffer[21] = node52;
  node_buffer[22] = node62;
  node_buffer[23] = node72;
  node_buffer[24] = node03;
  node_buffer[25] = node13;
  node_buffer[26] = node23;
  node_buffer[27] = node33;
  node_buffer[28] = node43;
  node_buffer[29] = node53;
  node_buffer[30] = node63;
  node_buffer[31] = node73;

  // Create Graph
  struct path_graph graph = new_graph(size, node_buffer, edge_buffer);

  // Create Column Edges
  graph_set_adjacent(&graph, &node00, &node01, &failure);
  graph_set_adjacent(&graph, &node01, &node02, &failure);
  graph_set_adjacent(&graph, &node02, &node03, &failure);

  graph_set_adjacent(&graph, &node10, &node11, &failure);
  graph_set_adjacent(&graph, &node11, &node12, &failure);
  graph_set_adjacent(&graph, &node12, &node13, &failure);

  graph_set_adjacent(&graph, &node20, &node21, &failure);
  graph_set_adjacent(&graph, &node21, &node22, &failure);
  graph_set_adjacent(&graph, &node22, &node23, &failure);

  graph_set_adjacent(&graph, &node30, &node31, &failure);
  graph_set_adjacent(&graph, &node31, &node32, &failure);
  graph_set_adjacent(&graph, &node32, &node33, &failure);

  graph_set_adjacent(&graph, &node40, &node41, &failure);
  graph_set_adjacent(&graph, &node41, &node42, &failure);
  graph_set_adjacent(&graph, &node42, &node43, &failure);

  graph_set_adjacent(&graph, &node50, &node51, &failure);
  graph_set_adjacent(&graph, &node51, &node52, &failure);
  graph_set_adjacent(&graph, &node52, &node53, &failure);

  graph_set_adjacent(&graph, &node70, &node71, &failure);
  graph_set_adjacent(&graph, &node71, &node72, &failure);
  graph_set_adjacent(&graph, &node72, &node73, &failure);  

  // Create Row Edges
  graph_set_adjacent(&graph, &node00, &node10, &failure);
  graph_set_adjacent(&graph, &node10, &node20, &failure);
  graph_set_adjacent(&graph, &node20, &node30, &failure);
  graph_set_adjacent(&graph, &node30, &node40, &failure);
  graph_set_adjacent(&graph, &node40, &node50, &failure);
  graph_set_adjacent(&graph, &node50, &node60, &failure);
  graph_set_adjacent(&graph, &node60, &node70, &failure);

  graph_set_adjacent(&graph, &node01, &node11, &failure);
  graph_set_adjacent(&graph, &node11, &node21, &failure);
  graph_set_adjacent(&graph, &node21, &node31, &failure);
  graph_set_adjacent(&graph, &node31, &node41, &failure);
  graph_set_adjacent(&graph, &node41, &node51, &failure);
  graph_set_adjacent(&graph, &node51, &node61, &failure);
  graph_set_adjacent(&graph, &node61, &node71, &failure);

  graph_set_adjacent(&graph, &node02, &node12, &failure);
  graph_set_adjacent(&graph, &node12, &node22, &failure);
  graph_set_adjacent(&graph, &node22, &node32, &failure);
  graph_set_adjacent(&graph, &node32, &node42, &failure);
  graph_set_adjacent(&graph, &node42, &node52, &failure);
  graph_set_adjacent(&graph, &node52, &node62, &failure);
  graph_set_adjacent(&graph, &node62, &node72, &failure);

  graph_set_adjacent(&graph, &node03, &node13, &failure);
  graph_set_adjacent(&graph, &node13, &node23, &failure);
  graph_set_adjacent(&graph, &node23, &node33, &failure);
  graph_set_adjacent(&graph, &node33, &node43, &failure);
  graph_set_adjacent(&graph, &node43, &node53, &failure);
  graph_set_adjacent(&graph, &node53, &node63, &failure);
  graph_set_adjacent(&graph, &node63, &node73, &failure);

  path_find(&graph, node00, node33, &return_array);
  printf("Result\n");
  for (size_t i = 0; i < return_array.size; i++) {
    struct path_node node = return_array.buffer[i];
    printf("<%d:%d>\n", node.x, node.y);
  }

  return_array = new_array(array_size, array_buffer);
  path_find(&graph, node10, node33, &return_array);
  printf("Result\n");
  for (size_t i = 0; i < return_array.size; i++) {
    struct path_node node = return_array.buffer[i];
    printf("<%d:%d>\n", node.x, node.y);
  }

  return_array = new_array(array_size, array_buffer);
  path_find(&graph, node20, node33, &return_array);
  printf("Result\n");
  for (size_t i = 0; i < return_array.size; i++) {
    struct path_node node = return_array.buffer[i];
    printf("<%d:%d>\n", node.x, node.y);
  }

  return_array = new_array(array_size, array_buffer);
  path_find(&graph, node30, node33, &return_array);
  printf("Result\n");
  for (size_t i = 0; i < return_array.size; i++) {
    struct path_node node = return_array.buffer[i];
    printf("<%d:%d>\n", node.x, node.y);
  }

  return_array = new_array(array_size, array_buffer);
  path_find(&graph, node31, node33, &return_array);
  printf("Result\n");
  for (size_t i = 0; i < return_array.size; i++) {
    struct path_node node = return_array.buffer[i];
    printf("<%d:%d>\n", node.x, node.y);
  }

  return_array = new_array(array_size, array_buffer);
  path_find(&graph, node32, node33, &return_array);
  printf("Result\n");
  for (size_t i = 0; i < return_array.size; i++) {
    struct path_node node = return_array.buffer[i];
    printf("<%d:%d>\n", node.x, node.y);
  }

  return_array = new_array(array_size, array_buffer);
  path_find(&graph, node33, node33, &return_array);
  printf("Result\n");
  for (size_t i = 0; i < return_array.size; i++) {
    struct path_node node = return_array.buffer[i];
    printf("<%d:%d>\n", node.x, node.y);
  }
}

int main() {
  printf("Test Path Find\n");
  test_basic();
  test_real();
  return 0;
}
