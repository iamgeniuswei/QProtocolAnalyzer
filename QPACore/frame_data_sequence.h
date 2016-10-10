#ifndef FRAME_DATA_SEQUENCE_H
#define FRAME_DATA_SEQUENCE_H
#include <glib.h>
#include "frame_data.h"
#include <memory>

class frame_data_sequence
{
public:
    frame_data_sequence();
    ~frame_data_sequence();

private:
    quint32 count = 0;
    std::shared_ptr<void> ptree_root;
};




/*
 * We store the frame_data structures in a radix tree, with 1024
 * elements per level.  The leaf nodes are arrays of 1024 frame_data
 * structures; the nodes above them are arrays of 1024 pointers to
 * the nodes below them.  The capture_file structure has a pointer
 * to the root node.
 *
 * As frame numbers are 32 bits, and as 1024 is 2^10, that gives us
 * up to 4 levels of tree.
 */
#define LOG2_NODES_PER_LEVEL    10
#define NODES_PER_LEVEL         (1<<LOG2_NODES_PER_LEVEL)

/*
 * For a given frame number, calculate the indices into a level 3
 * node, a level 2 node, a level 1 node, and a leaf node.
 */
#define LEVEL_3_INDEX(framenum) \
        ((framenum) >> (3*LOG2_NODES_PER_LEVEL))
#define LEVEL_2_INDEX(framenum) \
        (((framenum) >> (2*LOG2_NODES_PER_LEVEL)) & (NODES_PER_LEVEL - 1))
#define LEVEL_1_INDEX(framenum) \
        (((framenum) >> (1*LOG2_NODES_PER_LEVEL)) & (NODES_PER_LEVEL - 1))
#define LEAF_INDEX(framenum) \
        (((framenum) >> (0*LOG2_NODES_PER_LEVEL)) & (NODES_PER_LEVEL - 1))


//typedef struct _frame_data_sequence {
//  guint32      count;           /* Total number of frames */
//  void        *ptree_root;      /* Pointer to the root node */
//}frame_data_sequence;

extern frame_data *frame_data_sequence_add(frame_data_sequence *fds,
    frame_data *fdata);
#endif // FRAME_DATA_SEQUENCE_H
