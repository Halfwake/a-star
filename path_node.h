#ifndef _PATH_FIND_NODE_TEAM_11
#define _PATH_FIND_NODE_TEAM_11

#include <stdint.h>
#include <stdbool.h>

#define MAX_COST 4096

struct path_node {
  int32_t x;
  int32_t y;
  uint32_t cost;
};

/*
 * Create a new path node.
 * @param x The x coordinate of the node.
 * @param y The y coordinate of the node.
 * @return A path node with the given coordiantes and
 * a cost of zero.
 */
struct path_node new_path_node(uint32_t x, uint32_t y);

/*
 * Check if two nodes have the same coordinates.
 * @param node1 The first node in the comparison.
 * @param node2 The second node in the comparison.
 * @return True if both nodes have the same coordiantes.
 */
bool node_equal(struct path_node node1, struct path_node node2);

#endif


