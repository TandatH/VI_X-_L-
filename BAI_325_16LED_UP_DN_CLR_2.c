#define board d501
#include <tv_boards.c>
unsigned int1 tt=0;
unsigned int8 m;
void nutnhan()
{ 
   for(m=0;m<=1000;m++)
   {
      if ((inputcd(UP)==0) && (tt==0))
      {
            led32.ledx16[0] = (led32.ledx16[0]<<1)+1;
            //delay_ms(50);
            
      }
     else if((inputcd(UP)==0) && (tt==1))
      {
            led32.ledx16[0] = (led32.ledx16[0]>>1)+0;
           // delay_ms(50);
           
      }
      if ((inputcd(DW)==0) && (tt==0))
      {
            led32.ledx16[0] = (led32.ledx16[0]>>1)+0;
          //  delay_ms(50);
          
      }
      else if((inputcd(DW)==0) && (tt==1))
      {
            led32.ledx16[0] = (led32.ledx16[0]<<1)+1;
          //  delay_ms(50);
          
      }
      if (inputcd(CLR)==0) 
      {
            tt=!tt;
           // delay_ms(50);
          
      }
      led32_display();
   }
}

void main()
{
      system_init();
      while (true)
      {
            nutnhan();
      }
}     
 
