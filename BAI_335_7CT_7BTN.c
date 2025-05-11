#define board d501
#include <tv_boards.c>
#include <tv_key4x4.c>
unsigned int1 tt=0;
unsigned int8 i,n,m;
unsigned int32 mode=0;

void kt_nutnhan()
{
   if(key4x4_read()==OK)
   {
      if(key4x4.key==7) tt=~tt;
      if(tt==0)
      {
            
            if((key4x4.key>=1) && (key4x4.key<=6)) mode = key4x4.key;
      }
      if(tt==1)
      {
            
            mode = 0;
            tt=0;
      }
   }
}

void choptat()
{
         if(mode!=0)
          {
               led32.ledx32=0;
               led32_display();
               break;
         }
         led32.ledx32= ~ (led32.ledx32);
         led32_display();
         delay_ms(50);
   //     for(m=0;m<100;m++) kt_nutnhan();
         
}
void sangtatdan_pst()
{
      for(n=0;n<=32;n++)
      {  
            if(mode!=1)
         {
               led32.ledx32=0;
               led32_display();
               break;
         }
            led32.ledx32 =~(0xffffffff<<n); 
            led32_display();
            for(m=0;m<100;m++) kt_nutnhan();
      }
      for(n=0;n<=32;n++)
      {
            if(mode!=1)
         {
               led32.ledx32=0;
               led32_display();
               break;
         }
            led32.ledx32=(0xffffffff<<n); 
            led32_display();
            for(m=0;m<100;m++) kt_nutnhan();
      }    
}

void sangtatdan_tsp()
{
         // sang dan tat dan TSP 2 lan   
         for(n=0;n<=32;n++)
         {
                if(mode!=2)
                {
                  led32.ledx32=0;
                  led32_display();
                  break;
                }
                led32.ledx32 =~(0xffffffff>>n);
                led32_display();
                for(m=0;m<100;m++) kt_nutnhan();
            
         }
         for(n=0;n<=32;n++)
         { 
                if(mode!=2)
         {
               led32.ledx32=0;
               led32_display();
               break;
         }
                led32.ledx32=(0xffffffff>>n); 
                led32_display();
                for(m=0;m<100;m++) kt_nutnhan();
               
         }
}

void ngoaivaotrong_sangdan()
{
      for(n=0;n<=16;n++)
      {
         if(mode!=3)
         {
               led32.ledx32=0;
               led32_display();
               break;
         }
         led32.ledx16[0]=~(0xffff<<n);
         led32.ledx16[1]=~(0xffff>>n);
         led32_display();
         for(m=0;m<=150;m++) kt_nutnhan();
        
      }
      for(n=0;n<=16;n++)
      {
         if(mode!=3)
         {
               led32.ledx32=0;
               led32_display();
               break;
         }
         led32.ledx16[0]=(0xffff<<n);
         led32.ledx16[1]=(0xffff>>n);
         led32_display();
         for(m=0;m<=150;m++) kt_nutnhan();
        
      }
}
void trongrangoai_sangdan()
{
      if(mode!=4)
         {
               led32.ledx32=0;
               led32_display();
               break;
         }
      for(n=0;n<=16;n++)
      {
         
         led32.ledx16[0]=~(0xffff>>n);
         led32.ledx16[1]=~(0xffff<<n);
         led32_display();
        for(m=0;m<100;m++) kt_nutnhan();
         
      }
       if(mode!=4)
         {
               led32.ledx32=0;
               led32_display();
               break;
         }
      for(n=0;n<=16;n++)
      {
        
         led32.ledx16[0]=(0xffff>>n);
         led32.ledx16[1]=(0xffff<<n);
         led32_display();
         for(m=0;m<100;m++) kt_nutnhan();
         
      }
}
void sangdon_pst()
{
       for(i=0;i<=32;i++)
           for(n=0;n<32-i;n++)
         {     if(mode!=5)
         {
               led32.ledx32=0;
               led32_display();
               break;
         }
               led32.ledx32= (~(0xffffffff<<i)| (0x80000000>>n));
               
               led32_display();
               for(m=0;m<100;m++) kt_nutnhan();
         }
}
void sangdon_tsp()
{
      for(i=0;i<=32;i++)
          for(n=0;n<32-i;n++)
         {
               if(mode!=6)
         {
               led32.ledx32=0;
               led32_display();
               break;
         }
               led32.ledx32 = (~(0xffffffff>>i)| ((int32)1<<n));
               
               led32_display();
               for(m=0;m<100;m++) kt_nutnhan();
      
         }
}
void main()
{
      system_init();
      while(true)
      {     
            
           
            for(m=0;m<200;m++)  kt_nutnhan();
            if(mode==0) choptat();
            
            else if (mode==1) sangtatdan_pst();
            else if (mode==2) {sangtatdan_tsp();}
            else if (mode==3) {ngoaivaotrong_sangdan();}
            else if (mode==4) {trongrangoai_sangdan();}
            else if (mode==5) {sangdon_pst();}
            else if (mode==6) {sangdon_tsp();}
      }
}
