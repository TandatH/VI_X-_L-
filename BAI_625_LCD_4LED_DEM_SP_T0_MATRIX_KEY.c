//#define board d501
#include <tv_boards.c>
#include <tv_lcd.c>
#include <tv_key4x4.c>
unsigned int8 limit=01, product = 0, T0=0,m,i,key;
unsigned int1 tt=0;

void kt_nutnhan()
{
    if (key4x4_read() == OK) {
        key = key4x4.key;

        if (key >= 0 && key <= 9) {
            limit = (limit % 10) * 10 + key;  // D?ch s? và thêm s? m?i
            if (limit > 99) limit = 99;  // Gi?i h?n không du?c vu?t quá 99
        }

        if (key == 0x0C) {  // N?u nh?n phím C
            limit = 1;product=0;  // Ð?t l?i gi?i h?n v? 01
        }
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
            set_timer0(0);
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
         //mtp();
         ktra_clr();
         hienthi();
         //delay_ms(50);
      }
      }
      
}
