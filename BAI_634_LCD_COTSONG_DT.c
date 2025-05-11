#define  board d501
#include<tv_boards.c>
#include<tv_lcd.c> 
const unsigned int8 cotsong[]={0,0,0,0,0,0,0,0x80,
                               0,0,0,0,0,0,0x40,0xc0,
                               0,0,0,0,0,0x20,0x60,0xe0,
                               0,0,0,0,0x10,0x34,0x70,0xf0,
                               0,0,0,0x08,0x18,0x38,0x78,0xf8,
                               0,0,4,0x0c,0x1c,0x3c,0x7c,0xfc,
                               0,2,6,0x0e,0x1e,0x3e,0x7e,0xfe,
                               1,3,7,0x0f,0x1f,0x3f,0x7f,0xff
                              };
unsigned int8 n;
void main()
{
      system_init();
      lcd_setup();
      lcd_command(0x40);
      for(n=0;n<64;n++)
      {
         
         lcd_data(cotsong[n]);
      }
      while(true)
      {
       for(n=0;n<8;n++) 
       { 
            lcd_goto(19,0);
            lcd_data(n);
            delay_ms(200);
       }
      }
}
