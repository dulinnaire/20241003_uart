//
// Created by 81301 on 2024/10/3.
//
#include "stm32f4xx.h"
#include "usart.h"

uint16_t cnt = 0;

extern uint8_t tx_buff[2];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart) {
    if (huart->Instance == USART6) {
        cnt++;
        HAL_UART_Transmit_IT(&huart6, tx_buff, sizeof(tx_buff));
        HAL_UART_Receive_IT(&huart6, tx_buff, 2);
    }
}
