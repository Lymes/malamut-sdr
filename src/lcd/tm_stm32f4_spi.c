/**	
 * |----------------------------------------------------------------------
 * | Copyright (C) Tilen Majerle, 2014
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */
#include "tm_stm32f4_spi.h"

/* Private functions */
static void TM_SPIx_Init(SPI_TypeDef* SPIx, TM_SPI_PinsPack_t pinspack, TM_SPI_Mode_t SPI_Mode, uint16_t SPI_BaudRatePrescaler, uint16_t SPI_MasterSlave, uint16_t SPI_FirstBit);
void TM_SPI1_INT_InitPins(TM_SPI_PinsPack_t pinspack);
void TM_SPI2_INT_InitPins(TM_SPI_PinsPack_t pinspack);
void TM_SPI3_INT_InitPins(TM_SPI_PinsPack_t pinspack);
void TM_SPI4_INT_InitPins(TM_SPI_PinsPack_t pinspack);
void TM_SPI5_INT_InitPins(TM_SPI_PinsPack_t pinspack);
void TM_SPI6_INT_InitPins(TM_SPI_PinsPack_t pinspack);

void TM_SPI_Init(SPI_TypeDef* SPIx, TM_SPI_PinsPack_t pinspack) {
	/* Init with default settings */
	if (SPIx == SPI1) {
		TM_SPIx_Init(SPI1, pinspack, TM_SPI1_MODE, TM_SPI1_PRESCALER, TM_SPI1_MASTERSLAVE, TM_SPI1_FIRSTBIT);
	}
	if (SPIx == SPI2) {
		TM_SPIx_Init(SPI2, pinspack, TM_SPI2_MODE, TM_SPI2_PRESCALER, TM_SPI2_MASTERSLAVE, TM_SPI2_FIRSTBIT);
	}
	if (SPIx == SPI3) {
		TM_SPIx_Init(SPI3, pinspack, TM_SPI3_MODE, TM_SPI3_PRESCALER, TM_SPI3_MASTERSLAVE, TM_SPI3_FIRSTBIT);
	}
	/*if (SPIx == SPI4) {
		TM_SPIx_Init(SPI4, pinspack, TM_SPI4_MODE, TM_SPI4_PRESCALER, TM_SPI4_MASTERSLAVE, TM_SPI4_FIRSTBIT);
	}
	if (SPIx == SPI5) {
		TM_SPIx_Init(SPI5, pinspack, TM_SPI5_MODE, TM_SPI5_PRESCALER, TM_SPI5_MASTERSLAVE, TM_SPI5_FIRSTBIT);
	}
	if (SPIx == SPI6) {
		TM_SPIx_Init(SPI6, pinspack, TM_SPI6_MODE, TM_SPI6_PRESCALER, TM_SPI6_MASTERSLAVE, TM_SPI6_FIRSTBIT);
	}*/
}

void TM_SPI_InitWithMode(SPI_TypeDef* SPIx, TM_SPI_PinsPack_t pinspack, TM_SPI_Mode_t SPI_Mode) {
	/* Init with custom mode, 0, 1, 2, 3 */
	if (SPIx == SPI1) {
		TM_SPIx_Init(SPI1, pinspack, SPI_Mode, TM_SPI1_PRESCALER, TM_SPI1_MASTERSLAVE, TM_SPI1_FIRSTBIT);
	}
	if (SPIx == SPI2) {
		TM_SPIx_Init(SPI2, pinspack, SPI_Mode, TM_SPI2_PRESCALER, TM_SPI2_MASTERSLAVE, TM_SPI2_FIRSTBIT);
	}
	if (SPIx == SPI3) {
		TM_SPIx_Init(SPI3, pinspack, SPI_Mode, TM_SPI3_PRESCALER, TM_SPI3_MASTERSLAVE, TM_SPI3_FIRSTBIT);
	}
	/*if (SPIx == SPI4) {
		TM_SPIx_Init(SPI4, pinspack, SPI_Mode, TM_SPI4_PRESCALER, TM_SPI4_MASTERSLAVE, TM_SPI4_FIRSTBIT);
	}
	if (SPIx == SPI5) {
		TM_SPIx_Init(SPI5, pinspack, SPI_Mode, TM_SPI5_PRESCALER, TM_SPI5_MASTERSLAVE, TM_SPI5_FIRSTBIT);
	}
	if (SPIx == SPI6) {
		TM_SPIx_Init(SPI6, pinspack, SPI_Mode, TM_SPI6_PRESCALER, TM_SPI6_MASTERSLAVE, TM_SPI6_FIRSTBIT);
	}*/
}

