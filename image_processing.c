/* image processing file */



#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <ti/display/Display.h>
#include <ti/drivers/GPIO.h>

#include "geometric_transform.h"

unsigned char img[120000];

#define WHITE 0x0
#define BLACK 0x1
#define GREEN 0x2
#define RED 0x3
#define WIDTH 800
#define HEIGHT 600

//Define color cutoff values
uint8_t black_B = 0x64;
uint8_t black_G = 0x64;
uint8_t black_R = 0x64;

uint8_t green_B = 0x64;
uint8_t green_G = 0x64;
uint8_t green_R = 0x64;

uint8_t white_B = 0x64;
uint8_t white_G = 0x64;
uint8_t white_R = 0x64;

uint8_t red_B = 0x80;
uint8_t red_G = 0x80;
uint8_t red_R = 0x80;

//Current pixel index
uint32_t pixel_i;

void* image_processing_init(){

    pixel_i = 0;

    //Allocate one big image. Does not work. We hit the stack and start overwriting local variables...
//    uint32_t img_size = 120000; //800*600/4
//    img = malloc(sizeof(unsigned char)*img_size);


    if(img == NULL) return NULL;

    /* Initialization. Assuming, for now, that it's not necessary */
//    for(uint32_t i = 0; i < img_size; i++){
//        img[i] = 0x00;
//    }

    return img;
}

unsigned char getColor(uint32_t width, uint32_t height){
    unsigned char color;
    height = HEIGHT - height; //picture is upside down.
    uint32_t array_i = (height * WIDTH + width) / 4;
    uint32_t element_i = (height * WIDTH + width) % 4;

    if(element_i == 0){
        color = img[array_i] & 0x03;
    }
    if(element_i == 1){
        color = (img[array_i] & 0x0C) >> 2;
    }
    if(element_i == 2){
        color = (img[array_i] & 0x30) >> 4;
    }
    if(element_i == 3){
        color = (img[array_i] & 0xC0) >> 6;
    }
    return color;
}

unsigned char process_pixel(unsigned char* colors){
    //From SD card: B, G, R

    uint32_t array_i = pixel_i / 4;
    uint32_t element_i = pixel_i % 4;

    unsigned char color;

    if((colors[0] < black_B) && (colors[1] < black_G) && (colors[2] < black_R)){
            //set this pixel black
        color = BLACK;
    }

    if((colors[0] < green_B) && (colors[1] > green_G) && (colors[2] < green_R)){
            //set this pixel green
       color = GREEN;
    }

    if((colors[0] > white_B) && (colors[1] > white_G) && (colors[2] > white_R)){
            //set this pixel white
       color = WHITE;
    }

//    if((colors[0] < red_B) && (colors[1] < red_G) && (colors[2] < red_R)){
//            //set this pixel red
//       color = RED;
//    } not worrying about red for now.....

    //Theoretically, these go in order. can we rely on that?
    if(element_i == 0){
        img[array_i] = (0x00 | color); //the first element will initialize all other values to 0's.
    }
    else{
        //left shift color 2 * the element index to get it in the right spot
        img[array_i] = (img[array_i] | (color << (element_i * 2)));
    }

    pixel_i++;

//    if(pixel_i == 9){
//        printf("Byte 0: %u \n Byte 1: %u \n", img[0], img[1]);
//    }

    return color;
}

