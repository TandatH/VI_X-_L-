#define board d501
#include <tv_boards.c>
#include <tv_lcd.c>

void main()
{
      system_init();
      lcd_setup();
      lcd_goto(0,0);
      lcd_data("DAI HOC SPKT TPHCM");
      lcd_goto(0,1);
      lcd_data("KHOA DIEN-DIEN TU");
      lcd_goto(0,2);
      lcd_data("BO MON DTCN-YS");
      lcd_goto(0,3);
      lcd_data("TTVXL MOUDLE LCD");
      while(true)
      { 
      }
}

