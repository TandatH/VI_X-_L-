#include<tv_boards.c>
unsigned int16 dem=0; // Ch� �: Bien "dem" phai khai b�o 16bit
void main()
{
      system_init();
      while(true)
      {
         for(dem=0;dem<1000;dem++)
         {
            d7seg.led[2] = m7d[dem/100%10];
            d7seg.led[1] = m7d[dem/10%10];
            d7seg.led[0] = m7d[dem%10];
            d7seg_display();
            delay_ms(500);
         }
      }
}
