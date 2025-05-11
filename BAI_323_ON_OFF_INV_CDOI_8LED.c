#define board d501
#include<tv_boards.c>
void main ()
{
   system_init();
   while(true)
   {
         if(input(ON)==0) led32.ledx8[0]=0xff;
         if(input(OFF)==0) led32.ledx8[0]=0;
         if((inputcd(INV)==0)&&(led32.ledx8[0]!=1)) // so sanh voi 1 de nhan bit sang tat de chuyen doi
                             led32.ledx8[0]=~led32.ledx8[0];
         //delay_ms(50);
         led32_display();
   }
}
