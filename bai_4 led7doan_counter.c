#include <tv_boards.c>
unsigned int8 limit = 0, product =0, T0=0;
unsigned int1 tt=0;

void kt_nutnhan()
{
      if(inputcd(up)==0)
      {
         if(limit>=99) limit=99;
         else limit++;
      }
      if(inputcd(dw)==0)
      {
         if(limit<=0) limit =00;
         else limit--;
      }
      if(inputcd(inv)==0) tt=~tt;
}

void kt_inv()
{
     if(tt==0) set_timer0(product);
     else      set_timer0(limit-product);
}
void main()
{
      system_init();
      setup_timer_0(T0_ext_h_to_l|T0_div_1);
      set_timer0(0);
      while(true)
      {
         t0=get_timer0();
         if(T0>limit)
         {
            T0=1;
            set_timer0(1);
         }
         if(tt==0) product =T0;
         else      product = limit - T0;
         kt_nutnhan();
         kt_inv();
         d7seg.led[3] = m7d[limit/10%10];
         d7seg.led[2] = m7d[limit%10]-128;
         d7seg.led[1] = m7d[product/10%10];
         d7seg.led[0] = m7d[product%10];
         d7seg_display();
         delay_ms(50);
      }
      
}
