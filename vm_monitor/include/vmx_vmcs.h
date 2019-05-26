/*
 * Copyright (c) 2019 Jie Zheng
 */

#ifndef _VMX_VMCS_H
#define _VMX_VMCS_H
#include <lib64/include/type.h>

// VMCS HOST STATE FIELDS: see Intel SDM Volume 3, Appendix B.1.3,
// Appendix B.2.4, Appendix B.3.4 and Appendix 4.4.4

#define HOST_ES_SELECTOR 0x00000C00
#define HOST_CS_SELECTOR 0x00000C02
#define HOST_SS_SELECTOR 0x00000C04
#define HOST_DS_SELECTOR 0x00000C06
#define HOST_FS_SELECTOR 0x00000C08
#define HOST_GS_SELECTOR 0x00000C0A
#define HOST_TR_SELECTOR 0x00000C0C
#define HOST_IA32_PAT_FULL 0x00002C00
#define HOST_IA32_PAT_HIGH 0x00002C00
#define HOST_IA32_EFER_FULL 0x00002C02
#define HOST_IA32_EFER_HIGH 0x00002C03
#define HOST_IA32_PERF_GLOBAL_CTRL_FULL 0x00002C04
#define HOST_IA32_PERF_GLOBAL_CTRL_HIGH 0x00002C05
#define HOST_IA32_SYSENTER_CS 0x00004C00
#define HOST_CR0 0x00006C00
#define HOST_CR3 0x00006C02
#define HOST_CR4 0x00006C04
#define HOST_FS_BASE 0x00006C06
#define HOST_GS_BASE 0x00006C08
#define HOST_TR_BASE 0x00006C0A
#define HOST_GDTR_BASE 0x00006C08
#define HOST_IDTR_BASE 0x00006C0E
#define HOST_IA32_SYSENTER_ESP 0x00006C10
#define HOST_IA32_SYSENTER_EIP 0x00006C12
#define HOST_RSP 0x00006C14
#define HOST_RIP 0x00006C16

// Appendix B.1.2
#define GUEST_ES_SELECTOR 0x00000800
#define GUEST_CS_SELECTOR 0x00000802
#define GUEST_SS_SELECTOR 0x00000804
#define GUEST_DS_SELECTOR 0x00000806
#define GUEST_FS_SELECTOR 0x00000808
#define GUEST_GS_SELECTOR 0x0000080A
#define GUEST_LDTR_SELECTOR 0x0000080C
#define GUEST_TR_SELECTOR 0x0000080E
#define GUEST_INTERRUPT_STATUS 0x00000810
#define GUEST_PML_INDEX 0x00000812

// Appendix B.4.3
#define GUEST_CR0 0x00006800
#define GUEST_CR3 0x00006802
#define GUEST_CR4 0x00006804
#define GUEST_ES_BASE 0x00006806
#define GUEST_CS_BASE 0x00006808
#define GUEST_SS_BASE 0x0000680A
#define GUEST_DS_BASE 0x0000680C
#define GUEST_FS_BASE 0x0000680E
#define GUEST_GS_BASE 0x00006810
#define GUEST_LDTR_BASE 0x00006812
#define GUEST_TR_BASE 0x00006814
#define GUEST_GDTR_BASE 0x00006816
#define GUEST_IDTR_BASE 0x00006818
#define GUEST_DR7 0x0000681A
#define GUEST_RSP 0x0000681C
#define GUEST_RIP 0x0000681E
#define GUEST_RFLAG 0x00006820
#define GUEST_PENDING_DEBUG_EXCEPTION 0x00006822
#define GUEST_IA32_SYSENTER_ESP 0x00006824
#define GUEST_IA32_SYSENTER_EIP 0x00006826

// Appendix B.3.3
#define GUEST_ES_LIMIT 0x00004800
#define GUEST_CS_LIMIT 0x00004802
#define GUEST_SS_LIMIT 0x00004804
#define GUEST_DS_LIMIT 0x00004806
#define GUEST_FS_LIMIT 0x00004808
#define GUEST_GS_LIMIT 0x0000480A
#define GUEST_LDTR_LIMIT 0x0000480C
#define GUEST_TR_LIMIT 0x0000480E
#define GUEST_GDTR_LIMIT 0x00004810
#define GUEST_IDTR_LIMIT 0x00004812
#define GUEST_ES_ACCESS_RIGHT 0x00004814
#define GUEST_CS_ACCESS_RIGHT 0x00004816
#define GUEST_SS_ACCESS_RIGHT 0x00004818
#define GUEST_DS_ACCESS_RIGHT 0x0000481A
#define GUEST_FS_ACCESS_RIGHT 0x0000481C
#define GUEST_GS_ACCESS_RIGHT 0x0000481E
#define GUEST_LDTR_ACCESS_RIGHT 0x00004820
#define GUEST_TR_ACCESS_RIGHT 0x00004822
#define GUEST_INTERRUPTIBILITY_STATE 0x00004824
#define GUEST_ACTIVITY_STATE 0x00004826 // See 24.4.2
#define GUEST_SMBASE 0x00004828
#define GUEST_IA32_SYSENTER_CS 0x0000482A
#define GUEST_VMX_PREEMPTION_TIMER 0x0000482E
// Appendix b.2.3
#define GUEST_VMCS_LINK_POINTER_LOW 0x00002800
#define GUEST_VMCS_LINK_POINTER_HIGH 0x00002801


//Appendix B.3.1
#define CTLS_PIN_BASED_VM_EXECUTION 0x00004000
struct vmcs_region {
    uint64_t guest_region;
    uint64_t io_bitmap_region0;
    uint64_t io_bitmap_region1;
    uint64_t msr_bitmap_region;
    uint64_t virtual_apic_region;
};

#define HOST_STACK_NR_PAGES 0x8 // 32K is supposed to be enough

struct vmcs_blob {
    struct vmcs_region regions;
    uint64_t host_stack;
};

int
pre_initialize_vmcs(struct vmcs_blob * vm);


int
initialize_vmcs(struct vmcs_blob * vm);

#endif
