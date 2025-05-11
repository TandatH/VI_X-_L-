
#INCLUDE<TV_BOARDS.C>
unsigned int8 i,n;
VOID MAIN ()
{
      system_init();
      while(true)
      //SANG TAT 5 LAN
      {    
         for(i=0;i<10;i++)
   {
            led32.ledx32=~led32.ledx32;
            delay_ms(200);
            led32_display();
   }
         for(i=0;i<2;i++) // sang dan tat dan PST 2 lan
    {
              for(n=0;n<=32;n++)
         {
                led32.ledx32 =~(0xffffffff<<n); 
                delay_ms(100);
                led32_display();
         }
               for(n=0;n<=32;n++)
         {
                led32.ledx32=(0xffffffff<<n); 
                delay_ms(100);
                led32_display();
         }
      }
     //32led chop tat 5 lan          
         for(i=0;i<10;i++)
             {
            led32.ledx32=~led32.ledx32;
            delay_ms(200);
            led32_display();
             }
          // sang dan tat dan TSP 2 lan   
          for(i=0;i<2;i++) 
       {
              for(n=0;n<=32;n++)
         {
                led32.ledx32 =~(0xffffffff>>n);
                delay_ms(100);
                led32_display();
         }
               for(n=0;n<=32;n++)
         {
                led32.ledx32=(0xffffffff>>n); 
                delay_ms(100);
                led32_display();
         }
      }
      // 32 led chop tat 5 lan
           for(i=0;i<10;i++)
             {
               led32.ledx32=~led32.ledx32;
               delay_ms(200);
               led32_display();
             }
            //32 led sang dan va tat dan tu ngoai vao 2 lan
            for(i=0;i<2;i++)
            {
              for(n=0;n<=16;n++)
              {
                  led32.ledx16[1]=~(0xffff>>n);
                  led32.ledx16[0]=~(0xfffff<<n);
                  delay_ms(100);
                  led32_display();
              }
              for(n=0;n<=16;n++)
              {
                  led32.ledx16[1]=(0xffff>>n);
                  led32.ledx16[0]=(0xffff<<n);
                  delay_ms(100);
                  led32_display();
              }
            }
           // 32 led chop tat 5 lan
            for(i=0;i<10;i++)
             {
               led32.ledx32=~led32.ledx32;
               delay_ms(200);
               led32_display();
             }
           // 32 led sang dan va tat dan tu trong ra ngoai 2 lan
           for(i=0;i<2;i++)
            {
              for(n=0;n<=16;n++)
              {
                  led32.ledx16[1]=~(0xffff<<n);
                  led32.ledx16[0]=~(0xfffff>>n);
                  delay_ms(100);
                  led32_display();
              }
              for(n=0;n<=16;n++)
              {
                  led32.ledx16[1]=(0xffff<<n);
                  led32.ledx16[0]=(0xffff>>n);
                  delay_ms(100);
                  led32_display();
              }
            }
     }
}
