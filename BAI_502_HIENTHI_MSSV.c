#define board d501
#include<tv_boards.c>

void main()
{
      system_init();
      while(true)
      {
         
            s7seg.led[7]=m7d[2];
            s7seg.led[6]=m7d[2];
            s7seg.led[5]=m7d[1];
            s7seg.led[4]=m7d[6];
            s7seg.led[3]=m7d[1];
            s7seg.led[2]=m7d[2];
            s7seg.led[1]=m7d[3];
            s7seg.led[0]=m7d[2];
            s7seg_display();
      }
}
