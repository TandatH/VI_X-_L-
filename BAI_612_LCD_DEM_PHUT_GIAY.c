#define board d501
#include <tv_boards.c>
#include <tv_lcd.c>
unsigned int8 giay=0,phut=0,bdn=0;


void main()
{
      system_init();
      lcd_setup();
      setup_timer_1(T1_INTERNAL| T1_DIV_BY_8);
      set_timer1(3036);
      enable_interrupts(INT_TIMER1);
      enable_interrupts(GLOBAL);
      while(true)
      {
      if(bdn>=10) 
      {
            bdn=bdn-10;
            giay++;
            giay%=60;
            if(giay>=59)
            {
               phut++;
               phut%=60;  
            }
            
      }
       lcd_goto(5,2);
       printf(lcd_data,"giay: %02u ",giay);
       lcd_goto(5,3);
       printf(lcd_data,"phut: %02u ",phut);
       }
       
}

#INT_TIMER1
void ngat_timer1() 
{
      set_timer1(3036);
      bdn++; //disable_interrupts(INT_TIMER1);
}
