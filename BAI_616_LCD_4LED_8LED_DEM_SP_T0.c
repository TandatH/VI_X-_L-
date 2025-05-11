//#define board d501
#include<tv_boards.c>
#include<tv_lcd.c>
unsigned int8 T0;
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
void hienthi()
{
   s7seg.led[2]=m7d[T0/100%10];
   s7seg.led[1]=m7d[T0/10%10];
   s7seg.led[0]=m7d[T0%10];
   s7seg_display();
   lcd_goto(5,0);
   printf(lcd_data,"counter: %02u ",T0);


}
void main()
{
      system_init();
      lcd_setup();
      setup_timer_0 (t0_ext_l_to_h |t0_div_1);
      set_timer0(0);// Khi test SV thay d?i giá tr? d?t cho nhanh
      while(true)
      {
       
         T0= get_timer0();
         if(T0>100) set_timer0(1);
         d7seg_xoa0VN(T0);
         hienthi();

      }
}
