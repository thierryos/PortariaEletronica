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
#include "TecladoFuncoes.h"
#include <stdio.h>

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

/* USER CODE BEGIN PV */
struct Teclado {
	int N;
	int M;
	unsigned long *tecladoIn;
	unsigned long *tecladoOut;
};
char senha1[4] = {'1','2','3','4'};
char senha2[4] = {'5','6','7','8'};
char senha3[4] = {'0','0','0','0'};
char senha4[4] = {'1','1','1','1'};
char senha_m[4] = {'C','A','1','0'};
short tentativa = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
int comp(char *valor1,char *valor2);
void copy(char *valor1,char *valor2);
void Estrela1 ();
void Estrela2 ();
void Estrela3 ();
void Estrelas (int i);
void MandaBits(int x);
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
  /* USER CODE BEGIN 2 */
  //Inicializa os vetores que armazenam os pinos do teclado
	unsigned long tecladoOut[4] = { GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_2, GPIO_PIN_3 };
	unsigned long tecladoIn[4] = { GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7};
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  char digito = getDigito(tecladoOut, tecladoIn, 4, 4);
	  char senha_entrada[4] = {'0', '0', '0', '0'};

	  	 if(tentativa < 3 )
	  	 {
	  		 if (digito == '#')
	  		 {
	  			 for (int i = 0; i < 4; i++)
	  			 {
	  				 senha_entrada[i] = getDigito(tecladoOut, tecladoIn, 4, 4);
	  				 switch (i)
	  				 {
	  				 case 0:
	  					Estrela1();
	  					break;
	  				 case 1:
	  					Estrela2();
	  					break;
	  				 case 2:
	  					Estrela3();
	  					break;
	  				default:
	  					break;
	  				 }
	  			 }
	  			 if (comp(senha_entrada, senha1) == 1)
	  			 {
	  				 MandaBits(1);
	  				 tentativa = 0;
	  			 }
	  			 else if (comp(senha_entrada, senha2) == 1)
	  			 {
	  				 MandaBits(2);
					 tentativa = 0;
	  			 }
	  			 else if (comp(senha_entrada, senha3) == 1)
				 {
					 MandaBits(3);
					 tentativa = 0;
				 }
	  			 else if(comp(senha_entrada, senha4) == 1)
				 {
	  				 MandaBits(4);
					 tentativa = 0;
				 }
	  			 else if(comp(senha_entrada, senha_m) == 1){
	  				 MandaBits(0);
	  				 tentativa = 0;
	  			 }
	  			 else
	  			 {
	  				tentativa++;
	  				switch (tentativa)
	  				{
	  				case 1:
	  					MandaBits(8);
	  					break;
	  				case 2:
	  					MandaBits(9);
	  					break;
	  				case 3:
	  					MandaBits(6);
	  				}
	  			 }
	  		 }

	  		 if(digito == '*')
	  		 {
	  			MandaBits(5);
	  			char n = '0';
	  			n = getDigito(tecladoOut, tecladoIn, 4, 4);
	  			for(int i = 0; i < 4; i++)
	  			{
	  				 senha_entrada[i] = getDigito(tecladoOut, tecladoIn, 4, 4);
	  				 switch (i)
					 {
					 case 0:
						Estrela1();
						break;
					 case 1:
						Estrela2();
						break;
					 case 2:
						Estrela3();
						break;
					 default:
					 	break;
					 }
	  			}
	  			if ((n == '1') && (comp(senha_entrada, senha_m)))
	  			{
	  				MandaBits(7);
	  				for (int i = 0; i < 4; i++)
					 {
						 senha1[i] = getDigito(tecladoOut, tecladoIn, 4, 4);
						 Estrelas (i);
					 }
	  				MandaBits(15);
	  			}
	  			else if ((n == '2') && (comp(senha_entrada, senha_m)))
				{
	  				MandaBits(7);
					for (int i = 0; i < 4; i++)
					 {
						 senha2[i] = getDigito(tecladoOut, tecladoIn, 4, 4);
						 Estrelas (i);
					 }
					MandaBits(15);
				}
	  			else if ((n == '3') && (comp(senha_entrada, senha_m)))
				{
	  				MandaBits(7);
					for (int i = 0; i < 4; i++)
					 {
						 senha3[i] = getDigito(tecladoOut, tecladoIn, 4, 4);
						 Estrelas (i);
					 }
					MandaBits(15);
				}
	  			else if ((n == '4') && (comp(senha_entrada, senha_m)))
				{
	  				MandaBits(7);
					for (int i = 0; i < 4; i++)
					 {
						 senha4[i] = getDigito(tecladoOut, tecladoIn, 4, 4);
						 Estrelas (i);
					 }
					MandaBits(15);
				}
	  			else
	  			{
	  				MandaBits(14);
	  			}

	  		 }
	  	 }
	  	 else
	  	 {
	  		 if (digito == '#')
	  		 {
	  			 for (int i = 0; i < 4; i++)
	  			 {
	  				 senha_entrada[i] = getDigito(tecladoOut, tecladoIn, 4, 4);
	  				 switch (i)
					 {
					 case 0:
						Estrela1();
						break;
					 case 1:
						Estrela2();
						break;
					 case 2:
						Estrela3();
						break;
					 default:
						 break;
					 }
	  			 }
	  			 if ((comp(senha_entrada, senha_m) == 1))
	  			 {
	  				MandaBits(10);
	  				tentativa = 0;
	  			 }
	  		 }
	  	 }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pins : PF0 PF1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 
                           PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
int comp(char *valor1,char *valor2){
	short ok = 0;
	for(int i=0;i<4;i++){
		if(valor1[i]==valor2[i]){
			ok++;
		}
	}
	if (ok == 4)
		return 1;
	else
		return 0;
}

void copy(char *valor1,char *valor2)
{
	for(int i=0;i<4;i++)
	{
		valor1[i]=valor2[i];
	}
}

void Estrela1 ()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
}

void Estrela2 ()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0 | GPIO_PIN_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10 | GPIO_PIN_9, GPIO_PIN_SET);
}

void Estrela3 ()
{
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9 | GPIO_PIN_10, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_RESET);
}


void Estrelas (int i)
{
	switch (i)
	 {
	 case 0:
		Estrela1();
		break;
	 case 1:
		Estrela2();
		break;
	 case 2:
		Estrela3();
		break;
	 default:
	 	break;
	 }
}

void MandaBits(int x){

	switch (x)
	 {
	case 0:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
		   break;
	case 1:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
		   break;

	case 2:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
		   break;

	case 3:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
		   break;

	case 4:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
		   break;

	case 5:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
		   break;

	case 6:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
		   break;

	case 7:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
		   break;

	case 8:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
		   break;

	case 9:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
		   break;

	case 10:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
		   break;

	case 11:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
		   break;

	case 12:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
		   break;

	case 13:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
		   break;

	case 14:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_RESET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
		   break;
	case 15:
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_1, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOF, GPIO_PIN_0, GPIO_PIN_SET);
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
		   break;
	}




}
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
