#define board d501
#include <tv_boards.c>
unsigned int8 i,tt=00;
void main()
{
   system_init();
   while(true)
   {
    
      for (i=0;i<60;i++)
      {
         s7seg.led[0]=m7d[i/1%10];
         s7seg.led[1]= m7d[i/10%10];
         for(tt=0;tt<100;tt++) s7seg_display();
        
   
      }
       
   }
}

