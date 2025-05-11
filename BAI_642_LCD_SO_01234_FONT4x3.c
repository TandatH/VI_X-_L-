#DEFINE BOARD D501
#include<tv_boards.c>
#include<tv_lcd.c>
void main()
{
      system_init();
      lcd_setup();
      lcd_command(0x40);
      lcd_write_4x3_num(0,1); 
      lcd_write_4x3_num(1,4); 
      lcd_write_4x3_num(2,7); 
      lcd_write_4x3_num(3,10); 
      lcd_write_4x3_num(4,14); 
      while(true)
      { 
      }
}

