//#define board d501
#include<tv_boards.c>
unsigned int8 T0=0,i,hu=1,n=0,m,t;
unsigned int8 giay=0,bdn=0,phut=0,gio=0;

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
void hien_thi_quet()
{
   s7seg.led[1] = m7d[giay/10%10]; 
   s7seg.led[0] = m7d[giay%10]; 
   s7seg.led[3] = m7d[phut/10%10]; 
   s7seg.led[2] = m7d[phut%10]; 
   s7seg.led[5] = m7d[gio/10%10]; 
   s7seg.led[4] = m7d[gio%10]; 
   s7seg_display(); 
}
void choptat()
{
     if(n<=10)
     {
      
         led32.ledx32=~(led32.ledx32);
         led32_display();
        // delay_ms(50);
        for (t=0;t<40;t++) s7seg_display(); 
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
           // delay_ms(50);
           for (t=0;t<40;t++) s7seg_display(); 
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
            // delay_ms(50);
            for (t=0;t<40;t++) s7seg_display(); 
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
         // delay_ms(50);
         for (t=0;t<40;t++) s7seg_display(); 
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
            //delay_ms(50);
            for (t=0;t<40;t++) s7seg_display(); 
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
      //delay_ms(50);
      for (t=0;t<40;t++) s7seg_display(); 
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
         //delay_ms(50);
         for (t=0;t<40;t++) s7seg_display(); 
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
        // delay_ms(50);
        for (t=0;t<40;t++) s7seg_display(); 
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
         led32_display();
         //delay_ms(10);
         for (t=0;t<40;t++) s7seg_display(); 
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
          // delay_ms(10);
          for (t=0;t<40;t++) s7seg_display(); 
          }
          n++;
     }
   
  else {n=0;hu=1;}
}
void counter()
{
   T0= get_timer0(); 
   if(T0>100)
   {
   T0=T0-100;
   set_timer0(1);
   }
}
void dongho()
{
   if(bdn>=10) 
    {
       bdn=bdn-10;
       giay++;
       giay%=60;
       if(giay>=59)
       {
          phut++;
          phut%=60;  
          if(phut>=59)
          {
             gio++;
             gio%=24;
            }
         }           
    }

}
void main()
{
            
      system_init(); 
      //timer_0
      setup_timer_0 (T0_EXT_H_TO_L|T0_DIV_1);
      set_timer0(0);
      //timer_1
      setup_timer_1(T1_INTERNAL| T1_DIV_BY_8);
      set_timer1(3036);
      enable_interrupts(INT_TIMER1);
      enable_interrupts(GLOBAL);    
      while(true)
      {   
            
            counter();
            d7seg_xoa0VN(T0);
            dongho();
            hien_thi_quet();
                  
       
            
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
            
         
      
                       
              
      }
}
#INT_TIMER1
void ngat_timer1() 
{
      set_timer1(3036);
      bdn++; 
}


    

