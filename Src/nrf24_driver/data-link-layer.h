/*
 * data-link-layer.h
 *
 *  Created on: Jun 20, 2020
 *      Author: John Carr
 */

#ifndef NRF24_DRIVER_DATA_LINK_LAYER_H_
#define NRF24_DRIVER_DATA_LINK_LAYER_H_

class NRF_DATA_LINK_LAYER {
//Public Function Prototypes
public:
//Delete all public constructors as this will be an inherited class only
NRF_DATA_LINK_LAYER() = delete;
NRF_DATA_LINK_LAYER(const NRF_DATA_LINK_LAYER&) = delete;
NRF_DATA_LINK_LAYER(const NRF_DATA_LINK_LAYER&&) = delete;
NRF_DATA_LINK_LAYER& operator=(const NRF_DATA_LINK_LAYER&) = delete;
NRF_DATA_LINK_LAYER& operator=(const NRF_DATA_LINK_LAYER&&) = delete;

//Public Constants

//Public Variable
protected:
//Protected Constants
/**
 * @brief These are the special characters in the packet
 */
static constexpr uint8_t START_CHAR = 0xFF;
static constexpr uint8_t END_CHAR = 0x3F;
//Protected Constructor
/**
 * @brief This takes in the initialized SPI instance to use for communicating information
 * @param @uart_instance: initialized SPI instance
 */
NRF_DATA_LINK_LAYER(SPI_TypeDef* uart_instance);
//Protected Function Prototypes
/**
 * @brief This sends a message pointed to be @data of @data_length length
 * @param data: Pointer to data to send
 * @param data_length: Amount of bytes to send
 */
void sendMessage(uint8_t* data, uint16_t data_length);
private:
//Private Variables
const SPI_TypeDef* spiInstance;
const GPIO_TypeDef* cePort;
const uint16_t cePin;
//Private Function Prototypes
/**
 * @brief This sends data through SPI
 * @param Data to send
 */
inline void sendData(uint8_t data);
};

#endif /* NRF24_DRIVER_DATA_LINK_LAYER_H_ */
