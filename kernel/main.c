volatile unsigned char *vimem=(volatile unsigned char*)0xb8000;
__attribute__((section(".multiboot"))) 
unsigned int multiboot_header[] = {
    0x1BADB002,
    0x00,
    -(0x1BADB002)
};
int clearsc(){
    unsigned int j=0;
    while(j<80*25*2){
        vimem[j]=' ';
        vimem[j+1]=0x07;
        j+=2;
    }
    j=0;
}
int echo(const char *str){
    unsigned int i=0,j=0;
    while(str[j]!='\0'){
        vimem[i]=str[j];
        vimem[i+1]=0x07;
        ++j;
        i+=2;
    }
}
int kernelm(){
    clearsc();
    echo("hi");
    for(;;);
}
