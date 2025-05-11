#define board d501
#include <tv_boards.c>
#include <tv_lcd.c>

unsigned int8 n, i;
int1 direction = 1;  // Bi?n d? ki?m tra hu?ng, 1 l� sang tr�i, 0 l� sang ph?i

void quancao()
{
    const unsigned int8 T[39] = "TRUONG DAI HOC SU PHAM KY THUAT TP.HCM"; // Chu?i d�i 39 k� t?

    if (direction) // N?u hu?ng l� t? ph?i sang tr�i
    {
        for (n = 0; n <= 20; n++)  // Ch?y t? ph?i sang tr�i
        {
            lcd_goto(0, 0);
            lcd_command(0x80);
            for (i = 0; i < 19; i++)
            {
                lcd_data(T[n + i]); // In t?ng k� t? tr�n LCD
            }
            delay_ms(200);
        }
        direction = 0; // �?i hu?ng sau khi k?t th�c ch?y t? ph?i sang tr�i
    }
    else // N?u hu?ng l� t? tr�i sang ph?i
    {
        for (n = 20; n > 0; n--)  // Ch?y ngu?c l?i t? tr�i sang ph?i
        {
            lcd_goto(0, 0);
            lcd_command(0x80);
            for (i = 0; i < 19; i++)
            {
                lcd_data(T[n + i]);
            }
            delay_ms(200);
        }
        direction = 1; // �?i hu?ng sau khi k?t th�c ch?y t? tr�i sang ph?i
    }
}

void main()
{
    system_init();
    lcd_setup();

    while (true)
    {
        quancao();  // G?i h�m qu?ng c�o li�n t?c
    }
}