uint32_t find_borders(){

    /* Finding top and bottom lines
     * Search until you find a green pixel
     * Start at width/2 and scale with height
     */

    /*
     * Variable Declarations needed for all lines
     */
    uint32_t middle_width = WIDTH/2;
    uint32_t middle_height = HEIGHT/2;
    uint32_t sixty_percent_width = (WIDTH * 3) / 5;
    uint32_t sixty_percent_height = (HEIGHT * 3) / 5;
    unsigned char color;

    //Finding Top Line

    uint32_t top_line_50_x = 0;
    uint32_t top_line_50_y = 0;
    uint32_t top_line_60_x = 0;
    uint32_t top_line_60_y = 0;

    for(uint32_t h_i = 0; h_i < HEIGHT; h_i++){
        color = getColor(middle_width, h_i);
        if(color != GREEN) continue;
        top_line_50_y = h_i;
        top_line_50_x = middle_width;
        break;
    }

    for(uint32_t h_i = 0; h_i < HEIGHT; h_i++){
        color = getColor(sixty_percent_width, h_i);
        if(color != GREEN) continue;
        top_line_60_y = h_i;
        top_line_60_x = sixty_percent_width;
        getColor(sixty_percent_width, h_i);
        break;
    }

    //Finding bottom line

    uint32_t bottom_line_50_x = 0;
    uint32_t bottom_line_50_y = 0;
    uint32_t bottom_line_60_x = 0;
    uint32_t bottom_line_60_y = 0;

    for(uint32_t h_i = HEIGHT; h_i > 0; h_i--){
        color = getColor(middle_width, h_i);
        if(color != GREEN) continue;
        bottom_line_50_y = h_i;
        bottom_line_50_x = middle_width;
        break;
    }

    for(uint32_t h_i = HEIGHT; h_i > 0; h_i--){
        color = getColor(sixty_percent_width, h_i);
        if(color != GREEN) continue;
        bottom_line_60_y = h_i;
        bottom_line_60_x = sixty_percent_width;
        getColor(sixty_percent_width, h_i);
        break;
    }

    //Finding Right Line

    uint32_t right_line_50_x = 0;
    uint32_t right_line_50_y = 0;
    uint32_t right_line_60_x = 0;
    uint32_t right_line_60_y = 0;

    for(uint32_t w_i = WIDTH; w_i > 0; w_i--){
        color = getColor(w_i, middle_height);
        if(color != GREEN) continue;
        right_line_50_y = middle_height;
        right_line_50_x = w_i;
        break;
    }

    for(uint32_t w_i = WIDTH; w_i > 0; w_i--){
        color = getColor(w_i, sixty_percent_height);
        if(color != GREEN) continue;
        right_line_60_y = sixty_percent_height;
        right_line_60_x = w_i;
        break;
    }

    //Finding Left Line

    uint32_t left_line_50_x = 0;
    uint32_t left_line_50_y = 0;
    uint32_t left_line_60_x = 0;
    uint32_t left_line_60_y = 0;

    for(uint32_t w_i = 0; w_i < WIDTH; w_i++){
        color = getColor(w_i, middle_height);
        if(color != GREEN) continue;
        left_line_50_y = middle_height;
        left_line_50_x = w_i;
        break;
    }

    for(uint32_t w_i = 0; w_i < WIDTH; w_i++){
        color = getColor(w_i, sixty_percent_height);
        if(color != GREEN) continue;
        left_line_60_y = sixty_percent_height;
        left_line_60_x = w_i;
        break;
    }

    //Calculate slopes & intercepts
    float top_m = ((float)((float)top_line_50_y - (float)top_line_60_y)) / ((float)((float)middle_width - (float)sixty_percent_width));
    float top_b = (float)((float)top_line_50_y - (float)top_m * (float)(middle_width));

    float bottom_m = ((float)((float)bottom_line_50_y - (float)bottom_line_60_y)) / ((float)((float)middle_width - (float)sixty_percent_width));
    float bottom_b = (float)((float)bottom_line_50_y - (float)bottom_m * (float)(middle_width));

    float right_m = (float)((float)right_line_50_x - (float)right_line_60_x) / (float)((float)middle_height - (float)sixty_percent_height);
    float right_b = (float)right_line_50_x - right_m*((float)middle_height);

    float left_m = (float)((float)left_line_50_x - (float)left_line_60_x) / (float)((float)middle_height - (float)sixty_percent_height);
    float left_b = (float)left_line_50_x - left_m*((float)middle_height);

    //In case they are zero, cannot divide by zero.
    right_m += .00001;
    left_m += .00001;

    //Calculate corners

    float top_left_corner_x = ((-left_b / left_m) - top_b) / (top_m - (1/left_m));
    float top_left_corner_y = top_m * top_left_corner_x + top_b;

    float bottom_left_corner_x = ((-left_b / left_m) - bottom_b) / (bottom_m - (1/left_m));
    float bottom_left_corner_y = bottom_m * bottom_left_corner_x + bottom_b;

    float top_right_corner_x = ((-right_b / right_m) - top_b) / (top_m - (1/right_m));
    float top_right_corner_y = top_m * top_right_corner_x + top_b;

    float bottom_right_corner_x = ((-right_b / right_m) - bottom_b) / (bottom_m - (1/right_m));
    float bottom_right_corner_y = bottom_m * bottom_right_corner_x + bottom_b;

    float* affine_transform_matrix = calculate_m(bottom_right_corner_x,
                                                 bottom_right_corner_y,
                                                 top_right_corner_x,
                                                 top_right_corner_y,
                                                 bottom_left_corner_x,
                                                 bottom_left_corner_y,
                                                 top_left_corner_x,
                                                 top_left_corner_y);


    return top_line_50_y;
}

