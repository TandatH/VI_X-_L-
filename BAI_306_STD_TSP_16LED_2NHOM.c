#define board d501
#INCLUDE<TV_BOARDS.C>
unsigned int16 i;
VOID MAIN ()
{
      system_init();
      while(true)
      {
         for(i=0;i<=16;i++)
         {
               led32.ledx16[0]= ~(0xffff>>i); //sang dan
               led32.ledx16[1]=~(0xffff>>i); //sang dan
               delay_ms(100);
               led32_display();
         }
         for(i=0;i<=16;i++)
         {
               led32.ledx16[0]=(0xffff>>i); //tat dan
               led32.ledx16[1]=(0xffff>>i); //tat dan 
               delay_ms(100);
               led32_display();
         }
        
      }
}
