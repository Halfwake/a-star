#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "path_node.h"
#include "path_set.h"

void assert(int check, char * description) {
  printf("[%s] - %s\n", check ? "T" : "F", description);
}

void test_basic() {
  struct path_set set;
  size_t size = 8;
  struct path_node node_buffer[8];
  bool valid_buffer[8];

  printf("Test Set Basic\n");

  struct path_node node0 = new_path_node(0, 0);
  struct path_node node1 = new_path_node(1, 1);
  struct path_node node2 = new_path_node(2, 2);
  //struct path_node node3 = new_path_node(3, 3);
  //struct path_node node4 = new_path_node(4, 4);

  set = new_set(size, node_buffer, valid_buffer);
  assert(set_is_empty(&set), "Set starts empty.");
  assert(!set_is_member(&set, &node0), "Empty set doesn't contain value.");
  assert(set_add(&set, &node0), "Value added.");
  assert(set_add(&set, &node1), "Value added.");
  assert(set_add(&set, &node2), "Value added.");
  assert(set_is_member(&set, &node0), "Added value is member.");
  assert(set_is_member(&set, &node1), "Added value is member.");
  assert(set_is_member(&set, &node2), "Added value is member.");

  assert(set_remove(&set, &node1), "Value removed.");
  assert(set_is_member(&set, &node0), "Added value is member.");
  assert(!set_is_member(&set, &node1), "Removed value is not member.");
  assert(set_is_member(&set, &node2), "Added value is member.");
  assert(!set_is_empty(&set), "Set is no longer empty.");

}

int main() {
  printf("Test Set\n");
  test_basic();
  return 0;
}
