
#INCLUDE<TV_BOARDS.C>
unsigned int8 n,i;

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
void main()
{
      system_init();
      while(true)
      {
            if(i==0) sangdan_tsp();
            else if(i==1) tatdan_tsp();
            else if(i==2) sangdan_pst();
            else if(i==3) tatdan_pst();
            else if(i==4) i=0;
      }
}





