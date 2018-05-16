#include <stdint.h>

#include "path_node.h"

struct path_node new_path_node(uint32_t x, uint32_t y) {
  struct path_node node;
  node.x = x;
  node.y = y;
  node.cost = 0;  
  return node;
}

bool node_equal(struct path_node node1, struct path_node node2) {
  return (node1.x == node2.x) && (node1.y == node2.y);
}
