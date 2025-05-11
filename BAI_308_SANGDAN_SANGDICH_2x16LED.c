//#define board d501
#INCLUDE<TV_BOARDS.C>
unsigned int8 i;
VOID MAIN ()
{
      system_init();
      while(true)
      {
         for(i=0;i<=16;i++)
         {
               led32.ledx16[0]=(0x0001<<i); //16 led phai sang dich PST
               led32.ledx16[1]= ~(0xffff>>i); //16 led trai sang dan TSP
               delay_ms(100);
               led32_display();
         }
         for(i=0;i<=16;i++)
         {
               led32.ledx16[1]=~(0xffff<<i); //16 led trai sang dan PST
               led32.ledx16[0]=(0x8000>>i); //16 led phai sang dich TSP 
               delay_ms(100);
               led32_display();
         }
        
      }
}
