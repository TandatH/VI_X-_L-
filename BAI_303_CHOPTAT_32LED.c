#define board d501
#INCLUDE<TV_BOARDS.C>
VOID MAIN ()
{
      system_init();
      while(true)
      {
            led32.ledx32=~led32.ledx32; //dk 32 led chop tat
            delay_ms(200); 
            led32_display();
      }
}
