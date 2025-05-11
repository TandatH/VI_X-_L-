#define board d501
#INCLUDE<TV_BOARDS.C>
unsigned int8 i,n;
VOID MAIN ()
{
      system_init();
      while(true)
      {
        for(i=0;i<=32;i++)
          for(n=0;n<32-i;n++)
         {     
               led32.ledx32= (~(0xffffffff<<i)| (0x80000000>>n));
               delay_ms(100);
               led32_display();
         }
        for(i=0;i<=32;i++)
          for(n=0;n<=32-i;n++)
         {
               led32.ledx32= (~(0xffffffff>>i)|((int32)1<<n));
               delay_ms(200);
               led32_display();
         }
      }
}
