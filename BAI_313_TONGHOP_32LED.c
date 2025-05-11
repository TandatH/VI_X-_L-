
#INCLUDE<TV_BOARDS.C>
unsigned int8 n,i,m;
void sangtat_5lan()
{
   if(n<10)
   {
         led32.ledx32=~led32.ledx32;
         delay_ms(200);
         led32_display();
         n++;
   }
   else
   {
      n=0; i++;
   }
}
void sangdan_pst()
{
 if(n<=32)
 {
      led32.ledx32=~(0xffffffff<<n);
      delay_ms(100);
      led32_display();
      n++;
 }
 else
 {
   n=0; i++;
 }
} 
void tatdan_pst()
{
   if(n<=32)
   {
         led32.ledx32=(0xffffffff<<n);
         delay_ms(100);
         led32_display();
         n++;
   }
   else
   {
   n=0;i++;
   }
}
void sangdan_tsp()
{
 if(n<=32)
 {
      led32.ledx32=~(0xffffffff>>n);
      delay_ms(100);
      led32_display();
      n++;
 }
 else
 {
   n=0; i++;
 }
} 
void tatdan_tsp()
{
   if(n<=32)
   {
         led32.ledx32=(0xffffffff>>n);
         delay_ms(100);
         led32_display();
         n++;
   }
   else
   {
   n=0;i++;
   }
}
void ngoaivaotrong()
{
   if(n<=16)
   {
         led32.ledx16[0]=~(0xffff<<n);
         led32.ledx16[1]=~(0xffff>>n);
         delay_ms(100);
         led32_display();
         n++;
   }
   else
   {
         n=0;i++;
   }
}
void tatngoaivaotrong()
{
   if(n<=16)
   {
         led32.ledx16[0]=(0xffff<<n);
         led32.ledx16[1]=(0xffff>>n);
         delay_ms(100);
         led32_display();
         n++;
   }
   else
   {
         n=0;i++;
   }
}
void trongrangoai()
{
   if(n<=16)
   {
         led32.ledx16[0]=~(0xffff>>n);
         led32.ledx16[1]=~(0xffff<<n);
         delay_ms(100);
         led32_display();
         n++;
   }
   else
   {
         n=0;i++;
   }
}
void tattrongrangoai()
{
   if(n<=16)
   {
         led32.ledx16[0]=(0xffff>>n);
         led32.ledx16[1]=(0xffff<<n);
         delay_ms(100);
         led32_display();
         n++;
   }
   else
   {
         n=0;i++;
   }
}
void main()
{
      system_init();
      while(true)
      {
            if(i==0) sangtat_5lan();
            else if(i==1) sangdan_pst();
            else if (i==2) tatdan_pst();
            else if(i==3) sangdan_pst();
            else if (i==4) tatdan_pst();
            else if (i==5) sangtat_5lan();
            else if(i==6) sangdan_tsp();
            else if (i==7) tatdan_tsp();
            else if(i==8) sangdan_tsp();
            else if (i==9) tatdan_tsp();
            else if(i==10) sangtat_5lan();
            else if(i==11) ngoaivaotrong();
            else if (i==12) tatngoaivaotrong();
            else if(i==13) ngoaivaotrong();
            else if(i==14) tatngoaivaotrong();
            else if(i==15) sangtat_5lan();
            else if (i==16) trongrangoai();
             else if (i==17) tattrongrangoai();
            else if (i==18) trongrangoai();
            else if (i==19) tattrongrangoai();
            else if (i==20) i=0;
      }
}





