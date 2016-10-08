#include "frame_data_sequence.h"
#include <glib.h>
frame_data *frame_data_sequence_add(frame_data_sequence *fds, frame_data *fdata)
{
    frame_data *leaf;
    frame_data **level1;
    frame_data ***level2;
    frame_data ****level3;
    frame_data *node;
    /*
     * The current value of fds->count is the index value for the new frame,
     * because the index value for a frame is the frame number - 1, and
     * if we currently have fds->count frames, the the frame number of
     * the last frame in the collection is fds->count, so its index value
     * is fds->count - 1.
     */
    if(fds->count == 0)
    {
        leaf = (frame_data*)g_malloc((sizeof (*leaf)) * NODES_PER_LEVEL);
        node = &leaf[0];
        fds->ptree_root = leaf;
    }
    else if (fds->count < NODES_PER_LEVEL) {
        leaf = (frame_data*)fds->ptree_root;
        node = &leaf[fds->count];
    }
    else if (fds->count == NODES_PER_LEVEL) {
        /* It's a 1-level tree that will turn into a 2-level tree. */
        level1 = (frame_data **)g_malloc0((sizeof *level1)*NODES_PER_LEVEL);
        level1[0] = (frame_data *)fds->ptree_root;
        leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
        level1[1] = leaf;
        node = &leaf[0];
        fds->ptree_root = level1;
    }
    else if(fds->count < NODES_PER_LEVEL * NODES_PER_LEVEL)
    {
        /* It's a 2-level tree, and is going to stay that way for now. */
            level1 = (frame_data **)fds->ptree_root;
            leaf = level1[fds->count >> LOG2_NODES_PER_LEVEL];
            if (leaf == NULL) {
              leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
              level1[fds->count >> LOG2_NODES_PER_LEVEL] = leaf;
            }
            node = &leaf[LEAF_INDEX(fds->count)];
    }
    else if(fds->count == NODES_PER_LEVEL * NODES_PER_LEVEL)
    {
        /* It's a 2-level tree that will turn into a 3-level tree */
        level2 = (frame_data ***)g_malloc0((sizeof *level2)*NODES_PER_LEVEL);
        level2[0] = (frame_data **)fds->ptree_root;
        level1 = (frame_data **)g_malloc0((sizeof *level1)*NODES_PER_LEVEL);
        level2[1] = level1;
        leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
        level1[0] = leaf;
        node = &leaf[0];
        fds->ptree_root = level2;
    }
    else if(fds->count < NODES_PER_LEVEL * NODES_PER_LEVEL * NODES_PER_LEVEL)
    {
        /* It's a 3-level tree, and is going to stay that way for now. */
        level2 = (frame_data ***)fds->ptree_root;
        level1 = level2[fds->count >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)];
        if (level1 == NULL) {
          level1 = (frame_data **)g_malloc0((sizeof *level1)*NODES_PER_LEVEL);
          level2[fds->count >> (LOG2_NODES_PER_LEVEL+LOG2_NODES_PER_LEVEL)] = level1;
        }
        leaf = level1[LEVEL_1_INDEX(fds->count)];
        if (leaf == NULL) {
          leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
          level1[LEVEL_1_INDEX(fds->count)] = leaf;
        }
        node = &leaf[LEAF_INDEX(fds->count)];

    }
    else if(fds->count == NODES_PER_LEVEL * NODES_PER_LEVEL * NODES_PER_LEVEL)
    {
        /* It's a 3-level tree that will turn into a 4-level tree */
        level3 = (frame_data ****)g_malloc0((sizeof *level3)*NODES_PER_LEVEL);
        level3[0] = (frame_data ***)fds->ptree_root;
        level2 = (frame_data ***)g_malloc0((sizeof *level2)*NODES_PER_LEVEL);
        level3[1] = level2;
        level1 = (frame_data **)g_malloc0((sizeof *level1)*NODES_PER_LEVEL);
        level2[0] = level1;
        leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
        level1[0] = leaf;
        node = &leaf[0];
        fds->ptree_root = level3;
    }
    else
    {
        /* fds->count is 2^32-1 at most, and NODES_PER_LEVEL^4
               2^(LOG2_NODES_PER_LEVEL*4), and LOG2_NODES_PER_LEVEL is 10,
               so fds->count is always less < NODES_PER_LEVEL^4.

               XXX - we should fail if fds->count is 2^31-1, or should
               make the frame numbers 64-bit and just let users run
               themselves out of address space or swap space. :-) */
        /* It's a 4-level tree, and is going to stay that way forever. */
        level3 = (frame_data ****)fds->ptree_root;
        level2 = level3[LEVEL_3_INDEX(fds->count)];
        if (level2 == NULL) {
            level2 = (frame_data ***)g_malloc0((sizeof *level2)*NODES_PER_LEVEL);
            level3[LEVEL_3_INDEX(fds->count)] = level2;
        }
        level1 = level2[LEVEL_2_INDEX(fds->count)];
        if (level1 == NULL) {
            level1 = (frame_data **)g_malloc0((sizeof *level1)*NODES_PER_LEVEL);
            level2[LEVEL_2_INDEX(fds->count)] = level1;
        }
        leaf = level1[LEVEL_1_INDEX(fds->count)];
        if (leaf == NULL) {
            leaf = (frame_data *)g_malloc((sizeof *leaf)*NODES_PER_LEVEL);
            level1[LEVEL_1_INDEX(fds->count)] = leaf;
        }
        node = &leaf[LEAF_INDEX(fds->count)];
    }
    *node = *fdata;
    fds->count++;
    return node;
}

