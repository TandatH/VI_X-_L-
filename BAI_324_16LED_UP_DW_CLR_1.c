#define board d501
#include<tv_boards.c>
unsigned int8 n=0, m;

void main ()
{
   system_init();
   while(true)
   {
         
       if(inputcd(UP)==0) 
            {
              n++;
              led32.ledx16[0] = (led32.ledx16[0]<<1)+1;
              delay_ms(50);
              led32_display();
            } 
           
         else if(inputcd(DW)==0)
            {
             n--;
            led32.ledx16[0] =  (led32.ledx16[0]>>1)+0;
            delay_ms(50);
            led32_display();
            }
         else if (input(CLR)==0) 
            {
            n=0;
            led32.ledx16[0] =  n;
            delay_ms(50);
            led32_display();
            }
           
         
   }
}
