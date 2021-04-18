/*
 * geometric_transform.c
 *
 *  Created on: Mar 3, 2021
 *      Author: David
 */

/* CMSIS-DSP Header File */
#include "C:\Users\David\Documents\Arm\Packs\ARM\CMSIS\5.7.0\CMSIS\DSP\Include\arm_math.h"

#include <stddef.h>

/* TI-Drivers Header files */
#include <ti/drivers/GPIO.h>

/* Display Header files */
#include <ti/display/Display.h>
#include <ti/display/DisplayUart.h>
#include <ti/display/DisplayExt.h>
#include <ti/display/AnsiColor.h>

//Hardcoded corner values for debugging
//float32_t bottom_right_x= 3329.5323459998582;
//float32_t bottom_right_y= 2685.421519193232;
//float32_t bottom_left_x= 1114.0027403709637;
//float32_t bottom_left_y= 2740.370963780482;
//float32_t top_right_x= 3243.9054919800406;
//float32_t top_right_y= 526.8183978970234;
//float32_t top_left_x= 1114.0005479484073;
//float32_t top_left_y= 547.9484072624166;

int output_width = 256;
int output_height = 256;

//Matrix data to return not local
float32_t Aff5_M_data[6];


float* calculate_m(float bottom_right_x,
                       float bottom_right_y,
                       float top_right_x,
                       float top_right_y,
                       float bottom_left_x,
                       float bottom_left_y,
                       float top_left_x,
                       float top_left_y){

    float32_t x0 = top_left_x;
    float32_t x1 = bottom_left_x;
    float32_t x2 = top_right_x;
    float32_t x3 = bottom_right_x;

    float32_t y0 = top_left_y;
    float32_t y1 = bottom_left_y;
    float32_t y2 = top_right_y;
    float32_t y3 = bottom_right_y;

    float32_t u0 = 0;
    float32_t u1 = 0;
    float32_t u2 = output_width;
    float32_t u3 = output_width;

    float32_t v0 = 0;
    float32_t v1 = output_height;
    float32_t v2 = 0;
    float32_t v3 = output_height;

//    float32_t A_data[] = {x0, y0, 1, 0, 0, 0, -x0*u0, -y0*u0,
//                          x1, y1, 1, 0, 0, 0, -x1*u1, -y1*u1,
//                          x2, y2, 1, 0, 0, 0, -x2*u2, -y2*u2,
//                          x3, y3, 1, 0, 0, 0, -x3*u3, -y3*u3,
//                          0, 0, 0, x0, y0, 1, -x0*v0, -y0*v0,
//                          0, 0, 0, x1, y1, 1, -x1*v1, -y1*v1,
//                          0, 0, 0, x2, y2, 1, -x2*v2, -y2*v2,
//                          0, 0, 0, x3, y3, 1, -x3*v3, -y3*v3};

//    float32_t A2_data[] = {x0, y0, 1, 0, 0, 0, -x0*u0, -y0*u0,
//                x1, y1, 1, 0, 0, 0, -x1*u1, -y1*u1,
//                x2, y2, 1, 0, 0, 0, -x2*u2, -y2*u2,
//                x3, y3, 1, 0, 0, 0, -x3*u3, -y3*u3,
//                0, 0, 0, x0, y0, 1, -x0*v0, -y0*v0,
//                0, 0, 0, x1, y1, 1, -x1*v1, -y1*v1,
//                0, 0, 0, x2, y2, 1, -x2*v2, -y2*v2,
//                0, 0, 0, x3, y3, 1, -x3*v3, -y3*v3};

    float32_t Aff_A_data[] = {x0, y0, 1, 0, 0, 0,
                              x1, y1, 1, 0, 0, 0,
                              x2, y2, 1, 0, 0, 0,
                              0, 0, 0, x0, y0, 1,
                              0, 0, 0, x1, y1, 1,
                              0, 0, 0, x2, y2, 1};

    float32_t Aff_B_data[] = {u0, u1, u2, v0, v1, v2};

    float32_t Aff2_A_data[] = {x0, y0, 1, 0, 0, 0,
                              x1, y1, 1, 0, 0, 0,
                              x3, y3, 1, 0, 0, 0,
                              0, 0, 0, x0, y0, 1,
                              0, 0, 0, x1, y1, 1,
                              0, 0, 0, x3, y3, 1};

    float32_t Aff2_B_data[] = {u0, u1, u3, v0, v1, v3};

    float32_t Aff3_A_data[] = {x0, y0, 1, 0, 0, 0,
                              x2, y2, 1, 0, 0, 0,
                              x3, y3, 1, 0, 0, 0,
                              0, 0, 0, x0, y0, 1,
                              0, 0, 0, x2, y2, 1,
                              0, 0, 0, x3, y3, 1};

    float32_t Aff3_B_data[] = {u0, u2, u3, v0, v2, v3};

    float32_t Aff4_A_data[] = {x1, y1, 1, 0, 0, 0,
                              x2, y2, 1, 0, 0, 0,
                              x3, y3, 1, 0, 0, 0,
                              0, 0, 0, x1, y1, 1,
                              0, 0, 0, x2, y2, 1,
                              0, 0, 0, x3, y3, 1};

    float32_t Aff4_B_data[] = {u1, u2, u3, v1, v2, v3};

//    float32_t B_data[] = {u0, u1, u2, u3, v0, v1, v2, v3};



    float32_t Aff_A_inverse_data[36];

    float32_t Aff2_A_inverse_data[36];

    float32_t Aff3_A_inverse_data[36];

    float32_t Aff4_A_inverse_data[36];

//    float32_t A_inverse_data[64];
//
//    float32_t M_data[8];

    float32_t Aff_M_data[6];

    float32_t Aff2_M_data[6];

    float32_t Aff3_M_data[6];

    float32_t Aff4_M_data[6];

    //done

//    arm_matrix_instance_f32 A, A2, B, A_inverse, M;

    arm_matrix_instance_f32 Aff_A, Aff_B, Aff_A_inverse, Aff_M;

    arm_matrix_instance_f32 Aff2_A, Aff2_B, Aff2_A_inverse, Aff2_M;

    arm_matrix_instance_f32 Aff3_A, Aff3_B, Aff3_A_inverse, Aff3_M;

    arm_matrix_instance_f32 Aff4_A, Aff4_B, Aff4_A_inverse, Aff4_M;

    arm_matrix_instance_f32 Aff5_M;

    uint32_t rows, cols;

    arm_status status;

    //initialize matrix A
//
//    rows = 8;
//    cols = 8;
//
//    arm_mat_init_f32(&A, rows, cols, (float32_t *) A_data);
//
//    arm_mat_init_f32(&A2, rows, cols, (float32_t *) A2_data);

    //Initialize matrix A_inverse

//    arm_mat_init_f32(&A_inverse, rows, cols, (float32_t *) A_inverse_data);

    //initialize Aff matrices

    rows = 6;
    cols = 6;

    arm_mat_init_f32(&Aff_A, rows, cols, (float32_t *) Aff_A_data);
    arm_mat_init_f32(&Aff2_A, rows, cols, (float32_t *) Aff2_A_data);
    arm_mat_init_f32(&Aff3_A, rows, cols, (float32_t *) Aff3_A_data);
    arm_mat_init_f32(&Aff4_A, rows, cols, (float32_t *) Aff4_A_data);

    //initialize Aff inverse matrix

    arm_mat_init_f32(&Aff_A_inverse, rows, cols, (float32_t *) Aff_A_inverse_data);
    arm_mat_init_f32(&Aff2_A_inverse, rows, cols, (float32_t *) Aff2_A_inverse_data);
    arm_mat_init_f32(&Aff3_A_inverse, rows, cols, (float32_t *) Aff3_A_inverse_data);
    arm_mat_init_f32(&Aff4_A_inverse, rows, cols, (float32_t *) Aff4_A_inverse_data);

    //initialize Aff B

    rows = 6;
    cols = 1;

    arm_mat_init_f32(&Aff_B, rows, cols, (float32_t *) Aff_B_data);
    arm_mat_init_f32(&Aff2_B, rows, cols, (float32_t *) Aff2_B_data);
    arm_mat_init_f32(&Aff3_B, rows, cols, (float32_t *) Aff3_B_data);
    arm_mat_init_f32(&Aff4_B, rows, cols, (float32_t *) Aff4_B_data);

    //initialize Aff M

    arm_mat_init_f32(&Aff_M, rows, cols, (float32_t *) Aff_M_data);
    arm_mat_init_f32(&Aff2_M, rows, cols, (float32_t *) Aff2_M_data);
    arm_mat_init_f32(&Aff3_M, rows, cols, (float32_t *) Aff3_M_data);
    arm_mat_init_f32(&Aff4_M, rows, cols, (float32_t *) Aff4_M_data);
    arm_mat_init_f32(&Aff5_M, rows, cols, (float32_t *) Aff5_M_data);

    //Initialize matrix B
//
//    rows = 8;
//    cols = 1;
//
//    arm_mat_init_f32(&B, rows, cols, (float32_t *) B_data);
//
//    //Initialize matrix M
//
//    arm_mat_init_f32(&M, rows, cols, (float32_t *) M_data);

    //Calculate A_inverse

//    status = arm_mat_inverse_f32(&A2, &A_inverse);

    status = arm_mat_inverse_f32(&Aff_A, &Aff_A_inverse);
    status = arm_mat_inverse_f32(&Aff2_A, &Aff2_A_inverse);
    status = arm_mat_inverse_f32(&Aff3_A, &Aff3_A_inverse);
    status = arm_mat_inverse_f32(&Aff4_A, &Aff4_A_inverse);

    int success = (status == ARM_MATH_SUCCESS) ? 1 : 0;

    //A^-1 * B = M

//    status = arm_mat_mult_f32(&A_inverse, &B, &M);

    status = arm_mat_mult_f32(&Aff_A_inverse, &Aff_B, &Aff_M);
    status = arm_mat_mult_f32(&Aff2_A_inverse, &Aff2_B, &Aff2_M);
    status = arm_mat_mult_f32(&Aff3_A_inverse, &Aff3_B, &Aff3_M);
    status = arm_mat_mult_f32(&Aff4_A_inverse, &Aff4_B, &Aff4_M);

    //Take the average of all 4

    //Add them together

    status = arm_mat_add_f32(&Aff_M, &Aff2_M, &Aff_M);
    status = arm_mat_add_f32(&Aff_M, &Aff3_M, &Aff_M);
    status = arm_mat_add_f32(&Aff_M, &Aff4_M, &Aff_M);

    //Scale by a fourth

    float32_t scale = .25;

    status = arm_mat_scale_f32(&Aff_M, scale, &Aff5_M);

    return Aff5_M_data;
}
