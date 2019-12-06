/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_hal.h"
#include <stdio.h>
#include <math.h>
#include "OledGrph.h"
#include "OledDriver.h"
#include "arduino.h"
#include "string.h"



/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART1_UART_Init(void);
void BemVindo();


/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	const short ent3 = 2;
	const short ent2 = 3;
	const short ent1 = 9;
	const short ent0 = 10;
	short valor1 = 0;
	short valor2 = 0;
	short val0 = 0;
	short val1 = 0;
	short val2 = 0;
	short val3 = 0;
	const short led1 = 14;
	const short led2 = 12;
	short printa = 0;
  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  OledInit();
  BemVindo();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

	  valor1 = ((val3*8)+(val2*4)+(val1*2)+(val0*1));

	  	  val0 = digitalRead(ent0);
	  	  val1 = digitalRead(ent1);
	  	  val2 = digitalRead(ent2);
	  	  val3 = digitalRead(ent3);


	  	  valor2 = ((val3*8)+(val2*4)+(val1*2)+(val0*1));
	  	  if(valor1==valor2){
	  		  printa = 0;
	  		  delay(50);
	  	  }
	  	  else{
	  		  printa = 1;
	  		  delay(50);
	  	  }
	  	  valor1 = valor2;
	  	  delay(50);


	  	  //ficar piscando enquanto a senha est� sendo redefinida
	  	  if(valor1==5){
	  		  digitalEscrever(led2, 1);
	  		  delay(500);
	  		  digitalEscrever(led2, 0);
	  		  delay(500);
	  	  }

	  	  if(printa > 0)
	  	  {
	  		  switch(valor1){
	  		  case 0: OledClear();
	  		  	  	  OledSetCursor(0,0);
	  		  	  	  OledPutString("Senha Mestre");
	  		  	  	  OledSetCursor(0,1);
	  		  	  	  OledPutString("digitada com    sucesso!");
	  		  	  	  delay(2000);
	  		  	  	  OledClear();
	  		  	  	  BemVindo();
	  				  break;

	  		  case 1:
	  			  	  HAL_UART_Transmit(&huart1,(uint8_t *)"TITULAR: Rodrigo\nAPARTAMENTO: 1\nEntrada Liberada\n\n",52, 100);
	  				  OledClear();
	  				  OledSetCursor(0,0);
	  				  OledPutString("ENTRADA LIBERADA");
	  				  OledSetCursor(0,1);
	  				  OledPutString("APARTAMENTO 1");
	  				  digitalEscrever(led1, 1);
	  				  delay(3000);
					  OledClear();
					  BemVindo();
					  digitalEscrever(led1, 0);


	  				  break;
	  		  case 2: HAL_UART_Transmit(&huart1,(uint8_t *)"TITULAR: Thierry\nAPARTAMENTO: 2\nEntrada Liberada\n\n",52, 100);
	  				  OledClear();
	  				  OledSetCursor(0,0);
	  				  OledPutString("ENTRADA LIBERADA");
	  				  OledSetCursor(0,1);
	  				  OledPutString("APARTAMENTO 2");
	  				  digitalEscrever(led1, 1);
					  delay(3000);
					  OledClear();
					  BemVindo();
					  digitalEscrever(led1, 0);
	  				  break;
	  		  case 3: HAL_UART_Transmit(&huart1,(uint8_t *)"TITULAR: Gabriela\nAPARTAMENTO: 3\nEntrada Liberada\n\n",52, 100);
	  				  OledClear();
	  				  OledSetCursor(0,0);
	  				  OledPutString("ENTRADA LIBERADA");
	  				  OledSetCursor(0,1);
	  				  OledPutString("APARTAMENTO 3");
	  				  digitalEscrever(led1, 1);
					  delay(3000);
					  OledClear();
					  BemVindo();
					  digitalEscrever(led1, 0);
	  				  break;
	  		  case 4: HAL_UART_Transmit(&huart1,(uint8_t *)"TITULAR: Gabriel\nAPARTAMENTO: 4\nEntrada Liberada\n\n",52, 100);
	  				  OledClear();
	  				  OledSetCursor(0,0);
	  				  OledPutString("ENTRADA LIBERADA");
	  				  OledSetCursor(0,1);
	  				  OledPutString("APARTAMENTO 4");
	  				  digitalEscrever(led1, 1);
					  delay(3000);
					  OledClear();
					  BemVindo();
					  digitalEscrever(led1, 0);
	  				  break;
	  		  case 5: OledClear();
	  				  OledSetCursor(0,0);
	  				  OledPutString("REDEFINICAO DE");
	  				  OledSetCursor(0,1);
	  				  OledPutString("SENHA");
	  				  HAL_Delay(2000);
	  				  OledClear();
	  				  OledSetCursor(0,0);
	  				  OledPutString("Digite o usuarioe a senha mestre");
	  				  HAL_UART_Transmit(&huart1,(uint8_t *)"A SENHA ESTA SENDO REDEFINIDA\n\n", 32, 100);
	  				  break;
	  		  case 6: HAL_UART_Transmit(&huart1,(uint8_t *)"SISTEMA TRAVADO, COMPARECA A ENTRADA\n\n",40, 100);
	  				  OledClear();
	  				  OledSetCursor(0,0);
	  				  OledPutString("3 ERROS         SISTEMA TRAVADO");
	  				  OledSetCursor(0,2);
	  				  OledPutString("Espere porteiro");
	  				  digitalEscrever(led2, 1);
	  				  digitalEscrever(led1, 1);
	  				  break;
	  		  case 7: OledClear();
	  				  OledSetCursor(0,0);
	  				  OledPutString("Digite a nova   senha");
	  				  break;
	  		  case 8: OledClear();
					  OledSetCursor(0,0);
					  OledPutString("SENHA INCORRETA");
					  OledSetCursor(0,1);
					  OledPutString("Digite novamente");
					  OledSetCursor(0,2);
					  OledPutString("Ha 2 tentativas");
					  digitalEscrever(led2, 1);
					  delay(3000);
					  digitalEscrever(led2, 0);
					  OledClear();
	  				  BemVindo();
	  				  break;
	  		  case 9: OledClear();
			  	  	  OledSetCursor(0,0);
			  	  	  OledPutString("SENHA INCORRETA");
			  	  	  OledSetCursor(0,1);
			  	  	  OledPutString("Digite novamente");
			  	  	  OledSetCursor(0,2);
			  	  	  OledPutString("Ha 1 tentativa");
			  	  	  digitalEscrever(led2, 1);
			  	  	  delay(3000);
			  	   	  digitalEscrever(led2, 0);
			  	  	  OledClear();
			  	  	  BemVindo();
	  				  break;
	  		  case 10:OledClear();
	  		  	  	  OledSetCursor(0,0);
	  		  	  	  OledPutString("DESTRAVADO");
	  		  	  	  delay(2000);
	  		  	  	  BemVindo();
	  		  	      digitalEscrever(led2, 0);
	  		  	      digitalEscrever(led1, 0);
	  				  break;
	  		  case 11:OledSetCursor(0,4);
	  	  	  	  	  OledPutString("*");
	  	  	  	  	  break;
	  		  case 12:OledSetCursor(0,4);
	  			  	  OledPutString("**");
	  				  break;
	  		  case 13:OledSetCursor(0,4);
	  	  	  	  	  OledPutString("***");
	  				  break;
	  		  case 14:OledClear();
	  			  	  OledSetCursor(0,0);
	  	  	  	  	  OledPutString("SENHA OU USUARIOINCORRETO");
	  	  	  	  	  OledSetCursor(0,2);
	  	  	  	  	  OledPutString("Operacao");
	  	  	  	  	  OledSetCursor(0,3);
	  	  	  	  	  OledPutString("Invalida");
	  	  	  	  	  digitalEscrever(led2, 1);
					  delay(3000);
					  digitalEscrever(led2, 0);
	  	  	  		  BemVindo();
	  				  break;
	  		  case 15:HAL_UART_Transmit(&huart1,(uint8_t *)"A SENHA FOI REDEFINIDA\n\n",26, 100);
	  		  	  	  OledClear();
	  		  	  	  OledSetCursor(0,0);
	  		  	  	  OledPutString("Senha redefinida");
	  		  	  	  delay(1000);
	  		  	  	  digitalEscrever(led1, 1);
	  		  	  	  delay(200);
	  		  	  	  digitalEscrever(led1, 0);
	  		  	  	  delay(200);
	  		  	      digitalEscrever(led1, 1);
	  		  	  	  delay(200);
	  		  	  	  digitalEscrever(led1, 0);
	  		  	  	  BemVindo();
	  				  break;
	  		  default:
	  			  break;
	  		  }
	  		  delay(1000);
	  	  }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

void BemVindo(){
	  OledClear();
	  OledSetCursor(0,0);
	  OledPutString("CONDOMINIO DEDEL");
	  OledSetCursor(0,1);
	  OledPutString("Pressione # e   digite sua senha");
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pins : PF0 PF1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA3 PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB1 */
  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
