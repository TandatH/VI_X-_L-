#define board d501
#include <tv_boards.c>
#include<tv_key4x4.c>
unsigned int8 mp,ht[4]={0xff-128,0xff-128,0xff-128,0xff-128};
void matran()
{
    if(key4x4_read()==OK)
         {
         mp=key4x4.key;
            if(mp<10)
            {
                  mp=key4x4.key;
                  ht[3]=ht[2];
                  ht[2]=ht[1];
                  ht[1]=ht[0];
                  ht[0] = m7d[mp];
            }
            if(mp==11)
            {
                  mp=key4x4.key;
                  ht[0]=ht[1];
                  ht[1]=ht[2];
                  ht[2]=ht[3];
                  ht[3]=0xff-128;
            }
            if(mp==12)
            {
                  mp=key4x4.key;
                  ht[3]=ht[2]=ht[1]=ht[0]= 0xff-128;
            }
         }
}
void main()
{
   system_init();
   while(true)
   {
      matran();
      d7seg.led[0] = ht[0];
      d7seg.led[1] = ht[1];
      d7seg.led[2] = ht[2];
      d7seg.led[3] = ht[3];
      d7seg_display();
      delay_ms(300);
   }
}
