#define board d501
#include <tv_boards.c>
#include <tv_lcd.c>
unsigned int8 giay=0,bdn=0,phut=0,gio=0;
unsigned int1 tt;
unsigned int8 mode=0,m=0,n=0;

void kt_nutnhan()
{
   if(inputcd(inv)==0) mode++;
      if(mode==1)
      {
         if(inputcd(up)==0) giay=giay+1; giay%=60;
         //if(giay>=59) phut++; phut%=60;
         if(inputcd(dw)==0) giay--;
      }
      else if(mode==2)
      {
         if(inputcd(up)==0) phut=phut+1; phut%=60;
         //if(phut>=59) gio++;gio%=24;
         if(inputcd(dw)==0) phut--;
      }
      else if(mode==3)
      {
         if(inputcd(up)==0) gio=gio+1; gio%=24;
         if(inputcd(dw)==0) gio--;
      }
      else if(mode>3) mode=0;
   
}
void ht()
{
            s7seg.led[1] = m7d[giay/10%10]; 
            s7seg.led[0] = m7d[giay%10]; 
            s7seg.led[3] = m7d[phut/10%10]; 
            s7seg.led[2] = m7d[phut%10]; 
            s7seg.led[5] = m7d[gio/10%10]; 
            s7seg.led[4] = m7d[gio%10]; 
            s7seg_display(); 
}

void main()
{
      system_init();
      lcd_setup();
      setup_timer_1(T1_INTERNAL| T1_DIV_BY_4);
      set_timer1(3036);
      enable_interrupts(INT_TIMER1);
      enable_interrupts(GLOBAL);
      
      while(true)
      {
      kt_nutnhan();
      if(bdn>=10) 
      {
            bdn=bdn-10;
            kt_nutnhan();
            giay++;
            giay%=60;
              
            if(giay>=59)
            {
               
               phut++;
               phut%=60;
               if(phut>=59)
               {
                  gio++;
                  gio%=24;
               }
               
            }
            
            
      }
       ht();
      
       lcd_goto(5,1);
       printf(lcd_data,"giay: %02u ",giay);
       lcd_goto(5,2);
       printf(lcd_data,"phut: %02u ",phut);
       lcd_goto(5,3);
       printf(lcd_data,"gio: %02u ", gio);
       }
}
#INT_TIMER1
void ngat_timer1() 
{
      set_timer1(3036);
      bdn++; 
}