void TM_SPI_InitFull(
	SPI_TypeDef* SPIx, 
	TM_SPI_PinsPack_t pinspack,
	uint16_t SPI_BaudRatePrescaler,
	TM_SPI_Mode_t SPI_Mode_t,
	uint16_t SPI_Mode,
	uint16_t SPI_FirstBit\
) {
	/* Init FULL SPI settings by user */
	if (SPIx == SPI1) {
		TM_SPIx_Init(SPI1, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
	if (SPIx == SPI2) {
		TM_SPIx_Init(SPI2, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
	if (SPIx == SPI3) {
		TM_SPIx_Init(SPI3, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
	/*if (SPIx == SPI4) {
		TM_SPIx_Init(SPI4, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
	if (SPIx == SPI5) {
		TM_SPIx_Init(SPI5, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}
	if (SPIx == SPI6) {
		TM_SPIx_Init(SPI6, pinspack, SPI_Mode_t, SPI_BaudRatePrescaler, SPI_Mode, SPI_FirstBit);
	}*/
}

uint16_t TM_SPI_GetPrescalerFromMaxFrequency(SPI_TypeDef* SPIx, uint32_t MAX_SPI_Frequency) {
	RCC_ClocksTypeDef RCC_Clocks;
	uint32_t APB_Frequency;
	uint8_t i;
	
	/* Prevent false input */
	if (MAX_SPI_Frequency == 0) {
		return SPI_BaudRatePrescaler_256;
	}
	
	/* Get clock values from RCC */
	RCC_GetClocksFreq(&RCC_Clocks);
	
	/* Calculate max SPI clock */
	if (SPIx == SPI1) {
		APB_Frequency = RCC_Clocks.PCLK2_Frequency;
	} else {
		APB_Frequency = RCC_Clocks.PCLK1_Frequency;
	}
	
	/* Calculate prescaler value */
	/* Bits 5:3 in CR1 SPI registers are prescalers */
	/* 000 = 2, 001 = 4, 002 = 8, ..., 111 = 256 */
	for (i = 0; i < 8; i++) {
		if (APB_Frequency / (1 << (i + 1)) <= MAX_SPI_Frequency) {
			/* Bits for BP are 5:3 in CR1 register */
			return (i << 3);
		}
	}
	
	/* Use max prescaler possible */
	return SPI_BaudRatePrescaler_256;
}

uint8_t TM_SPI_Send(SPI_TypeDef* SPIx, uint8_t data) {
	/* Fill output buffer with data */
	SPIx->DR = data;
	/* Wait for transmission to complete */
	while ((SPIx->SR & SPI_SR_TXE) == 0);
	/* Wait for received data to complete */
	while ((SPIx->SR & SPI_SR_RXNE) == 0);
	/* Wait for SPI to be ready */
	while (SPIx->SR & SPI_SR_BSY);
	/* Return data from buffer */
	return SPIx->DR;
}

void TM_SPI_SendMulti(SPI_TypeDef* SPIx, uint8_t* dataOut, uint8_t* dataIn, uint16_t count) {
	uint16_t i;
	for (i = 0; i < count; i++) {
		dataIn[i] = TM_SPI_Send(SPIx, dataOut[i]);
	}
}

void TM_SPI_WriteMulti(SPI_TypeDef* SPIx, uint8_t* dataOut, uint16_t count) {
	uint16_t i;
	for (i = 0; i < count; i++) {
		TM_SPI_Send(SPIx, dataOut[i]);
	}
}

void TM_SPI_ReadMulti(SPI_TypeDef* SPIx, uint8_t* dataIn, uint8_t dummy, uint16_t count) {
	uint16_t i;
	for (i = 0; i < count; i++) {
		dataIn[i] = TM_SPI_Send(SPIx, dummy);
	}
}

uint16_t TM_SPI_Send16(SPI_TypeDef* SPIx, uint16_t data) {
	/* Fill output buffer with data */
	SPIx->DR = data;
	/* Wait for transmission to complete */
	while ((SPIx->SR & SPI_SR_TXE) == 0);
	/* Wait for received data to complete */
	while ((SPIx->SR & SPI_SR_RXNE) == 0);
	/* Wait for SPI to be ready */
	while (SPIx->SR & SPI_SR_BSY);
	/* Return data from buffer */
	return SPIx->DR;
}

void TM_SPI_SendMulti16(SPI_TypeDef* SPIx, uint16_t* dataOut, uint16_t* dataIn, uint16_t count) {
	uint16_t i;
	for (i = 0; i < count; i++) {
		dataIn[i] = TM_SPI_Send16(SPIx, dataOut[i]);
	}
}

void TM_SPI_WriteMulti16(SPI_TypeDef* SPIx, uint16_t* dataOut, uint16_t count) {
	uint16_t i;
	for (i = 0; i < count; i++) {
		TM_SPI_Send16(SPIx, dataOut[i]);
	}
}

void TM_SPI_ReadMulti16(SPI_TypeDef* SPIx, uint16_t* dataIn, uint16_t dummy, uint16_t count) {
	uint16_t i;
	for (i = 0; i < count; i++) {
		dataIn[i] = TM_SPI_Send16(SPIx, dummy);
	}
}

/* Private functions */
static void TM_SPIx_Init(SPI_TypeDef* SPIx, TM_SPI_PinsPack_t pinspack, TM_SPI_Mode_t SPI_Mode, uint16_t SPI_BaudRatePrescaler, uint16_t SPI_MasterSlave, uint16_t SPI_FirstBit) {
	SPI_InitTypeDef SPI_InitStruct;

	/* Set default settings */
	SPI_StructInit(&SPI_InitStruct);
	
	if (SPIx == SPI1) {
		/* Enable SPI clock */
		RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
		
		/* Init pins */
		TM_SPI1_INT_InitPins(pinspack);
		
		/* Set options */
		SPI_InitStruct.SPI_DataSize = TM_SPI1_DATASIZE;
	}
	if (SPIx == SPI2) {
		/* Enable SPI clock */
		RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
		
		/* Init pins */
		TM_SPI2_INT_InitPins(pinspack);
		
		/* Set options */
		SPI_InitStruct.SPI_DataSize = TM_SPI2_DATASIZE;
	
	}
	if (SPIx == SPI3) {
		/* Enable SPI clock */
		RCC->APB1ENR |= RCC_APB1ENR_SPI3EN;
		
		/* Init pins */
		TM_SPI3_INT_InitPins(pinspack);
		
		/* Set options */
		SPI_InitStruct.SPI_DataSize = TM_SPI3_DATASIZE;
	
	} 


	/* Fill SPI settings */
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler;
	SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit;
	SPI_InitStruct.SPI_Mode = SPI_MasterSlave;
	
	/* SPI mode */
	if (SPI_Mode == TM_SPI_Mode_0) {
		SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
		SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	} else if (SPI_Mode == TM_SPI_Mode_1) {
		SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
		SPI_InitStruct.SPI_CPHA = SPI_CPHA_2Edge;
	} else if (SPI_Mode == TM_SPI_Mode_2) {
		SPI_InitStruct.SPI_CPOL = SPI_CPOL_High;
		SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	} else if (SPI_Mode == TM_SPI_Mode_3) {
		SPI_InitStruct.SPI_CPOL = SPI_CPOL_High;
		SPI_InitStruct.SPI_CPHA = SPI_CPHA_2Edge;
	}
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
	
	/* Deinit first */
	SPI_Cmd(SPIx, DISABLE);
	SPI_DeInit(SPIx);
	
	/* Init SPI */
	SPI_Init(SPIx, &SPI_InitStruct);
	SPI_Cmd(SPIx, ENABLE);
}

/* Private functions */
void TM_SPI1_INT_InitPins(TM_SPI_PinsPack_t pinspack) {
	/* Init SPI pins */
	if (pinspack == TM_SPI_PinsPack_1) {
#ifdef ILI9341_SPI_NOMOSI
		TM_GPIO_InitAlternate(GPIOA, GPIO_Pin_5 | GPIO_Pin_7, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI1);
#else               
		TM_GPIO_InitAlternate(GPIOA, GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI1);
#endif              
	} else if (pinspack == TM_SPI_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOB, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI1);
	} else if (pinspack == TM_SPI_PinsPack_Custom) {
		/* Call user function */
		TM_SPI_InitCustomPins(SPI1);
	}
}

void TM_SPI2_INT_InitPins(TM_SPI_PinsPack_t pinspack) {
	/* Init SPI pins */
	if (pinspack == TM_SPI_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOB, GPIO_Pin_10, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI2);
		TM_GPIO_InitAlternate(GPIOC, GPIO_Pin_2 | GPIO_Pin_3, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI2);
	} else if (pinspack == TM_SPI_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOB, GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI2);
	} else if (pinspack == TM_SPI_PinsPack_3) {
		TM_GPIO_InitAlternate(GPIOI, GPIO_Pin_0 | GPIO_Pin_2 | GPIO_Pin_3, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI2);
	} else if (pinspack == TM_SPI_PinsPack_Custom) {
		/* Call user function */
		TM_SPI_InitCustomPins(SPI2);
	}
}

void TM_SPI3_INT_InitPins(TM_SPI_PinsPack_t pinspack) {
	/* Enable SPI pins */
	if (pinspack == TM_SPI_PinsPack_1) {
		TM_GPIO_InitAlternate(GPIOI, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI3);
	} else if (pinspack == TM_SPI_PinsPack_2) {
		TM_GPIO_InitAlternate(GPIOC, GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12, TM_GPIO_OType_PP, TM_GPIO_PuPd_NOPULL, TM_GPIO_Speed_High, GPIO_AF_SPI3);
	} else if (pinspack == TM_SPI_PinsPack_Custom) {
		/* Call user function */
		TM_SPI_InitCustomPins(SPI3);
	}
}


