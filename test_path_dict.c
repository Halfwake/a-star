#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "path_node.h"
#include "path_dict.h"

void assert(int check, char * description) {
  printf("[%s] - %s\n", check ? "T" : "F", description);
}

void test_basic() {
  printf("Test Dict Basic\n");
  struct path_dict dict;
  size_t size = 8;
  struct path_node * node_buffer[8];
  uint32_t cost_buffer[8];
  bool valid_buffer[8];

  struct path_node node0 = new_path_node(0, 0);
  struct path_node node1 = new_path_node(1, 1);
  struct path_node node2 = new_path_node(2, 2);
  struct path_node node3 = new_path_node(3, 3);
  struct path_node node4 = new_path_node(4, 4);
  dict = new_dict(size, node_buffer, cost_buffer, valid_buffer);
  assert(dict_set(&dict, &node0, 10), "Added correctly.");
  assert(dict_set(&dict, &node1, 20), "Added correctly.");
  assert(dict_set(&dict, &node3, 30), "Added correctly.");
  assert(dict_set(&dict, &node2, 40), "Added correctly.");
  assert(dict_set(&dict, &node3, 100), "Reset correctly.");

  uint32_t temp;
  assert(dict_get(&dict, &node0, &temp), "Got correctly.");
  assert(temp == 10, "temp == 10");
  assert(dict_get(&dict, &node1, &temp), "Got correctly.");
  assert(temp == 20, "temp == 20");
  assert(dict_get(&dict, &node2, &temp), "Got correctly.");
  assert(temp == 40, "temp == 40");
  assert(dict_get(&dict, &node3, &temp), "Got correctly.");
  assert(temp == 100, "temp == 100");
  assert(!dict_get(&dict, &node4, &temp), "Could not find.");
}

int main() {
  test_basic();
  return 0;
}
