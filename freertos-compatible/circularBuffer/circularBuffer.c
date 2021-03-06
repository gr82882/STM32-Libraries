/**
 ******************************************************************************
 * @file	circularBuffer.c
 * @author	Hampus Sandberg
 * @version	0.1
 * @date	2014-03-01
 * @brief	Contains the function implementations for the circular buffer.
 *			Uses ATOMIC where necessary to avoid problem
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "circularBuffer.h"

/* Private defines -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Functions -----------------------------------------------------------------*/
/**
 * @brief	Initializes the circular buffer that is specified in the parameter
 * @param	CircularBuffer: the  buffer that should be initialized. If the 
 *			buffer already is initialized it will be reset
 * @retval	None
 */
void CIRC_BUFFER_Init(CircularBuffer_TypeDef* CircularBuffer)
{
	CircularBuffer->in = CircularBuffer->data;
	CircularBuffer->out = CircularBuffer->data;
	CircularBuffer->count = 0;
}

/**
 * @brief	Insert an item in the front of the buffer
 * @param	CircularBuffer: the buffer to insert into
 * @param	Data: data to insert
 * @retval	None
 */
void CIRC_BUFFER_Insert(CircularBuffer_TypeDef* CircularBuffer, CIRCULARBUFFER_DATATYPE Data)
{
	*CircularBuffer->in = Data;
		
	if (++CircularBuffer->in == &CircularBuffer->data[CIRCULARBUFFER_SIZE])
		CircularBuffer->in = CircularBuffer->data;
	CircularBuffer->count++;
}

/**
 * @brief	Removes one item from the end of the buffer
 * @param	CircularBuffer: buffer to remove from
 * @retval	data removed from the end of the buffer
 */
CIRCULARBUFFER_DATATYPE CIRC_BUFFER_Remove(CircularBuffer_TypeDef* CircularBuffer)
{
	CIRCULARBUFFER_DATATYPE data = *CircularBuffer->out;
	    
    if (++CircularBuffer->out == &CircularBuffer->data[CIRCULARBUFFER_SIZE])
        CircularBuffer->out = CircularBuffer->data;
    CircularBuffer->count--;
    
    return data;
}

/**
 * @brief	Start peeking at the buffer
 * @param	CircularBuffer: buffer to peek at
 * @retval	None
 */
void CIRC_BUFFER_StartPeeking(CircularBuffer_TypeDef* CircularBuffer)
{
	CircularBuffer->peekOut = CircularBuffer->out;
}

/**
 * @brief	Peeks at the item at the end of the buffer
 * @param	CircularBuffer: buffer to peek at
 * @retval	data at the end of the buffer
 */
CIRCULARBUFFER_DATATYPE CIRC_BUFFER_Peek(CircularBuffer_TypeDef* CircularBuffer)
{
	CIRCULARBUFFER_DATATYPE data = *CircularBuffer->peekOut;

    if (++CircularBuffer->peekOut == &CircularBuffer->data[CIRCULARBUFFER_SIZE])
        CircularBuffer->peekOut = CircularBuffer->data;

    return data;
}

/**
 * @brief	Get the current count for the buffer
 * @param	CircularBuffer: the buffer to get the count for
 * @retval	the count value
 */
CIRCULARBUFFER_COUNTTYPE CIRC_BUFFER_GetCount(CircularBuffer_TypeDef* CircularBuffer)
{    
	CIRCULARBUFFER_COUNTTYPE count;
	count = CircularBuffer->count;

    return count;
}

/**
 * @brief	Check if the buffer is empty
 * @param	CircularBuffer: the buffer to check
 * @retval	(1) if it was empty, (0) otherwise
 */
uint8_t CIRC_BUFFER_IsEmpty(CircularBuffer_TypeDef* CircularBuffer)
{
	return (CIRC_BUFFER_GetCount(CircularBuffer) == 0);
}

/**
 * @brief	Check if the buffer is full
 * @param	CircularBuffer: the buffer to check
 * @retval	(1) if it was full, (0) otherwise
 */
uint8_t CIRC_BUFFER_IsFull(CircularBuffer_TypeDef* CircularBuffer)
{
	return (CIRC_BUFFER_GetCount(CircularBuffer) == CIRCULARBUFFER_SIZE);
}
