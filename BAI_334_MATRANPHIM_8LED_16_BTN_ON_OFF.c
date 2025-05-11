#define board d501
#include<tv_boards.c>
#include<tv_key4x4.c>
void main()
{
      system_init();
      while(true)
      {
         if(key4x4_read()==OK)
         {
            if (key4x4.key==0) led32.ledx1[0]= (led32.ledx1[0]=1);
            else if(key4x4.key==1) led32.ledx1[1]=1;
            else if(key4x4.key==2) led32.ledx1[2]=1;
            else if(key4x4.key==3) led32.ledx1[3]=1;
            else if(key4x4.key==4) led32.ledx1[4]=1;
            else if(key4x4.key==5) led32.ledx1[5]=1;
            else if(key4x4.key==6) led32.ledx1[6]=1;
            else if(key4x4.key==7) led32.ledx1[7]=1;
            else if(key4x4.key==8) led32.ledx1[0]=0;
            else if (key4x4.key==9) led32.ledx1[1]=0;
            else if(key4x4.key==10) led32.ledx1[2]=0;
            else if(key4x4.key==11) led32.ledx1[3]=0;
            else if(key4x4.key==12) led32.ledx1[4]=0;
            else if(key4x4.key==13) led32.ledx1[5]=0;
            else if(key4x4.key==14) led32.ledx1[6]=0;
            else if(key4x4.key==15) led32.ledx1[7]=0;
           
            
         led32_display();
         }
       }
}
