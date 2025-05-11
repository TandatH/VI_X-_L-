#define board d501
#INCLUDE<TV_BOARDS.C>
VOID MAIN ()
{
      system_init();
      while(true)
      {
            led32.ledx16[1]=~led32.ledx16[1]; //dieu khien 16 led sang tat ben trai
            delay_ms(200); 
            led32_display();
      }
}
