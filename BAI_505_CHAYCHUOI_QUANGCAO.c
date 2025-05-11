#define board d501
#include<tv_boards.c>
unsigned int8 n;
//HELLO.CHO 1 LY CAFE
void quangcao()
{
        
            s7seg.led[0]=0xff;
            s7seg.led[1]=0xff;
            s7seg.led[2]=0xff;
            s7seg.led[3]=0xff;
            s7seg.led[4]=0xff;
            s7seg.led[5]=0xff;
            s7seg.led[6]=0xff;
            s7seg.led[7]=0xff;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-64-32-16-4-2;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-32-16-8-64-1;
            s7seg.led[1]=0xff-64-32-16-4-2;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-32-16-8;
            s7seg.led[1]=0xff-32-16-8-64-1;
            s7seg.led[2]=0xff-64-32-16-4-2;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-32-16-8;
            s7seg.led[1]=0xff-32-16-8;
            s7seg.led[2]=0xff-32-16-8-64-1;
            s7seg.led[3]=0xff-64-32-16-4-2;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-1-2-4-8-16-32-128;
            s7seg.led[1]=0xff-32-16-8;
            s7seg.led[2]=0xff-32-16-8;
            s7seg.led[3]=0xff-32-16-8-64-1;
            s7seg.led[4]=0xff-64-32-16-4-2;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff;
            s7seg.led[1]=0xff;
            s7seg.led[2]=0xff;
            s7seg.led[3]=0xff;
            s7seg.led[4]=0xff;
            s7seg.led[5]=0xff;
            s7seg.led[6]=0xff;
            s7seg.led[7]=0xff;
            for(n=0;n<100;n++)  s7seg_display();
            //CHO 1 LY CAFE
            s7seg.led[0]=0XFF-1-32-16-8;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-64-32-16-4-2;
            s7seg.led[1]=0XFF-1-32-16-8;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-1-2-4-8-16-32;
            s7seg.led[1]=0xff-64-32-16-4-2;
            s7seg.led[2]=0XFF-1-32-16-8;
            for(n=0;n<100;n++)  s7seg_display(); //CHO
            
            s7seg.led[0]=m7d[1];
            s7seg.led[1]=0xff-1-2-4-8-16-32;
            s7seg.led[2]=0xff-64-32-16-4-2;
            s7seg.led[3]=0XFF-1-32-16-8;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-32-16-8;
            s7seg.led[1]=m7d[1];
            s7seg.led[2]=0xff-1-2-4-8-16-32;
            s7seg.led[3]=0xff-64-32-16-4-2;
            s7seg.led[4]=0XFF-1-32-16-8;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-32-64-4-8-2;
            s7seg.led[1]=0xff-32-16-8;
            s7seg.led[2]=m7d[1];
            s7seg.led[3]=0xff-1-2-4-8-16-32;
            s7seg.led[4]=0xff-64-32-16-4-2;
            s7seg.led[5]=0XFF-1-32-16-8;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0XFF-1-32-16-8;
            s7seg.led[1]=0xff-32-64-4-8-2;
            s7seg.led[2]=0xff-32-16-8;
            s7seg.led[3]=m7d[1];
            s7seg.led[4]=0xff-1-2-4-8-16-32;
            s7seg.led[6]=0xff-64-32-16-4-2;
            s7seg.led[7]=0XFF-1-32-16-8;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-1-32-64-16-2-4;
            s7seg.led[1]=0XFF-1-32-16-8;
            s7seg.led[2]=0xff-32-64-4-8-2;
            s7seg.led[3]=0xff-32-16-8;
            s7seg.led[4]=m7d[1];
            s7seg.led[5]=0xff-1-2-4-8-16-32;
            s7seg.led[6]=0xff-64-32-16-4-2;
            s7seg.led[7]=0XFF-1-32-16-8;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-1-32-64-16;
            s7seg.led[1]=0xff-1-32-64-16-2-4;
            s7seg.led[2]=0XFF-1-32-16-8;
            s7seg.led[3]=0xff-32-64-4-8-2;
            s7seg.led[4]=0xff-32-16-8;
            s7seg.led[5]=m7d[1];
            s7seg.led[6]=0xff-1-2-4-8-16-32;
            s7seg.led[7]=0xff-64-32-16-4-2;
            for(n=0;n<100;n++)  s7seg_display();
            s7seg.led[0]=0xff-1-32-64-16-8;
            s7seg.led[1]=0xff-1-32-64-16;
            s7seg.led[2]=0xff-1-32-64-16-2-4;
            s7seg.led[3]=0XFF-1-32-16-8;
            s7seg.led[4]=0xff-32-64-4-8-2;
            s7seg.led[5]=0xff-32-16-8;
            s7seg.led[6]=m7d[1];
            s7seg.led[7]=0xff-1-2-4-8-16-32;
            for(n=0;n<100;n++)  s7seg_display();
            
}
void main()
{
      system_init();
      while(true)
      {
           quangcao();
           s7seg_display();
         
      }
}
