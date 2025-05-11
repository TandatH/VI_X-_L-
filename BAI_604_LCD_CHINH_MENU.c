#define board d501
#include<tv_boards.c>
#include<tv_lcd.c>
signed int8 giay=0,n; // bien giay va bien chieu phai la signed
signed int8 chieu=1; // muc dich dem lam chieu dem len xuong
void hienthi_muiten()
{
      if(chieu==1)
      {
            lcd_goto(0,1); // Neu dem len thi hien thi mui lên  dau hang 1
            lcd_data(0x7e);// Tra bang ma ASCII da có ma dau mui tên
            lcd_goto(0,2); // Xoa mui ten cua dau hàng 2
            lcd_data(" ");
      }
      else
      {
            lcd_goto(0,1); // Neu dem xuong thi xoa mui tên cua dau hang 1
            lcd_data(" ");
            lcd_goto(0,2); // Hien thi mui ten  dau hang 2
            lcd_data(0x7e);
      }
}
void kiemtra_inv()
{
      if(inputcd(INV)==0) //dem len "chieu =1",dem xuong "chieu=-1"
      {
            chieu=-chieu;
            hienthi_muiten(); // Cap nhat lai vi tri mui tên
      }
}
void main()
{
      system_init();
      lcd_setup();
      lcd_goto(0,0);
      lcd_data("BAI TAP CHINH MENU");
      lcd_goto(1,1);
      lcd_data("DEM LEN");
      lcd_goto(1,2);
      lcd_data("DEM XUONG");
      hienthi_muiten(); // Hien thi dau mui tên
      while(true)
      {
      lcd_goto(9,3);
      printf(lcd_data,"%d ",giay);
      giay = giay + chieu;
      //giay++;
      // "chieu=1" thi dem len,"chieu=-1" thi dem xuong
      if(giay>=60) giay=0; 
      else if(giay<0) giay=59;
      for(n=0;n<100;n++)
      {
            kiemtra_inv();
            delay_ms(10);
      }
      }
}
