#include <algorithm>
#include <array>
#include <vector>
#include <math.h>

typedef enum{ //enum classのがいいのかな？
    ERROR,
    RELOAD,
    SHOOT,
    BELT_POSITIVE,
    BELT_NEGATIVE,
}status_t;

float motor_pwm[3];
int motor_amp = 64;
std::array<int,8> data; //ここに受信データが入ると仮定
std::array<int,4> vec_data;
std::array<int,4> vec_old_data;

int judge_switch(std::array<int,4>* new_arr,std::array<int,4>* old_arr); //FIXME:arrayにする
void toggle_prog(int flag);
void WE_3(int Vx,int Vy,int Vr,float* motor_pwm);
void make_deadzone(int* data,int deadzone);


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
    std::vector<std::vector<float>> motor_arr{
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

int judge_switch(std::array<int,4>* new_arr,std::array<int,4>* old_arr){ //FIXME:読みにくい
    if(new_arr[0]!=old_arr[0] and new_arr[0] == 1){return 1;}　//旧ボタンデータ[0]が新ボタンデータ[0]と等しくないかつ新ボタンデータ[0]が1
    else if(new_arr[1]!=old_arr[1] and new_arr[1] == 1){return 2;}
    else if(new_arr[2]!=old_arr[2] and new_arr[2] == 1){return 3;}
    else if(new_arr[3]!=old_arr[3] and new_arr[3] == 1){return 4;}
    else {return 0;} 
}

void toggle_prog(int flag){
    switch (flag){ //各Caseで関数を呼び出し
        case RELOAD:
            break;
        case SHOOT:
            break;
        case BELT_POSITIVE:
            break;
        case BELT_NEGATIVE:
            break;
        case ERROR;
            break;
    }
}

void main(void){
    int switch_nom;

    for(int i = 0;i < 4;i++){
        vec_data[i] = data[i+4];
    }

    if (vec_data != vec_old_data)　{ //等しくない場合に切り替え操作
        switch_nom = judge_switch(vec_data,vec_old_data); //変更されたスイッチの番号を取得
        toggle_prog(switch_nom); //スイッチ番号を渡してプログラムを実行
        vec_old_data = vec_data; //旧ボタンデータとして登録
    }

    WE_3(data[1],data[2],data[3],motor_pwm);//data[0]は仰角用
    make_deadzone(motor_pwm,8);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1,motor_pwm[0] * motor_amp);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2,motor_pwm[1] * motor_amp);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3,motor_pwm[2] * motor_amp);

    //PWMでmotor_pwm * motor_ampを送信
}