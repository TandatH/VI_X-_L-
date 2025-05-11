#define board d501
#include<tv_boards.c>
#include<tv_ds18b20.c>
#include<tv_lcd.c>
unsigned int16 ng,tp;
unsigned int8 gh=35;

void kt_nutnhan()
{
   if(inputcd(up)==0)
   {
      gh++;
      if(gh>60) gh=60;
   }
   if(inputcd(dw)==0)
   {
      gh--;
      if(gh<35) gh=35;
   }
}


void main()
{
      system_init();
      lcd_setup();
      ds18b20_set_resolution(10);// Cài d?t d? phân gi?i 11 bit (0.125d?)
      lcd_goto(14,0);
      lcd_data("GH");
      lcd_goto(0,0);
      lcd_data("GT DO");
      while(true)
         {
               kt_nutnhan();
               d7seg.led[1] = m7d[gh/10%10];
               d7seg.led[0] = m7d[gh%10];
               d7seg_display();
               lcd_write_2x3_num(gh/10%10,14,1);
               lcd_write_2x3_num(gh%10,17,1);
              
               if(ds18b20_read_temperature()==OK)
               {
                  ng = ds18b20.temperatureA>>4; //Ph?n nguyên DS18B20A
                  tp = (ds18b20.temperatureA&0x0f)*100/16; //Th?p phân
                  d7seg.led[3] = m7d[ng/10%10];
                  lcd_write_2x3_num(ng/10%10,0,1);
                  d7seg.led[2] = m7d[ng%10];
                  lcd_write_2x3_num(ng%10,3,1);
                  d7seg_display();          
                  if(ng > gh)
                  {
                     triac_2_off();
                     led32.ledx8[3]=0xff;
                     led32.ledx8[1]=0xff;
                     led32.ledx32=~led32.ledx32;
                     delay_ms(500);//thay the buzz
                     led32_display();
                     lcd_goto(4,3);
                     lcd_data("           "); delay_ms(20);
                     lcd_goto(8,3);
                     lcd_data("SOS"); delay_ms(20);
                  }
                  else
                  {
                     triac_2_on();
                     led32.ledx32=0;
                     led32_display();
                     lcd_goto(7,3);
                     //lcd_command(0x01); delay_ms(20);
                     lcd_data("            "); delay_ms(20);
                     lcd_goto(7,3);
                     lcd_data("safetion"); delay_ms(20);                     
                  }
                 
                  
               }

        }
}
