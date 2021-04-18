/*
 * geometric_transform.h
 *
 *  Created on: Mar 3, 2021
 *      Author: David
 */

#ifndef GEOMETRIC_TRANSFORM_H_
#define GEOMETRIC_TRANSFORM_H_

float* calculate_m(float bottom_right_x,
                  float bottom_right_y,
                  float top_right_x,
                  float top_right_y,
                  float bottom_left_x,
                  float bottom_left_y,
                  float top_left_x,
                  float top_left_y);

#endif /* GEOMETRIC_TRANSFORM_H_ */
