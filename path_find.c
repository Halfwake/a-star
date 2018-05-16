#include "path_find.h"
#include <stdio.h>

static uint32_t _abs(uint32_t a, uint32_t b) {
  if (a > b) {
    return a - b;
  }
  return b - a;
}

static uint32_t heuristic_cost_estimate(struct path_node * node1, struct path_node * node2) {
  uint32_t x_dist, y_dist;
  x_dist = _abs(node1->x, node2->x);
  y_dist = _abs(node1->y, node2->y);
  return (x_dist + y_dist) / 2;
}

static void reconstruct_path(struct path_node_dict * came_from, struct path_node current, struct path_array * array) {
  struct path_node new_current;
  array_add(array, current);
  while (node_dict_get(came_from, current, &new_current)) {
    current = new_current;
    array_add(array, current);
  }
}

void path_find(struct path_graph * graph, struct path_node start, struct path_node goal, struct path_array * return_array) {
  struct path_set closed_set;
  size_t closed_size = 32;
  struct path_node closed_node_buffer[32];
  bool closed_valid_buffer[32];
  closed_set = new_set(closed_size, closed_node_buffer, closed_valid_buffer);

  struct path_set open_set;
  size_t open_size = 32;
  struct path_node open_node_buffer[32];
  bool open_valid_buffer[32];
  open_set = new_set(open_size, open_node_buffer, open_valid_buffer);
  set_add(&open_set, &start);

  struct path_node_dict came_from;
  size_t came_from_size = 128;
  struct path_node came_from_key_buffer[128];
  struct path_node came_from_val_buffer[128];
  bool came_from_valid_buffer[128];
  came_from = new_node_dict(came_from_size, came_from_key_buffer, came_from_val_buffer, came_from_valid_buffer);

  struct path_dict g_score;
  size_t g_score_size = 32;
  struct path_node * g_score_node_buffer[32];
  uint32_t g_score_cost_buffer[32];
  bool g_score_valid_buffer[32];
  g_score = new_dict(g_score_size, g_score_node_buffer, g_score_cost_buffer, g_score_valid_buffer);
  for (size_t i = 0; i < graph->size; i++) {
    dict_set(&g_score, &(graph->node_buffer[i]), MAX_COST);
  }
  dict_set(&g_score, &start, 0);

  struct path_dict f_score;
  size_t f_score_size = 32;
  struct path_node * f_score_node_buffer[32];
  uint32_t f_score_cost_buffer[32];
  bool f_score_valid_buffer[32];
  f_score = new_dict(f_score_size, f_score_node_buffer, f_score_cost_buffer, f_score_valid_buffer);
  for (size_t i = 0; i < graph->size; i++) {
    dict_set(&f_score, &(graph->node_buffer[i]), MAX_COST);
  }
  dict_set(&f_score, &start, heuristic_cost_estimate(&start, &goal));

  while (!set_is_empty(&open_set)) {
    // Find node in open set with lowest f_score value.
    struct path_node * current;
    uint32_t cost;
    bool found_current = false;
    for (size_t i = 0; i < graph->size; i++) {
      if (set_is_member(&open_set, &graph->node_buffer[i])) {
	uint32_t temp_cost;
	dict_get(&f_score, &graph->node_buffer[i], &temp_cost);
	if ((temp_cost < cost) || !found_current) {
	  cost = temp_cost;
	  current = &(graph->node_buffer[i]);
	  found_current = true;
	}
      }
    }
    if (node_equal(*current, goal)) {
      reconstruct_path(&came_from, *current, return_array);
      return;
    }

    set_remove(&open_set, current);
    set_add(&closed_set, current);

    for (size_t i = 0; i < graph->size; i++) {
      struct path_node neighbor = graph->node_buffer[i];
      bool failure;
      if (graph_is_adjacent(graph, current, &neighbor, &failure)) {
	if (set_is_member(&closed_set, &neighbor)) {
	  continue;
	}

	if (!set_is_member(&open_set, &neighbor)) {
	  set_add(&open_set, &neighbor);
	}

	uint32_t tenative_g_score;
	dict_get(&g_score, current, &tenative_g_score);
	tenative_g_score += 1;
	uint32_t neighbor_g_score;
	dict_get(&g_score, &neighbor, &neighbor_g_score);
	if (tenative_g_score >= neighbor_g_score) {
	  continue;
	}
	
	node_dict_set(&came_from, neighbor, *current);
	dict_set(&g_score, &neighbor, tenative_g_score);
	dict_set(&f_score, &neighbor, neighbor_g_score + heuristic_cost_estimate(&neighbor, &goal));
      }
    }
  }
}
