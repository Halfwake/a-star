#ifndef _TEAM11_PATH_FIND
#define _TEAM11_PATH_FIND

#include <stdint.h>

#include "path_node.h"
#include "path_graph.h"
#include "path_set.h"
#include "path_dict.h"
#include "path_node_dict.h"
#include "path_array.h"

void path_find(struct path_graph * graph, struct path_node start, struct path_node goal, struct path_array * return_array);

#endif
