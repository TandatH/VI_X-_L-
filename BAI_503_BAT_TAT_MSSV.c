//#define board d501
#include<tv_boards.c>
unsigned int8 i=0;
void nutnhan()
{
      if(inputcd(ON)==0) i=1;
      if(inputcd(OFF)==0) i=2;
}
void main()
{
      system_init();
      while(true)
      {
         nutnhan();
        
            if(i==1)
            {
            s7seg.led[7]=m7d[2];
            s7seg.led[6]=m7d[2];
            s7seg.led[5]=m7d[1];
            s7seg.led[4]=m7d[6];
            s7seg.led[3]=m7d[1];
            s7seg.led[2]=m7d[2];
            s7seg.led[1]=m7d[3];
            s7seg.led[0]=m7d[2];
            for(i=0;i<100;i++)  s7seg_display();
            }
            else if (i==2)
            {
            s7seg.led[7]=0xff;
            s7seg.led[6]=0xff;
            s7seg.led[5]=0xff;
            s7seg.led[4]=0xff;
            s7seg.led[3]=0xff;
            s7seg.led[2]=0xff;
            s7seg.led[1]=0xff;
            s7seg.led[0]=0xff;
            s7seg_display();
            }
      
      }
}
