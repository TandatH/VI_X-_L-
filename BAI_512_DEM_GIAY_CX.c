
#include <tv_boards.c>
unsigned int8 giay=0,bdn=0;

#INT_TIMER1
void ngat_timer1() 
{
      set_timer1(3036);
      bdn++; disable_interrupts(INT_TIMER1);
}
void main()
{
      system_init();
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
      }
            s7seg.led[4] = m7d[giay/10%10]; 
            s7seg.led[3] = m7d[giay%10]; 
            s7seg_display(); 
       }
}


