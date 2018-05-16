#include "path_node_dict.h"

struct path_node_dict new_node_dict(size_t size, struct path_node * key_buffer, struct path_node * val_buffer, bool * valid_buffer) {
  struct path_node_dict dict;
  dict.size = size;
  dict.key_buffer = key_buffer;
  dict.val_buffer = val_buffer;
  dict.valid_buffer = valid_buffer;
  for (size_t i = 0; i < dict.size; i++) {
    dict.valid_buffer[i] = false;
  }
  return dict;
}

bool node_dict_set(struct path_node_dict * dict, struct path_node key, struct path_node val) {
  for (size_t i = 0; i < dict->size; i++) {
    if (dict->valid_buffer[i]) {
      if (node_equal(dict->key_buffer[i], key)) {
	dict->val_buffer[i] = val;
	return true;
      }
    }
  }
  for (size_t i = 0; i < dict->size; i++) {
    if (!dict->valid_buffer[i]) {
      dict->key_buffer[i] = key;
      dict->val_buffer[i] = val;
      dict->valid_buffer[i] = true;
      return true;
    }
  }
  return false;
}

bool node_dict_get(struct path_node_dict * dict, struct path_node key, struct path_node * val) {
  for (size_t i = 0; i < dict->size; i++) {
    if (dict->valid_buffer[i]) {
      if (node_equal(dict->key_buffer[i], key)) {
	*val = dict->val_buffer[i];
	return true;
      }
    }
  }
  return false;
}
