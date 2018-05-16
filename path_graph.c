#include "path_graph.h"

struct path_graph new_graph(size_t size, struct path_node * node_buffer, bool * edge_buffer) {
  struct path_graph graph;
  graph.size = size;
  graph.node_buffer = node_buffer;
  graph.edge_buffer = edge_buffer;
  for (size_t i = 0; i < size * size; i++) {
    graph.edge_buffer[i] = false;
  }
  return graph;
}

/*
 * Find the index of a node in a graph array.
 * @param graph The graph to search.
 * @param node The node to search for.
 * @param failure True if node could not be found;
 * @return The index of the node if it could be found.
 */
static size_t find_node_index(struct path_graph * graph, struct path_node * node, bool * failure) {
  for (size_t i = 0; i < graph->size; i++) {
    if (node_equal(*node, graph->node_buffer[i])) {
      *failure = false;
      return i;
    }
  }
  *failure = true;
  return 0;
}

bool graph_is_adjacent(struct path_graph * graph, struct path_node * node1, struct path_node * node2, bool * failure) {
  bool failure1 = false;
  bool failure2 = false;
  size_t index1 = find_node_index(graph, node1, &failure1);
  size_t index2 = find_node_index(graph, node2, &failure2);
  if (failure1 || failure2) {
    *failure = true;
    return false;
  }
  *failure = false;
  return graph->edge_buffer[index1 + (graph->size * index2)];
}

void graph_set_adjacent(struct path_graph * graph, struct path_node * node1, struct path_node * node2, bool * failure) {
  bool failure1 = false;
  bool failure2 = false;
  size_t index1 = find_node_index(graph, node1, &failure1);
  size_t index2 = find_node_index(graph, node2, &failure2);
  if (failure1 || failure2) {
    *failure = true;
    return;
  }
  *failure = false;
  graph->edge_buffer[index1 + (graph->size * index2)] = true;
  graph->edge_buffer[index2 + (graph->size * index1)] = true;
}
