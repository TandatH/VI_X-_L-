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
            // khi bien l� unsigned int8 ta d�ng %u
            // khi bien l� signed int8 ta d�ng %d
            // khi bien l� unsigned int16 ta d�ng %lu
            // khi bien l� signed int16 ta d�ng %ld
            // khi bien l� unsigned int32 ta d�ng %lu
            // khi bien l� signed int32 ta d�ng %ld
            // khi bien l� float ta d�ng %f
            // trong vi du tr�n %02u c� nghia bien cun hien thi thuoc kieu
            // unsigned int8 v� muon lay 2 s? - kh�ng x�a s? 0 v� nghia
            giay++;           
            giay%=60;
            delay_ms(1000);
            
      }
}

