#define board d501
#include<tv_boards.c>
unsigned int16 giay;
void main()
{
      system_init();
      while(true)
      {

        if(giay<60)
         {
               d7seg.led[1] = m7d[giay/10%10];
               d7seg.led[0] = m7d[giay%10];
               d7seg.led[2] = m7d[0/giay];
               d7seg.led[3] = m7d[0/giay];
               d7seg_display();
               delay_ms(500);
               giay++;
           
          }
          else
          {
            giay=0;
          }
         }
         
      
}
