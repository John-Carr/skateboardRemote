/*
 * data-link-layer.cpp
 *
 *  Created on: Jun 20, 2020
 *      Author: John Carr
 */

#include "data-link-layer.h"

//Private Function Definitions
inline void NRF_DATA_LINK_LAYER::sendData(uint8_t data)
{
	HAL_GPIO_WritePin(NRF_CE_GPIO_Port, NRF_CE_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(this->spiInstance, &data, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(NRF_CE_GPIO_Port, NRF_CE_Pin, GPIO_PIN_SET);
}
//Public Function Definitions
NRF_DATA_LINK_LAYER::NRF_DATA_LINK_LAYER(SPI_HandleTypeDef* spi_instance, GPIO_TypeDef* ce_port, uint16_t ce_pin):
spiInstance{spi_instance}, cePort{ce_port}, cePin{ce_pin}
{}

void NRF_DATA_LINK_LAYER::sendMessage(uint8_t* data, uint16_t data_length)
{
	for(uint16_t i = 0; i < data_length; i++)
	{
		sendData(data[i]);
	}
}
