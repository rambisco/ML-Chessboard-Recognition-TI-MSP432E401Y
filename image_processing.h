/*
 * image_processing.h
 *
 *  Created on: Apr 17, 2021
 *      Author: David
 */

#ifndef IMAGE_PROCESSING_H_
#define IMAGE_PROCESSING_H_

void* image_processing_init();
unsigned char process_pixel(unsigned char* colors);
uint32_t find_borders();

#endif /* IMAGE_PROCESSING_H_ */
