#ifndef _TEAM11_PATH_GRAPH
#define _TEAM11_PATH_GRAPH

#include <stdint.h>

#include "path_node.h"

/*
 * A graph object for path finding.
 */
struct path_graph {
  size_t size;
  struct path_node * node_buffer;
  bool * edge_buffer;
};

/*
 * Create a new graph object.
 * @param size The amount of nodes in the graph.
 * @param node_buffer A buffer containing the nodes in the graph. It must match the length of size.
 * @param edge_buffer A buffer to be used for edges. It must be size squared units large.
 * @return A new graph with no edges.
 */
struct path_graph new_graph(size_t size, struct path_node * node_buffer, bool * edge_buffer);

/*
 * Check if two nodes have an edge between them.
 * @param graph The graph the nodes belong to.
 * @param node1 The first node in the comparison.
 * @param node2 The second node in the comparison.
 * @param failure True if a given node was not in the graph.
 * @return True if the nodes have an edge between them.
 */
bool graph_is_adjacent(struct path_graph * graph, struct path_node * node1, struct path_node * node2, bool * failure);

/*
 * Create an edge between two nodes.
 * @param The graph to add an edge to.
 * @param node1 The first node in the connection.
 * @param node2 The second node in the connection.
 * @param failure True if a given node was not in the graph.
 */
void graph_set_adjacent(struct path_graph * graph, struct path_node * node1, struct path_node * node2, bool * failure);

#endif
