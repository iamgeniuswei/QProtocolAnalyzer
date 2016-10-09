#include "packet-frame.h"
#include "define.h"
#include "time_fmt.h"
#include "proto.h"
#include "tvbuff.h"
#include "packet_info.h"
#include "packet.h"
#include <QDebug>
static int proto_frame = -1;
static int proto_pkt_comment = -1;
static int hf_frame_arrival_time = -1;
static int hf_frame_shift_offset = -1;
static int hf_frame_arrival_time_epoch = -1;
static int hf_frame_time_delta = -1;
static int hf_frame_time_delta_displayed = -1;
static int hf_frame_time_relative = -1;
static int hf_frame_time_reference = -1;
static int hf_frame_number = -1;
static int hf_frame_len = -1;
static int hf_frame_capture_len = -1;
static int hf_frame_p2p_dir = -1;
static int hf_frame_file_off = -1;
static int hf_frame_md5_hash = -1;
static int hf_frame_marked = -1;
static int hf_frame_ignored = -1;
static int hf_link_number = -1;
static int hf_frame_protocols = -1;
static int hf_frame_color_filter_name = -1;
static int hf_frame_color_filter_text = -1;
static int hf_frame_interface_id = -1;
static int hf_frame_pack_flags = -1;
static int hf_frame_pack_direction = -1;
static int hf_frame_pack_reception_type = -1;
static int hf_frame_pack_fcs_length = -1;
static int hf_frame_pack_reserved = -1;
static int hf_frame_pack_crc_error = -1;
static int hf_frame_pack_wrong_packet_too_long_error = -1;
static int hf_frame_pack_wrong_packet_too_short_error = -1;
static int hf_frame_pack_wrong_inter_frame_gap_error = -1;
static int hf_frame_pack_unaligned_frame_error = -1;
static int hf_frame_pack_start_frame_delimiter_error = -1;
static int hf_frame_pack_preamble_error = -1;
static int hf_frame_pack_symbol_error = -1;
static int hf_frame_wtap_encap = -1;
static int hf_comments_text = -1;

static gint ett_frame = -1;
static gint ett_flags = -1;
static gint ett_comments = -1;

static expert_field ei_comments_text = EI_INIT;
static expert_field ei_arrive_time_out_of_range = EI_INIT;
static expert_field ei_incomplete = EI_INIT;


#define PACKET_WORD_DIRECTION_MASK                        0x00000003
#define PACKET_WORD_RECEPTION_TYPE_MASK                   0x0000001C
#define PACKET_WORD_FCS_LENGTH_MASK                       0x000001E0
#define PACKET_WORD_RESERVED_MASK                         0x0000FE00
#define PACKET_WORD_CRC_ERR_MASK                          0x01000000
#define PACKET_WORD_PACKET_TOO_LONG_ERR_MASK              0x02000000
#define PACKET_WORD_PACKET_TOO_SHORT_ERR_MASK             0x04000000
#define PACKET_WORD_WRONG_INTER_FRAME_GAP_ERR_MASK        0x08000000
#define PACKET_WORD_UNALIGNED_FRAME_ERR_MASK              0x10000000
#define PACKET_WORD_START_FRAME_DELIMITER_ERR_MASK        0x20000000
#define PACKET_WORD_PREAMBLE_ERR_MASK                     0x40000000
#define PACKET_WORD_SYMBOL_ERR_MASK                       0x80000000


#define array_length(x)	(sizeof x / sizeof x[0])

static int dissect_frame(tvbuff_t *tvb, \
                         packet_info *pinfo,\
                         proto_tree *parent_tree,\
                         void *data)
{
    qDebug() << "dissect_frame() is working...";
}

