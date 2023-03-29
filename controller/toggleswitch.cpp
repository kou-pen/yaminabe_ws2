#include <algorithm>
#include <vector>

typedef enum{
    ERROR,
    RELOAD,
    SHOOT,
    BELT_POSITIVE,
    BELT_NEGATIVE,
}status_t;

std::vector<int> vec_data[4];
std::vector<int> vec_old_data[4];
std::vector<int> data[8]; //ここに受信データが入ると仮定

int judge_switch(std::vector<int>& new_arr,std::vector<int>& old_arr);
void toggle_prog(int flag);

void main(void){
    int switch_nom;

    for(int i = 0;i < 4;i++){
        vec_data[i] = data[i+4];
    }

    bool arr_equal = std::equal(vec_data.cbegin(), vec_data.cend(), vec_old_data.cbegin());

    if not arr_equal{
        switch_nom = judge_switch(vec_data,vec_old_data);
        toggle_prog(switch_nom);
        vec_old_data = vec_data;
    }
}

int judge_switch(std::vector<int>& new_arr,std::vector<int>& old_arr){
    if(new_arr[0]!=old_arr[0] and new_arr[0] == 1){return 1;}
    else if(new_arr[1]!=old_arr[1] and new_arr[1] == 1){return 2;}
    else if(new_arr[2]!=old_arr[2] and new_arr[2] == 1){return 3;}
    else if(new_arr[3]!=old_arr[3] and new_arr[3] == 1){return 4;}
    else {return 0;}
}

void toggle_prog(int flag){
    switch (flag){
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












