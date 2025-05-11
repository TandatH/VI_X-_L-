#include <tv_boards.c>
#include <tv_lcd.c>
unsigned int8 giay=0;
void main()
{
      system_init();
      lcd_setup();
      lcd_goto(0,0);
      lcd_data("BIEN DEM GIAY");
      
      while(true)
      { 
            lcd_goto(9,3);
            printf(lcd_data, "%02u", giay);
            // khi bien là unsigned int8 ta dùng %u
            // khi bien là signed int8 ta dùng %d
            // khi bien là unsigned int16 ta dùng %lu
            // khi bien là signed int16 ta dùng %ld
            // khi bien là unsigned int32 ta dùng %lu
            // khi bien là signed int32 ta dùng %ld
            // khi bien là float ta dùng %f
            // trong vi du trên %02u có nghia bien cun hien thi thuoc kieu
            // unsigned int8 và muon lay 2 s? - không xóa s? 0 vô nghia
            giay++;           
            giay%=60;
            delay_ms(1000);
            
      }
}

