#define board d501
#INCLUDE<TV_BOARDS.C>
VOID MAIN ()
{
      system_init();
      while(true)
      {
            led32.ledx8[0]=~led32.ledx8[0];
            delay_ms(200);
            led32_display();
      }
}
