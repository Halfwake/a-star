#include "path_set.h"

struct path_set new_set(size_t size, struct path_node * node_buffer, bool * valid_buffer) {
  struct path_set set;
  set.size = size;
  set.node_buffer = node_buffer;
  set.valid_buffer = valid_buffer;
  for (size_t i = 0; i < size; i++) {
    set.valid_buffer[i] = false;
  }
  return set;
}

bool set_is_member(struct path_set * set, struct path_node * node) {
  for (size_t i = 0; i < set->size; i++) {
    if (set->valid_buffer[i]) {
      if (node_equal(set->node_buffer[i], *node)) {
	return true;
      }
    }
  }
  return false;
}

bool set_add(struct path_set * set, struct path_node * node) {
  for (size_t i = 0; i < set->size; i++) {
    if (!set->valid_buffer[i]) {
      set->valid_buffer[i] = true;
      set->node_buffer[i] = *node;
      return true;
    }
  }
  return false;
}

bool set_remove(struct path_set * set, struct path_node * node) {
  for (size_t i = 0; i < set->size; i++) {
    if (node_equal(set->node_buffer[i], *node)) {
      set->valid_buffer[i] = false;
      return true;
    }
  }
  return false;
}

bool set_is_empty(struct path_set * set) {
  for (size_t i = 0; i < set->size; i++) {
    if (set->valid_buffer[i]) {
      return false;
    }
  }
  return true;
}
