#define board d501
#include<tv_boards.c>
unsigned int16 giay,n;
void giaydemlen()
{
     for(giay=0;giay<60;giay++)
     {
         d7seg.led[1] = m7d[giay/10%10];
         d7seg.led[0] = m7d[giay%10];
         d7seg_display();
         delay_ms(500);
     }
         
}

void giaydemxuong()
{
       for(giay=59;giay>0;giay--)
     {
         d7seg.led[1] = m7d[giay/10%10];
         d7seg.led[0] = m7d[giay%10];
         d7seg_display();
         delay_ms(500);
     }
}
void main()
{
      system_init();
      while(true)
      {
         giaydemlen();
         giaydemxuong();
      }
      
}
