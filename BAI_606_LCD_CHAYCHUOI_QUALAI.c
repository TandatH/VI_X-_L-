#define board d501
#include <tv_boards.c>
#include <tv_lcd.c>

unsigned int8 n, i;
int1 direction = 1;  // Bi?n d? ki?m tra hu?ng, 1 là sang trái, 0 là sang ph?i

void quancao()
{
    const unsigned int8 T[39] = "TRUONG DAI HOC SU PHAM KY THUAT TP.HCM"; // Chu?i dài 39 ký t?

    if (direction) // N?u hu?ng là t? ph?i sang trái
    {
        for (n = 0; n <= 20; n++)  // Ch?y t? ph?i sang trái
        {
            lcd_goto(0, 0);
            lcd_command(0x80);
            for (i = 0; i < 19; i++)
            {
                lcd_data(T[n + i]); // In t?ng ký t? trên LCD
            }
            delay_ms(200);
        }
        direction = 0; // Ð?i hu?ng sau khi k?t thúc ch?y t? ph?i sang trái
    }
    else // N?u hu?ng là t? trái sang ph?i
    {
        for (n = 20; n > 0; n--)  // Ch?y ngu?c l?i t? trái sang ph?i
        {
            lcd_goto(0, 0);
            lcd_command(0x80);
            for (i = 0; i < 19; i++)
            {
                lcd_data(T[n + i]);
            }
            delay_ms(200);
        }
        direction = 1; // Ð?i hu?ng sau khi k?t thúc ch?y t? trái sang ph?i
    }
}

void main()
{
    system_init();
    lcd_setup();

    while (true)
    {
        quancao();  // G?i hàm qu?ng cáo liên t?c
    }
}

