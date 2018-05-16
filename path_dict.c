#include "path_dict.h"

struct path_dict new_dict(size_t size, struct path_node ** node_buffer, uint32_t * cost_buffer, bool * valid_buffer) {
  struct path_dict dict;
  dict.size = size;
  dict.node_buffer = node_buffer;
  dict.cost_buffer = cost_buffer;
  dict.valid_buffer = valid_buffer;
  for (size_t i = 0; i < dict.size; i++) {
    dict.valid_buffer[i] = false;
  }
  return dict;
}

bool dict_set(struct path_dict * dict, struct path_node * key, uint32_t cost) {
  for (size_t i = 0; i < dict->size; i++) {
    if (dict->valid_buffer[i]) {
      if (node_equal(*(dict->node_buffer[i]), *key)) {
	dict->cost_buffer[i] = cost;
	return true;
      }
    }
  }
  for (size_t i = 0; i < dict->size; i++) {
    if (!dict->valid_buffer[i]) {
      dict->node_buffer[i] = key;
      dict->cost_buffer[i] = cost;
      dict->valid_buffer[i] = true;
      return true;
    }
  }
  return false;
}

bool dict_get(struct path_dict * dict, struct path_node * key, uint32_t * value) {
  for (size_t i = 0; i < dict->size; i++) {
    if (dict->valid_buffer[i]) {
      if (node_equal(*(dict->node_buffer[i]), *key)) {
	*value = dict->cost_buffer[i];
	return true;
      }
    }
  }
  return false;
}
