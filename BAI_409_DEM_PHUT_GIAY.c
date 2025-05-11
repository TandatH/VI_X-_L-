
#define board d501
#include<tv_boards.c>
unsigned int16 secon,phut; // Chú ý: Bien "dem" phai khai báo 16bit
void demphutgiay()
{
      for(phut=0;phut<60;phut++)
      {
        d7seg.led[3] = m7d[phut/10%10];
        d7seg.led[2] = m7d[phut%10];
        delay_ms(200);
        d7seg_display();
        for(secon=0;secon<60;secon++)
        {
            d7seg.led[1] = m7d[secon/10%10];
            d7seg.led[0] = m7d[secon%10];
            delay_ms(200);
            d7seg_display();
        }
      }
}

void main()
{
      system_init();
      while(true)
      {
      demphutgiay();
      }
}
