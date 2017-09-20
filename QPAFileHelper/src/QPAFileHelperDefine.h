/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QPAFileHelperDefine.h
 * Author: lenovo
 *
 * Created on 2017年9月19日, 上午8:29
 */

#ifndef QPAFILEHELPERDEFINE_H
#define QPAFILEHELPERDEFINE_H
/*
 * For registering file types that we can open.
 *
 * Each file type has an open routine and an optional list of extensions
 * the file might have.
 *
 * The open routine should return:
 *
 *      WTAP_OPEN_ERROR on an I/O error;
 *
 *      WTAP_OPEN_MINE if the file it's reading is one of the types
 *      it handles;
 *
 *      WTAP_OPEN_NOT_MINE if the file it's reading isn't one of the
 *      types it handles.
 *
 * If the routine handles this type of file, it should set the "file_type"
 * field in the "struct wtap" to the type of the file.
 *
 * Note that the routine does not have to free the private data pointer on
 * error. The caller takes care of that by calling wtap_close on error.
 * (See https://bugs.wireshark.org/bugzilla/show_bug.cgi?id=8518)
 *
 * However, the caller does have to free the private data pointer when
 * returning WTAP_OPEN_NOT_MINE, since the next file type will be called
 * and will likely just overwrite the pointer.
 */
typedef enum {
    WTAP_OPEN_NOT_MINE = 0,
    WTAP_OPEN_MINE = 1,
    WTAP_OPEN_ERROR = -1
} wtap_open_return_val;

typedef enum {
    OPEN_INFO_MAGIC = 0,
    OPEN_INFO_HEURISTIC = 1
} wtap_open_type;


//PCAP文件类型定义 
#define	PCAP_MAGIC			0xa1b2c3d4
#define	PCAP_SWAPPED_MAGIC		0xd4c3b2a1
#define	PCAP_MODIFIED_MAGIC		0xa1b2cd34
#define	PCAP_SWAPPED_MODIFIED_MAGIC	0x34cdb2a1
#define	PCAP_NSEC_MAGIC			0xa1b23c4d
#define	PCAP_SWAPPED_NSEC_MAGIC		0x4d3cb2a1

/* "libpcap" file header (minus magic number). */
struct pcap_hdr {
    unsigned short	version_major;	/* major version number */
    unsigned short	version_minor;	/* minor version number */
    int	thiszone;	/* GMT to local correction */
    unsigned int	sigfigs;	/* accuracy of timestamps */
    unsigned int	snaplen;	/* max length of captured packets, in octets */
    unsigned int	network;	/* data link type */
};

/* "libpcap" record header. */
struct pcaprec_hdr {
    unsigned int	ts_sec;		/* timestamp seconds */
    unsigned int	ts_usec;	/* timestamp microseconds (nsecs for PCAP_NSEC_MAGIC) */
    unsigned int	incl_len;	/* number of octets of packet saved in file */
    unsigned int	orig_len;	/* actual length of packet */
};




#endif /* QPAFILEHELPERDEFINE_H */

