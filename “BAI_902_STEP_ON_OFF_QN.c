#define board d501
#include<tv_boards.c>
#include<tv_stepmotor.c>
int1 ttquay=0;
void main()
{
      system_init();
      stepmotor.time_per_step =10; // 10ms/step
      stepmotor.direct = stepmotor_direct_reverse; // Quay nghich
      stepmotor.mode = stepmotor_mode_fullstep; // Ch? d? fullstep
      while(true)
      {
            if(input(ON)==0) ttquay=1;
            if(input(OFF)==0) ttquay=0;
            if(ttquay) stepmotor_control(); // Ði?u khi?n d?ng co
      }
}
