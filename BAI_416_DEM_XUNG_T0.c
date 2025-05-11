#define board d501
#include<tv_boards.c>
unsigned int16 T0=0,T0_TAM=10000;
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
      setup_timer_0 (t0_ext_l_to_h |t0_div_1);
      set_timer0(0); //Khi test SV thay d?i giá tr? d?t cho nhanh
      while(true)
      {
         T0= get_timer0();
         if(T0>10000) set_timer0(0);
         if(T0!=T0_TAM)
         {
         T0_TAM=T0;
         d7seg_xoa0VN(T0);
         }
      }
}
