#include <array>
#include <vector>
#include <math.h>

float motor_pwm[3];
int motor_amp = 64;
std::array<int,8> data[8]; //ここに受信データが入ると仮定

//PWM_STARTとかGPIO_WritePinを忘れない
HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);

HAL_GPIO_WritePin(GPIOC,PSB1_Pin,GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOB,BRK1_Pin,GPIO_PIN_RESET);
HAL_GPIO_WritePin(GPIOC,PSB2_Pin,GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOC,BRK2_Pin,GPIO_PIN_RESET);
HAL_GPIO_WritePin(GPIOC,PSB3_Pin,GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOB,BRK3_Pin,GPIO_PIN_RESET);


void WE_3(int Vx,int Vy,int Vr,float* motor_pwm){
    std::array<std::array<float,3>,3> motor_arr{
        {{-1,0,-1}},
        {{1/2,sqrt(3)/-2,-1}},
        {{1/2,sqrt(3)/2,-1}},
    };

    for(int i = 0;i < 3;i++){
        motor_pwm[i] = Vx * motor_arr[i][0] + Vy * motor_arr[i][1] + Vr * motor_arr[i][2];
    }
    if(motor_pwm[0] < 0){
        //HAL_GPIOでDIRECTION_PINを操作
        motor_pwm[0] *= -1.0;
        HAL_GPIO_WritePin(GPIOA,DIRECTION1_Pin,GPIO_PIN_RESET);
    }
    else{
        HAL_GPIO_WritePin(GPIOA,DIRECTION1_Pin,GPIO_PIN_SET);
    }
    if(motor_pwm[1] < 0){
        //HAL_GPIOでDIRECTION_PINを操作
        motor_pwm[1] *= -1.0;
        HAL_GPIO_WritePin(GPIOA,DIRECTION2_Pin,GPIO_PIN_RESET);
    }
    else{
        HAL_GPIO_WritePin(GPIOA,DIRECTION2_Pin,GPIO_PIN_SET);
    }
    if(motor_pwm[1] < 0){
        //HAL_GPIOでDIRECTION_PINを操作
        motor_pwm[1] *= -1.0;
        HAL_GPIO_WritePin(GPIOA,DIRECTION3_Pin,GPIO_PIN_RESET);
    }
    else{
        HAL_GPIO_WritePin(GPIOA,DIRECTION3_Pin,GPIO_PIN_SET);
    }
}

void make_deadzone(int* data,int deadzone){
    for(int i = 0;i < 3){
        if(data[i] < deadzone){
            data[i] = 0;
        }
    }
}

void main(void){
    WE_3(data[1],data[2],data[3],motor_pwm);//data[0]は仰角用
    make_deadzone(motor_pwm,8);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1,motor_pwm[0] * motor_amp);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2,motor_pwm[1] * motor_amp);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3,motor_pwm[2] * motor_amp);

    //PWMでmotor_pwm * motor_ampを送信
}