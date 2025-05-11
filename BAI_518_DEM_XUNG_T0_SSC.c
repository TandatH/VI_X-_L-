#include <tv_boards.c>
unsigned int1 tt=0;
unsigned int8 T0,ttc=0;

void nutnhan()
{
   if(inputcd(clr)==0)
    {
      ttc++;
      {
         if(ttc>1)
         {ttc=0;}
         s7seg_display();
      }
    }
   if(inputcd(on)==0)
      {
         tt=~tt;  
         s7seg_display();
      }
}

void ktra_on()
{
   if(tt==0)
   {
       setup_timer_0(T0_EXT_H_TO_L|T0_DIV_1); 
       T0= get_timer0();                    // doc ket qua dem san pham
       if(T0>99)
       {
             T0=T0-99;
             set_timer0(1);
             s7seg_display();
       }
   }
   else
   {
       setup_timer_0(T0_OFF);
       s7seg_display();
   }
}
void kta_clr()
{
   if(ttc==1)
   {
      setup_timer_0(T0_EXT_H_TO_L|T0_DIV_1);
      set_timer0(0);
      s7seg_display();;
   }
}
void hienthi()
{
   s7seg.led[0] = m7d[T0%10];
   s7seg.led[1] = m7d[T0/10%10];
   //delay_ms(100);
   s7seg_display();

}

void main()
{
      system_init();
      setup_timer_0(T0_EXT_H_TO_L|T0_DIV_1);    
      set_timer0(0);  
      while(true)
      {
            nutnhan();
            ktra_on();
            kta_clr();
            hienthi();
            s7seg_display();
      }

}