void proto_register_frame()
{
    static hf_register_info hf[] = {

        {
            &hf_frame_arrival_time,
            {
                "Arrival Time",
                "frame.time",
                FT_ABSOLUTE_TIME,\
                ABSOLUTE_TIME_LOCAL,\
                NULL,\
                0x0,
                "Absolute time when this frame was captured",\
                HFILL
            }
        },

        {
            &hf_frame_shift_offset,
            {
                "Time shift for this packet",\
                "frame.offset_shift",\
                FT_RELATIVE_TIME,\
                BASE_NONE,
                NULL,
                0x0,\
                "Timee shift applied to this packet",\
                HFILL
            }
        },

        {
            &hf_frame_arrival_time_epoch,
            {
                "Epoch Time",
                "frame.time_epoch",\
                FT_RELATIVE_TIME,\
                BASE_NONE,\
                NULL,\
                0x0,\
                "Epoch time when this frame was captured",
                HFILL
            }
        },

        {
            &hf_frame_time_delta,\
            {
                "Time delta from previous captured frame",
                "frame.time_delta",
                FT_RELATIVE_TIME,
                BASE_NONE,
                NULL,
                0x0,
                NULL,
                HFILL
            }
        },

        {
            &hf_frame_time_delta_displayed,
            {
                "Time delta from previous displayed frame",
                "frame.time_delta_displayed",
                FT_RELATIVE_TIME,
                BASE_NONE,
                NULL,
                0x0,
                NULL,
                HFILL
            }
        },

        {
            &hf_frame_time_relative,
                      { "Time since reference or first frame", "frame.time_relative",
                        FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
                        "Time relative to time reference or first frame", HFILL }
        },

        {
            &hf_frame_time_reference,
                      { "This is a Time Reference frame", "frame.ref_time",
                        FT_NONE, BASE_NONE, NULL, 0x0,
                        "This frame is a Time Reference frame", HFILL }
        },

        {
            &hf_frame_number,
                      { "Frame Number", "frame.number",
                        FT_UINT32, BASE_DEC, NULL, 0x0,
                        NULL, HFILL }
        },

        {
            &hf_frame_len,
                      { "Frame length on the wire", "frame.len",
                        FT_UINT32, BASE_DEC, NULL, 0x0,
                        NULL, HFILL }
        },

        {
            &hf_frame_capture_len,
                      { "Frame length stored into the capture file", "frame.cap_len",
                        FT_UINT32, BASE_DEC, NULL, 0x0,
                        NULL, HFILL }
        },

        {
            &hf_frame_md5_hash,
                      { "Frame MD5 Hash", "frame.md5_hash",
                        FT_STRING, BASE_NONE, NULL, 0x0,
                        NULL, HFILL }
        },

//        {
//            &hf_frame_p2p_dir,
//                      { "Point-to-Point Direction", "frame.p2p_dir",
//                        FT_INT8, BASE_DEC, VALS(p2p_dirs), 0x0,
//                        NULL, HFILL }
//        },

        {
            &hf_link_number,
                      { "Link Number", "frame.link_nr",
                        FT_UINT16, BASE_DEC, NULL, 0x0,
                        NULL, HFILL }
        },

        {
            &hf_frame_file_off,
                      { "File Offset", "frame.file_off",
                        FT_INT64, BASE_DEC, NULL, 0x0,
                        NULL, HFILL }
        },

        {
            &hf_frame_marked,
                      { "Frame is marked", "frame.marked",
                        FT_BOOLEAN, BASE_NONE, NULL, 0x0,
                        "Frame is marked in the GUI", HFILL }
        },

        {
            &hf_frame_ignored,
                      { "Frame is ignored", "frame.ignored",
                        FT_BOOLEAN, BASE_NONE, NULL, 0x0,
                        "Frame is ignored by the dissectors", HFILL }
        },

        {
            &hf_frame_protocols,
                      { "Protocols in frame", "frame.protocols",
                        FT_STRING, BASE_NONE, NULL, 0x0,
                        "Protocols carried by this frame", HFILL }
        },

        {
            &hf_frame_color_filter_name,
                      { "Coloring Rule Name", "frame.coloring_rule.name",
                        FT_STRING, BASE_NONE, NULL, 0x0,
                        "The frame matched the coloring rule with this name", HFILL }
        },

        {
            &hf_frame_color_filter_text,
                      { "Coloring Rule String", "frame.coloring_rule.string",
                        FT_STRING, BASE_NONE, NULL, 0x0,
                        "The frame matched this coloring rule string", HFILL }
        },

        {
            &hf_frame_interface_id,
                      { "Interface id", "frame.interface_id",
                        FT_UINT32, BASE_DEC, NULL, 0x0,
                        NULL, HFILL }
        },

        {
            &hf_frame_pack_flags,
                      { "Packet flags", "frame.packet_flags",
                        FT_UINT32, BASE_HEX, NULL, 0x0,
                        NULL, HFILL }
        },

//        {
//            &hf_frame_pack_direction,
//                      { "Direction", "frame.packet_flags_direction",
//                        FT_UINT32, BASE_HEX, VALS(packet_word_directions), PACKET_WORD_DIRECTION_MASK,
//                        NULL, HFILL }
//        },

//        {
//            &hf_frame_pack_reception_type,
//                      { "Reception type", "frame.packet_flags_reception_type",
//                        FT_UINT32, BASE_DEC, VALS(packet_word_reception_types), PACKET_WORD_RECEPTION_TYPE_MASK,
//                        NULL, HFILL }
//        },

        {
            &hf_frame_pack_fcs_length,
                      { "FCS length", "frame.packet_flags_fcs_length",
                        FT_UINT32, BASE_DEC, NULL, PACKET_WORD_FCS_LENGTH_MASK,
                        NULL, HFILL }
        },

        {
            &hf_frame_pack_reserved,
                      { "Reserved", "frame.packet_flags_reserved",
                        FT_UINT32, BASE_DEC, NULL, PACKET_WORD_RESERVED_MASK,
                        NULL, HFILL }
        },

//        {
//            &hf_frame_pack_crc_error,
//                  { "CRC error", "frame.packet_flags_crc_error",
//                    FT_BOOLEAN, 32, TFS(&tfs_set_notset), PACKET_WORD_CRC_ERR_MASK,
//                    NULL, HFILL }
//        },

//        { &hf_frame_pack_wrong_packet_too_long_error,
//          { "Packet too long error", "frame.packet_flags_packet_too_error",
//            FT_BOOLEAN, 32, TFS(&tfs_set_notset), PACKET_WORD_PACKET_TOO_LONG_ERR_MASK,
//            NULL, HFILL }},

//        { &hf_frame_pack_wrong_packet_too_short_error,
//          { "Packet too short error", "frame.packet_flags_packet_too_short_error",
//            FT_BOOLEAN, 32, TFS(&tfs_set_notset), PACKET_WORD_PACKET_TOO_SHORT_ERR_MASK,
//            NULL, HFILL }},

//        { &hf_frame_pack_wrong_inter_frame_gap_error,
//          { "Wrong interframe gap error", "frame.packet_flags_wrong_inter_frame_gap_error",
//            FT_BOOLEAN, 32, TFS(&tfs_set_notset), PACKET_WORD_WRONG_INTER_FRAME_GAP_ERR_MASK,
//            NULL, HFILL }},

//        { &hf_frame_pack_unaligned_frame_error,
//          { "Unaligned frame error", "frame.packet_flags_unaligned_frame_error",
//            FT_BOOLEAN, 32, TFS(&tfs_set_notset), PACKET_WORD_UNALIGNED_FRAME_ERR_MASK,
//            NULL, HFILL }},

//        { &hf_frame_pack_start_frame_delimiter_error,
//          { "Start frame delimiter error", "frame.packet_flags_start_frame_delimiter_error",
//            FT_BOOLEAN, 32, TFS(&tfs_set_notset), PACKET_WORD_START_FRAME_DELIMITER_ERR_MASK,
//            NULL, HFILL }},

//        { &hf_frame_pack_preamble_error,
//          { "Preamble error", "frame.packet_flags_preamble_error",
//            FT_BOOLEAN, 32, TFS(&tfs_set_notset), PACKET_WORD_PREAMBLE_ERR_MASK,
//            NULL, HFILL }},

//        { &hf_frame_pack_symbol_error,
//          { "Symbol error", "frame.packet_flags_symbol_error",
//            FT_BOOLEAN, 32, TFS(&tfs_set_notset), PACKET_WORD_SYMBOL_ERR_MASK,
//            NULL, HFILL }},

        { &hf_comments_text,
          { "Comment", "frame.comment",
            FT_STRING, BASE_NONE, NULL, 0x0,
            NULL, HFILL }}
    };

    static hf_register_info hf_encap =
    {
        &hf_frame_wtap_encap,
        {
            "Encapsulation type", "frame.encap_type",
                        FT_INT16, BASE_DEC, NULL, 0x0,
                        NULL, HFILL
        }
    };

    static gint *ett[] = {
        &ett_frame,\
        &ett_flags,\
        &ett_comments
    };

    static ei_register_info ei[] =
    {
        {
            &ei_comments_text,
            {
                "frame.comment.expert",
                PI_COMMENTS_GROUP,\
                PI_COMMENT,\
                "Formatted comment",\
                EXPFILL
            }
        },

        {
            &ei_arrive_time_out_of_range,
            {
                "frame.time_invalid",
                PI_SEQUENCE,\
                PI_NOTE,\
                "Arrival Time: Fractional second out of range (0-1000000000)",
                EXPFILL
            }
        },

        {
            &ei_incomplete,
            {
                "frame.incomplete",
                PI_UNDECODED,
                PI_WARN,
                "Incomplete dissector",
                EXPFILL
            }
        }
    };

    proto_frame = proto_register_protocol("Frame",\
                                          "Frame",\
                                          "frame");
    proto_pkt_comment = proto_register_protocol("Packet comments",\
                                                "Pkt_Comment",\
                                                "pkt_comment");

    proto_register_field_array(proto_frame, hf, array_length(hf));
    proto_register_field_array(proto_frame, &hf_encap, 1);
    proto_register_subtree_array(ett, array_length(ett));
    new_register_dissector("frame", dissect_frame, proto_frame);


}

