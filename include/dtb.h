#ifndef DTB_H
#define DTB_H

#include "my_stdint.h"
#include "kernel.h"

#define FDT_MAGIC ((unsigned int) 0xd00dfeed)

#define FDT_BEGIN_NODE     0x1
#define FDT_END_NODE       0x2
#define FDT_PROP           0x3
#define FDT_NOP            0x4
#define FDT_END            0x9

typedef struct _fdt_header {
    uint32_t magic; // magic number should be FDT_MAGIC
    uint32_t totalsize; // total size of dt block
    uint32_t off_dt_struct; // offset to string
    uint32_t off_dt_strings; // offset to structure
    uint32_t off_mem_rsvmap; // offset to memory reserve map
    uint32_t version; // format version
    uint32_t last_comp_version; // last compatible version
    uint32_t boot_cpuid_phys; // which cpu we are boot on
    uint32_t size_dt_strings; // size of the strings block
    uint32_t size_dt_struct; // size of the structure block
} fdt_header;

typedef struct _fdt_node_header {
    uint32_t tag;
    char name[0];
} fdt_node_header;

typedef struct _fdt_prop {
    uint32_t len;
    uint32_t nameoff;
} fdt_prop;

extern fdt_header *dtb_address;

void fdt_init();

void fdt_traverse(void (*callback)(fdt_prop *, char *, char *));
// void fdt_traverse();
void initramfs_callback(fdt_prop *prop, char *node_name, char *property_name);


#endif