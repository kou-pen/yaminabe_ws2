#include <vector>
#include <math.h>

float motor_pwm[3];
int motor_amp = 64;
std::vector<int> data[8]; 

//PWM_STARTとかGPIO_WritePinを忘れない

float WE_3(int Vx,int Vy,int Vr,float* motor_pwm){
    std::vector<std::vector<float>> motor_arr{
        {{}},
        {{}},
        {{}},
    };

    for(int i = 0;i < 3){
        motor_pwm[i] = Vx * motor_arr[i][0] + Vy * motor_arr[i][1] + Vr * motor_arr[i][2];
        if(motor_pwm[i] < 0){
            //HAL_GPIOでDIRECTION_PINを操作
            motor_pwm[i] *= -1.0;
        i++;
        }
    }
    return *motor_pwm;
}

int make_deadzone(int* data,int deadzone){
    for(int i = 0;i < 3){
        if(data[i] < deadzone){
            data[i] = 0;
        }
    }
}

void main(void){
    WE_3(data[1],data[2],data[3],motor_pwm);//data[0]は仰角用
    make_deadzone(motor_pwm,8);
    //PWMでmotor_pwm * motor_ampを送信
}