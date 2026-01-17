ENTRY(kernelm)
SECTIONS {
    . = 0x100000;
    .text : {
        *(.multiboot)
        *(.text)
    }
    .data : {
        *(.data)
    }
    .bss (NOLOAD) : {
        __bss_start = .;
        *(.bss)
        __bss_end = .;
    }
}
