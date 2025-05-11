#define board d501
#include <tv_boards.c>
#include <tv_lcd.c>
#include <tv_key4x4.c>

unsigned int8 key, time_buzzer = 1,buzzer; // Th?i gian m?c d?nh là 1 giây
unsigned int8 buzzer_status = 0;    // Tr?ng thái c?a buzzer (0: OFF, 1: ON)

void display_lcd() {
    lcd_goto(0, 1);
    lcd_data("DIEU KHIEN BUZZER");

    lcd_goto(0, 2);
    lcd_data("BUZZER: ");
    
    if (buzzer_status == 1)
        lcd_data("ON ");
    else
        lcd_data("OFF");
    
    lcd_data(", TG:");
    lcd_data(time_buzzer + 0x30);  // Hi?n th? th?i gian Y (du?i d?ng ký t?)
}

void buzzer_on(unsigned int8 seconds) {
    buzzer_status = 1;
    display_lcd();  // Hi?n th? tr?ng thái "ON"
    buzzer = 1;     // B?t buzzer
    buzzer_on();     
    delay_ms(seconds * 1000);  // Buzzer kêu trong th?i gian du?c cài d?t
    buzzer =0 ;  // T?t buzzer
         
    buzzer_status = 0;
    buzzer_off();
    display_lcd();  // Hi?n th? tr?ng thái "OFF"
}

void main() {
    system_init();
    lcd_setup();
    display_lcd();

    while(true) {
        if (key4x4_read() == OK) {
            key = key4x4.key;

            if (key >= 0 && key <= 9) {
                time_buzzer = key;  // C?p nh?t th?i gian Y t? phím s?
                display_lcd();      // Hi?n th? l?i th?i gian m?i
            }
            else if (key == 0x0A) {  // N?u phím 'A' du?c nh?n
                if (time_buzzer > 0) {
                    buzzer_on(time_buzzer);
                                        // Kích ho?t buzzer v?i th?i gian Y
                }
            }
        }
    }
}

