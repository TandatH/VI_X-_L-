//#define board d501
#include<tv_boards.c>
unsigned int8 T0,i,hu=1,n=0,m;
void d7seg_xoa0VN(unsigned int16 d)
{
   unsigned int8 n=0;
      do
      { 
         d7seg.led[n]= m7d[d%10];
         
         d/=10;n++;
      }
      while(d!=0);
         
   for(;n<4;n++) d7seg.led[n]= 0xff;
            
   d7seg_display();

}
void choptat()
{
     if(n<=10)
     {
      
         led32.ledx32=~(led32.ledx32);
         led32_display();
         delay_ms(50);
         n++;
      }
     
     else{ n=0;hu++;}
}
void sangdan_pst()
{
      
      if(n<=32)
      {      
            led32.ledx32= ~(0xffffffff<<n);    
            led32_display();     
            delay_ms(50);    
            n++;
      }
    else 
    { 
    n=0;hu++;
    }
}
void tatdan_pst()
{  
      if(n<=32)
      {
             led32.ledx32= 0xffffffff<<n;
             led32_display();
             delay_ms(50);       
             n++;
      }
     else
     {
     n=0;hu++;
     }
}
   
void sangdan_tsp()
{     
      if(n<=32)
      {
            led32.ledx32= ~(0xffffffff>>n);     
            led32_display();                 
            delay_ms(50);                 
            n++;
      }
      else
      { 
         n=0;hu++;
      }
}


void tatdan_tsp()
{     
      if(n<=32)
      {
          led32.ledx32= 0xffffffff>>n;           
          led32_display();           
          delay_ms(50);            
          n++;
      }
     else
     {
        n=0;hu++;
     }
}
void sangdanngoaivao()
   {
      if(n<=32)
      {
            led32.ledx16[1]= ~(0xffff>>n);
            led32.ledx16[0]=~(0xffff<<n);
            led32_display();
            delay_ms(50);
            n++;
      }
      
    else
    {
           n=0;hu++;
    }
}

void tatdanngoaivao()
{
     if(n<=32)
  {
  
      led32.ledx16[1]= (0xffff>>n);
      led32.ledx16[0]=(0xffff<<n);
      led32_display();
      delay_ms(50);
      n++;
   }
    else 
    {
      n=0;hu++;
    }
}

void sangdantrongra()
{
   if(n<=32)
   {
         led32.ledx16[1]= ~(0xffff<<n);
         led32.ledx16[0]=~(0xffff>>n);
         led32_display();
         delay_ms(50);
         n++;
   }
   else {n=0;hu++;}
}

void tatdantrongra()
{
   if(n<=32)
   {
         led32.ledx16[1]= (0xffff<<n);
         led32.ledx16[0]=(0xffff>>n);
         led32_display();
         delay_ms(50);
         n++;
   }
   else {n=0;hu++;}
}


void sangdonpst()
{
   if(n<=32)
   {
   
      for(m=0;m<32-n;m++)
      {
         led32.ledx32=(0x80000000>>m) | (~(0xffffffff<<n)) ;
         led32_display();delay_ms(10);
      }
      n++;
   }
   
  else {n=0;hu++;}
}
void sangdontsp()
{
   if(n<=32)
   {
     
       for(m=0;m<32-n;m++)
          {
           led32.ledx32=((int32)1<<m) | (~(0xffffffff>>n)) ;
           led32_display();
           delay_ms(10);
          }
          n++;
     }
   
  else {n=0;hu=1;}
}
void main()
{
            
      system_init();                 
      setup_timer_0 (T0_EXT_H_TO_L|T0_DIV_1);
      set_timer0(0);
          
      while(true)
      {   
            T0= get_timer0(); 
            if(T0>100) set_timer0(1);
            
            if (hu==1) choptat();
      
            else if (hu==2)sangdan_pst();
            else if (hu==3)tatdan_pst();
            else if(hu==4)sangdan_tsp();
            else if(hu==5)tatdan_tsp();
            else if(hu==6)sangdanngoaivao();
            else if(hu==7)tatdanngoaivao();
            else if(hu==8)sangdantrongra();
            else if(hu==9)tatdantrongra();
            else if(hu==10)sangdonpst();
            else if(hu==11)sangdontsp();
            d7seg_xoa0VN(T0);
           
         
      
                       
              
      }
}

    

