//#define board d501
#include<tv_boards.c>
#include<tv_lcd.c>
#include<tv_key4x4.c>
unsigned int8 chuc,dv,i;
unsigned int mp[]={"                    "};
void main()
{
      system_init();
      lcd_setup();
      lcd_goto(3,1);
      lcd_data("HAY NHAN PHIM");
      while(true)
      {
        if(key4x4_read()==ok)
         {
           if(key4x4.key<16) 
                  {
                    for(i=0;i<19;i++)
                    {
                       mp[i]= mp[i+1];
                    }
                    mp[19]=key4x4.key+0x30;
                    lcd_goto(0,2);
                    for(i=0;i<20;i++)
                    {
                       lcd_data(mp[i]);
                    }
                    
                   }
         }

      }
}
