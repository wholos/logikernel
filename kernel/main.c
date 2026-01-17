volatile unsigned char *vimem=(volatile unsigned char*)0xb8000;
#define VGA_WIDTH 80
static unsigned int row=0;
static unsigned int col=0;
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
    while(*str){
        if(*str=='\n'){
            col=0;
            row++;
        }
        else {
            unsigned int i=(row*VGA_WIDTH+col)*2;
            vimem[i]=*str;
            vimem[i+1]=0x07;
            col++;
        }
        str++;
    }
}
int kernelm(){
    clearsc();
    echo("Copyright(c) Holos(Nikita Shyshatskyi)\n");
    echo("This is a learning system. With love, Logi.\n");
    for(;;);
}
