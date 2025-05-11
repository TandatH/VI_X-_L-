#define board d501
#include<tv_boards.c>
unsigned int8 T0=240;
void d7seg_xoa0VN(unsigned int16 d)
{
      unsigned int8 n=0;
      do
      {
            d7seg.led[n]= m7d[d%10];
            d/=10;
            n++;
      }
      while(d!=0);
      for(;n<4;n++) d7seg.led[n]= 0xff;
         d7seg_display();
}

void main()
{
      system_init();
      setup_timer_0 (T0_EXT_H_TO_L|t0_div_1|T0_8_BIT);
      set_timer0(240); 
      while(true)
      {
         T0= get_timer0();
         if(T0>=255) set_timer0(240);
         d7seg_xoa0VN(T0);
         
      }
}
