/*
 * arduino.h
 *
 *  Created on: 18 de nov de 2019
 *      Author: Gabriel
 */

#ifndef ARDUINO_H_
#define ARDUINO_H_

unsigned int equivalencia [21][2]={
		{0,0},
		{0,0},
		{GPIOF,GPIO_PIN_0},
		{GPIOF,GPIO_PIN_1},
		{0,0},
		{0,0},
		{GPIOA,GPIO_PIN_0},
		{GPIOA,GPIO_PIN_1},
		{GPIOA,GPIO_PIN_2},
		{GPIOA,GPIO_PIN_3},
		{GPIOA,GPIO_PIN_4},
		{GPIOA,GPIO_PIN_5},
		{GPIOA,GPIO_PIN_6},
		{GPIOA,GPIO_PIN_7},
		{GPIOB,GPIO_PIN_1},
		{0,0},
		{0,0},
		{GPIOA,GPIO_PIN_9},
		{GPIOA,GPIO_PIN_10},
		{GPIOA,GPIO_PIN_13},
		{GPIOA,GPIO_PIN_14}
};

pinMode(int pino, int mode)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	/* GPIO Ports Clock Enable */
	if(pino == 14){
		__HAL_RCC_GPIOB_CLK_ENABLE();
	}
	else if(pino ==2 || pino == 3){

		__HAL_RCC_GPIOF_CLK_ENABLE();
	}
	else{
		__HAL_RCC_GPIOA_CLK_ENABLE();
	}

	if(mode==0){
		/*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(equivalencia[pino][0], equivalencia[pino][1], GPIO_PIN_RESET);

		/*Configure GPIO pin : PA0 */
		GPIO_InitStruct.Pin = equivalencia[pino][1];
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(equivalencia[pino][0], &GPIO_InitStruct);}
	if(mode==1){
		/*Configure GPIO pin : PA1 */
		GPIO_InitStruct.Pin = equivalencia[pino][1];
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(equivalencia[pino][0], &GPIO_InitStruct);
	}
}

delay(int time){
	HAL_Delay(time);
}

digitalEscrever(int pino, int modo){
	if(modo==1){
		HAL_GPIO_WritePin(equivalencia[pino][0], equivalencia[pino][1], GPIO_PIN_SET);
	}
	if(modo==0){
		HAL_GPIO_WritePin(equivalencia[pino][0], equivalencia[pino][1], GPIO_PIN_RESET);
	}
}

digitalRead(int pino){
	HAL_GPIO_ReadPin(equivalencia[pino][0], equivalencia[pino][1]);
}




#endif /* ARDUINO_H_ */
