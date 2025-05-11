#define board d501
#include <tv_boards.c>
#include <tv_lcd.c>
unsigned int8 limit = 01, product = 0, T0=0,m;
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
         if(limit<=01) limit =01;
         else limit--;
      }
      if(inputcd(clr)==0) 
      {
         tt=~tt;
         
      }
      
}
void ktra_clr()
{
   if(tt==0) product=T0;
   if(tt==1) 
   {
      limit=01;
      product=00;
   }
}
void hienthi()
{
         d7seg.led[3] = m7d[limit/10%10];
         d7seg.led[2] = m7d[limit%10]-128;
         d7seg.led[1] = m7d[product/10%10];
         d7seg.led[0] = m7d[product%10];
         d7seg_display();                                                                    //CAN DUOC CAI THIEN THEM NUT CLR
         for(m=0;m<50;m++)s7seg_display();
         
         lcd_goto(5,1);
         printf(lcd_data,"limit: %02u ",limit);
         lcd_goto(5,0);
         printf(lcd_data,"product: %02u ",product);
         s7seg.led[1] = m7d[product/10%10]; 
         s7seg.led[0] = m7d[product%10];  
         s7seg.led[6] = m7d[limit%10]; 
         s7seg.led[7] = m7d[limit/10%10];
         s7seg_display(); 
         
}

void main()
{
      system_init();
      lcd_setup();
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
         
         if(tt==0) product=T0;
         if(tt==1) 
         {
            limit=01;
            product=00;
            product=T0;
            
         } 
      for(m=0;m<50;m++)
      {
         kt_nutnhan();
         ktra_clr();
         hienthi();
         //delay_ms(50);
      }
      }
      
}
