#define board d501
#include<tv_boards.c>
unsigned int16 giay,n;
unsigned int16 m=59;
unsigned int16 s=00;
void giaydemlen()
{
     for(giay=0;giay<60;giay++)
     {
         d7seg.led[1] = m7d[giay/10%10];
         d7seg.led[0] = m7d[giay%10];
         d7seg_display();
         delay_ms(200);
     }
         
}

void giaydemxuong()
{
       for(giay=59;giay>0;giay--)
     {
         d7seg.led[1] = m7d[giay/10%10];
         d7seg.led[0] = m7d[giay%10];
         d7seg_display();
         delay_ms(200);
     }
}
void hienthi59_3s()
{
      d7seg.led[1] = m7d[m/10%10];
      d7seg.led[0] = m7d[m%10];
      d7seg_display();
      delay_ms(3000);
}
void hienthi00_3s()
{
      d7seg.led[1] = m7d[s/10%10];
      d7seg.led[0] = m7d[s%10];
      d7seg_display();
      delay_ms(3000);
}
void main()
{
      system_init();
      while(true)
      {
         giaydemlen();
         hienthi59_3s();
         giaydemxuong();
         hienthi00_3s();
      }
      
}
