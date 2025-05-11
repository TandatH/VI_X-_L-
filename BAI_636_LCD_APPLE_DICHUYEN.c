#define board d501
#include<tv_boards.c>
#include<tv_lcd.c>
const unsigned int8 traitim[]={0,0x06,0x09,0x08,0x08,0x08,0x08,0x08,
                               0x08,0x08,0x08,0x09,0x06,0,0,0
                               0x0c,0x10,0x1c,0x02,0x02,0x02,002,
                               0x02,0x02,0x02,0x12,0x0c,0x00,0x00,0x00
                               
                              };
unsigned int8 n,x=0;
unsigned int1 tt=0;
void main()
{
      system_init();
      lcd_setup();
      lcd_command(0x40); 
      for(n=0;n<8;n++) lcd_data(traitim[n]); 
      for(n=8;n<16;n++) lcd_data(traitim[n]); 
      for(n=16;n<24;n++) lcd_data(traitim[n]);
      for(n=24;n<32;n++) lcd_data(traitim[n]); 
      lcd_goto(1,0);
      lcd_data("HIEN THI APPLE MOVE");

      
    
      while(true)
      {
      lcd_goto(0,1);
      lcd_data("                    ");
      lcd_goto(0,2);
      lcd_data("                    ");      
      lcd_goto(x,1);
      
      lcd_data(0);  
      lcd_goto(x,2);
      lcd_data(1); 
      lcd_goto(x+1,1);
      lcd_data(2); 
      lcd_goto(x+1,2);
      lcd_data(3); 
      delay_ms(300);
      if(tt)
      {
         if(x<18)
         {
            x++;
         }
         else tt=0;
      }
      else 
      {
         if(x>0)
         {
            x--;
         }
         else tt=1;
      }
      
      }
}
