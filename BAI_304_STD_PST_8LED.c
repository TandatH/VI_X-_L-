#define board d501
#INCLUDE<TV_BOARDS.C>
unsigned int8 i;
VOID MAIN ()
{
      system_init();
      while(true)
      {
         for(i=0;i<8;i++)
         {
               led32.ledx8[0]= ~(0xff<<i); //sang dan
               delay_ms(100);
               led32_display();
         }
         for(i=0;i<8;i++)
         {
               led32.ledx8[0]=(0xff<<i); //tat dan
               delay_ms(100);
               led32_display();
         }
      }
}
