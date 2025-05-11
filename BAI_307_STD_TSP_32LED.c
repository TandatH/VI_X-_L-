#define board d501
#INCLUDE<TV_BOARDS.C>
unsigned int32 i;
VOID MAIN ()
{
      system_init();
      while(true)
      {
         for(i=0;i<=32;i++)
         {
               led32.ledx32 =~(0xffffffff>>i); //sang dan
               delay_ms(100);
               led32_display();
         }
         for(i=0;i<=32;i++)
         {
               led32.ledx32=(0xffffffff>>i); //tat dan 
               delay_ms(100);
               led32_display();
         }
        
      }
}
