#define board d501
#include<tv_boards.c>
unsigned int8 n,t=0;
//22161232
const unsigned int8 MSSV[8]={0x02,0x02,0x01,0x06,0x01,0x02,0x03,0x02};
void kt_nutnhan()
{
         if(inputcd(on)==0)
         { 
            t=1;
         }
         if(inputcd(off)==0)
         {
            t=0;
         }
}
void nhan_on()
{
           for(n=0;n<8;n++)
           {
            s7seg.led[n]=m7d[MSSV[n]];
            s7seg_display();
            delay_ms(500);
            
           }
           
         
}
void nhan_off()
{
            for(n=0;n<100;n++) kt_nutnhan();
            s7seg.led[0]=0xff;
            s7seg.led[1]=0xff;
            s7seg.led[2]=0xff;
            s7seg.led[3]=0xff;
            s7seg.led[4]=0xff;
            s7seg.led[5]=0xff;
            s7seg.led[6]=0xff;
            s7seg.led[7]=0xff;
            for(n=0;n<100;n++)  s7seg_display();kt_nutnhan();
         
}
void main()
{
      system_init();
      while(true)
      {
            for(n=0;n<100;n++) kt_nutnhan();
            if(t==1)  nhan_on();
            else if (t==0) nhan_off();
         
      }
}
