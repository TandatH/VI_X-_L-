#DEFINE board d501
#include<tv_boards.c>
#include<tv_lcd.c>
#include<tv_key4x4.c>
unsigned int8 i,chuoi1234[80];

void hang_0()
{
      for(i=0;i<80;i++) chuoi1234[i]=" ";
}



void main()
{
      system_init();
      lcd_setup();
      hang_0();
      while(true)
      {
            if(key4x4_read()==OK)
            {
                 
                  if(key4x4.key<10)
                  {
                     for(i=0;i<79;i++)
                    {
                       chuoi1234[i]= chuoi1234[i+1];
                       
                    }
                    chuoi1234[79]=key4x4.key+0x30;
                    
                    lcd_goto(0,3);
                    for(i=0;i<20;i++)
                    {
                       lcd_data(chuoi1234[i]);
                       //delay_ms(200);
                    }
                    lcd_goto(0,2);
                    for(i=20;i<40;i++)
                    {
                       lcd_data(chuoi1234[i]);
                      // delay_ms(200);
                    }
                    lcd_goto(0,1);
                    for(i=40;i<60;i++)
                    {
                       lcd_data(chuoi1234[i]);
                      // delay_ms(200);
                    }
                    lcd_goto(0,0);
                    for(i=60;i<80;i++)
                    {
                       lcd_data(chuoi1234[i]);
                      // delay_ms(200);
                    }
                 
                    
                  }
             }
      }
}
