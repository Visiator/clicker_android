/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <vector>
#include "font.h"
#include "gui.h"

uint16_t font_[] = {
258, 0, 4, 18,  0, 72, 
258, 1, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 2, 4, 18,  0, 72, 
258, 3, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 4, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 5, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 6, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 7, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 8, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 9, 4, 18,  0, 17, 3, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 1, 3, 12, 
258, 10, 4, 18,  0, 17, 3, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 1, 3, 12, 
258, 11, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 12, 4, 18,  0, 72, 
258, 13, 4, 18,  0, 72, 
258, 14, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 15, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 16, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 17, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 18, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 19, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 20, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 21, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 22, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 23, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 24, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 25, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 26, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 27, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 28, 4, 18,  0, 17, 3, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 1, 3, 12, 
258, 29, 4, 18,  0, 17, 3, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 1, 3, 12, 
258, 30, 4, 18,  0, 17, 3, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 1, 3, 12, 
258, 31, 4, 18,  0, 17, 3, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 1, 3, 12, 
258, 32, 4, 18,  0, 72, 
258, 33, 3, 18,  0, 10, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 5, 1, 13, 
258, 34, 4, 18,  0, 13, 1, 3, 2, 2, 1, 50, 
258, 35, 11, 18,  0, 37, 1, 3, 1, 6, 1, 2, 1, 7, 1, 2, 1, 6, 1, 3, 1, 4, 9, 4, 1, 2, 1, 7, 1, 2, 1, 4, 9, 4, 1, 2, 1, 7, 1, 2, 1, 6, 1, 3, 1, 49, 
258, 36, 9, 18,  0, 22, 1, 7, 3, 5, 1, 1, 1, 1, 1, 3, 1, 2, 1, 5, 1, 2, 1, 6, 1, 1, 1, 7, 3, 7, 1, 1, 1, 6, 1, 2, 1, 2, 1, 2, 1, 2, 1, 3, 1, 1, 1, 1, 1, 5, 3, 7, 1, 31, 
258, 37, 11, 18,  0, 34, 3, 4, 1, 2, 1, 3, 1, 2, 1, 3, 1, 3, 1, 1, 1, 4, 1, 3, 1, 1, 1, 4, 1, 3, 2, 6, 3, 1, 1, 1, 2, 6, 1, 1, 1, 2, 1, 4, 1, 2, 1, 2, 1, 4, 1, 2, 1, 2, 1, 3, 1, 3, 1, 2, 1, 3, 1, 4, 2, 3, 1, 42, 
258, 38, 9, 18,  0, 31, 2, 5, 2, 2, 1, 4, 1, 3, 1, 4, 1, 2, 2, 5, 2, 6, 1, 1, 1, 5, 1, 3, 1, 2, 2, 5, 2, 1, 1, 6, 1, 2, 1, 3, 2, 1, 1, 2, 3, 40, 
258, 39, 3, 18,  0, 10, 1, 2, 1, 2, 1, 37, 
258, 40, 4, 18,  0, 11, 1, 2, 1, 3, 1, 3, 1, 2, 1, 3, 1, 3, 1, 3, 1, 3, 1, 4, 1, 3, 1, 3, 1, 4, 1, 12, 
258, 41, 4, 18,  0, 12, 1, 4, 1, 3, 1, 3, 1, 4, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 2, 1, 3, 1, 2, 1, 11, 
258, 42, 7, 18,  0, 24, 1, 4, 1, 1, 1, 1, 1, 3, 3, 4, 1, 1, 1, 3, 1, 3, 1, 71, 
258, 43, 9, 18,  0, 49, 1, 8, 1, 8, 1, 5, 7, 5, 1, 8, 1, 8, 1, 58, 
258, 44, 3, 18,  0, 43, 1, 2, 1, 7, 
258, 45, 6, 18,  0, 55, 4, 49, 
258, 46, 3, 18,  0, 40, 1, 13, 
258, 47, 6, 18,  0, 22, 1, 5, 1, 4, 1, 5, 1, 4, 1, 5, 1, 5, 1, 4, 1, 5, 1, 4, 1, 5, 1, 29, 
258, 48, 9, 18,  0, 30, 4, 4, 1, 4, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 2, 1, 4, 1, 4, 4, 38, 
258, 49, 4, 18,  0, 14, 1, 2, 2, 1, 1, 1, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 17, 
258, 50, 8, 18,  0, 26, 4, 3, 1, 4, 1, 8, 1, 7, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 7, 7, 32, 
258, 51, 9, 18,  0, 29, 3, 4, 2, 3, 1, 9, 1, 8, 1, 7, 1, 6, 3, 9, 1, 9, 1, 8, 1, 1, 2, 4, 1, 4, 4, 39, 
258, 52, 9, 18,  0, 33, 1, 7, 2, 6, 1, 1, 1, 5, 1, 2, 1, 4, 1, 3, 1, 3, 1, 4, 1, 2, 1, 5, 1, 2, 8, 7, 1, 8, 1, 8, 1, 38, 
258, 53, 9, 18,  0, 28, 6, 3, 1, 8, 1, 8, 1, 8, 1, 1, 3, 4, 2, 3, 1, 9, 1, 8, 1, 8, 1, 2, 1, 4, 1, 4, 4, 39, 
258, 54, 9, 18,  0, 30, 4, 4, 1, 4, 1, 2, 1, 8, 1, 8, 1, 1, 4, 3, 2, 4, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 2, 1, 4, 1, 4, 4, 38, 
258, 55, 7, 18,  0, 22, 6, 6, 1, 5, 1, 6, 1, 5, 1, 6, 1, 5, 1, 6, 1, 5, 1, 6, 1, 5, 1, 33, 
258, 56, 9, 18,  0, 30, 3, 5, 1, 3, 1, 3, 1, 5, 1, 2, 1, 5, 1, 3, 1, 3, 1, 5, 4, 4, 1, 4, 1, 2, 1, 6, 1, 1, 1, 6, 1, 2, 1, 4, 1, 4, 4, 38, 
258, 57, 9, 18,  0, 30, 3, 5, 1, 3, 1, 3, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 3, 1, 3, 2, 4, 3, 1, 1, 8, 1, 8, 1, 3, 1, 3, 1, 5, 3, 39, 
258, 58, 3, 18,  0, 22, 1, 17, 1, 13, 
258, 59, 4, 18,  0, 30, 1, 23, 1, 3, 1, 13, 
258, 60, 7, 18,  0, 46, 1, 4, 2, 4, 1, 5, 2, 7, 2, 7, 1, 44, 
258, 61, 8, 18,  0, 65, 6, 10, 6, 57, 
258, 62, 7, 18,  0, 42, 2, 7, 2, 7, 1, 6, 2, 3, 2, 4, 1, 47, 
258, 63, 7, 18,  0, 22, 3, 3, 1, 3, 1, 7, 1, 6, 1, 6, 1, 5, 1, 4, 2, 5, 1, 6, 1, 13, 1, 32, 
258, 64, 12, 18,  0, 52, 4, 7, 1, 4, 2, 4, 1, 2, 2, 3, 1, 2, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 3, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 3, 1, 2, 1, 2, 1, 1, 1, 2, 2, 1, 1, 4, 1, 1, 2, 2, 1, 6, 1, 12, 4, 40, 
258, 65, 9, 18,  0, 30, 1, 8, 2, 7, 1, 1, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 4, 1, 4, 1, 4, 4, 4, 1, 4, 1, 2, 1, 6, 1, 1, 1, 6, 1, 37, 
258, 66, 9, 18,  0, 28, 5, 4, 1, 4, 1, 3, 1, 5, 1, 2, 1, 5, 1, 2, 1, 4, 1, 3, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 38, 
258, 67, 9, 18,  0, 30, 4, 4, 1, 4, 2, 1, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 9, 1, 4, 2, 3, 4, 38, 
258, 68, 10, 18,  0, 31, 6, 4, 1, 5, 1, 3, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 5, 1, 3, 6, 43, 
258, 69, 8, 18,  0, 25, 7, 1, 1, 7, 1, 7, 1, 7, 1, 7, 6, 2, 1, 7, 1, 7, 1, 7, 1, 7, 7, 32, 
258, 70, 8, 18,  0, 25, 7, 1, 1, 7, 1, 7, 1, 7, 1, 7, 6, 2, 1, 7, 1, 7, 1, 7, 1, 7, 1, 38, 
258, 71, 10, 18,  0, 33, 4, 5, 1, 4, 1, 3, 1, 9, 1, 9, 1, 9, 1, 3, 4, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 3, 1, 4, 1, 5, 4, 43, 
258, 72, 10, 18,  0, 31, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 8, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 41, 
258, 73, 3, 18,  0, 10, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 13, 
258, 74, 9, 18,  0, 31, 4, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 1, 1, 6, 1, 2, 1, 4, 1, 4, 4, 39, 
258, 75, 9, 18,  0, 28, 1, 6, 1, 1, 1, 5, 1, 2, 1, 4, 1, 3, 1, 3, 1, 4, 1, 2, 1, 5, 1, 1, 1, 6, 2, 1, 1, 5, 1, 3, 1, 4, 1, 4, 1, 3, 1, 5, 1, 2, 1, 6, 1, 36, 
258, 76, 7, 18,  0, 22, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 6, 28, 
258, 77, 12, 18,  0, 37, 1, 8, 1, 2, 2, 6, 2, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 3, 1, 1, 1, 2, 1, 2, 1, 3, 2, 3, 1, 2, 1, 4, 1, 3, 1, 2, 1, 8, 1, 49, 
258, 78, 10, 18,  0, 31, 1, 6, 1, 2, 2, 5, 1, 2, 1, 1, 1, 4, 1, 2, 1, 1, 1, 4, 1, 2, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1, 2, 1, 3, 1, 2, 1, 2, 1, 4, 1, 1, 1, 2, 1, 4, 1, 1, 1, 2, 1, 5, 2, 2, 1, 6, 1, 41, 
258, 79, 10, 18,  0, 33, 4, 5, 1, 4, 1, 3, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 3, 1, 4, 1, 5, 4, 43, 
258, 80, 9, 18,  0, 28, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 3, 1, 8, 1, 8, 1, 8, 1, 43, 
258, 81, 10, 18,  0, 33, 4, 5, 1, 4, 1, 3, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 4, 1, 1, 1, 3, 1, 4, 2, 4, 4, 1, 1, 41, 
258, 82, 9, 18,  0, 28, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 3, 1, 2, 1, 5, 1, 3, 1, 4, 1, 4, 1, 3, 1, 5, 1, 37, 
258, 83, 9, 18,  0, 30, 3, 5, 1, 3, 1, 3, 1, 8, 1, 9, 1, 9, 3, 9, 1, 9, 1, 2, 1, 5, 1, 3, 1, 3, 1, 5, 3, 39, 
258, 84, 8, 18,  0, 25, 7, 4, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 35, 
258, 85, 10, 18,  0, 31, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 3, 1, 4, 1, 5, 4, 43, 
258, 86, 9, 18,  0, 27, 1, 6, 1, 1, 1, 6, 1, 2, 1, 4, 1, 3, 1, 4, 1, 3, 1, 4, 1, 4, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 2, 8, 1, 40, 
258, 87, 14, 18,  0, 42, 1, 11, 1, 1, 1, 11, 1, 1, 1, 5, 1, 5, 1, 2, 1, 4, 1, 4, 1, 3, 1, 3, 1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1, 3, 1, 4, 1, 1, 1, 3, 1, 1, 1, 5, 1, 1, 1, 3, 1, 1, 1, 5, 1, 1, 1, 3, 1, 1, 1, 5, 2, 5, 2, 6, 1, 5, 1, 60, 
258, 88, 8, 18,  0, 25, 1, 5, 1, 2, 1, 3, 1, 3, 1, 3, 1, 4, 1, 1, 1, 5, 1, 1, 1, 6, 1, 6, 1, 1, 1, 5, 1, 1, 1, 4, 1, 3, 1, 3, 1, 3, 1, 2, 1, 5, 1, 32, 
258, 89, 8, 18,  0, 24, 1, 8, 1, 5, 1, 2, 1, 4, 1, 2, 1, 3, 1, 4, 1, 1, 1, 5, 1, 1, 1, 6, 1, 7, 1, 7, 1, 7, 1, 7, 1, 35, 
258, 90, 8, 18,  0, 25, 7, 7, 1, 6, 1, 6, 1, 7, 1, 6, 1, 6, 1, 7, 1, 6, 1, 6, 1, 7, 7, 32, 
258, 91, 4, 18,  0, 9, 2, 2, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 2, 9, 
258, 92, 6, 18,  0, 18, 1, 5, 1, 6, 1, 5, 1, 5, 1, 6, 1, 5, 1, 6, 1, 5, 1, 5, 1, 6, 1, 5, 1, 19, 
258, 93, 4, 18,  0, 9, 2, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 2, 2, 9, 
258, 94, 8, 18,  0, 27, 1, 7, 2, 5, 1, 2, 1, 3, 1, 3, 1, 3, 1, 4, 1, 81, 
258, 95, 9, 18,  0, 127, 7, 28, 
258, 96, 3, 18,  0, 4, 1, 2, 1, 46, 
258, 97, 9, 18,  0, 30, 1, 8, 2, 7, 1, 1, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 4, 1, 4, 1, 4, 4, 4, 1, 4, 1, 2, 1, 6, 1, 1, 1, 6, 1, 37, 
258, 98, 9, 18,  0, 28, 5, 4, 1, 4, 1, 3, 1, 5, 1, 2, 1, 5, 1, 2, 1, 4, 1, 3, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 38, 
258, 99, 9, 18,  0, 30, 4, 4, 1, 4, 2, 1, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 9, 1, 4, 2, 3, 4, 38, 
258, 100, 10, 18,  0, 31, 6, 4, 1, 5, 1, 3, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 5, 1, 3, 6, 43, 
258, 101, 8, 18,  0, 25, 7, 1, 1, 7, 1, 7, 1, 7, 1, 7, 6, 2, 1, 7, 1, 7, 1, 7, 1, 7, 7, 32, 
258, 102, 8, 18,  0, 25, 7, 1, 1, 7, 1, 7, 1, 7, 1, 7, 6, 2, 1, 7, 1, 7, 1, 7, 1, 7, 1, 38, 
258, 103, 10, 18,  0, 33, 4, 5, 1, 4, 1, 3, 1, 9, 1, 9, 1, 9, 1, 3, 4, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 3, 1, 4, 1, 5, 4, 43, 
258, 104, 10, 18,  0, 31, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 8, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 41, 
258, 105, 3, 18,  0, 10, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 13, 
258, 106, 9, 18,  0, 31, 4, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 1, 1, 6, 1, 2, 1, 4, 1, 4, 4, 39, 
258, 107, 9, 18,  0, 28, 1, 6, 1, 1, 1, 5, 1, 2, 1, 4, 1, 3, 1, 3, 1, 4, 1, 2, 1, 5, 1, 1, 1, 6, 2, 1, 1, 5, 1, 3, 1, 4, 1, 4, 1, 3, 1, 5, 1, 2, 1, 6, 1, 36, 
258, 108, 7, 18,  0, 22, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 6, 28, 
258, 109, 12, 18,  0, 37, 1, 8, 1, 2, 2, 6, 2, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 3, 1, 1, 1, 2, 1, 2, 1, 3, 2, 3, 1, 2, 1, 4, 1, 3, 1, 2, 1, 8, 1, 49, 
258, 110, 10, 18,  0, 31, 1, 6, 1, 2, 2, 5, 1, 2, 1, 1, 1, 4, 1, 2, 1, 1, 1, 4, 1, 2, 1, 2, 1, 3, 1, 2, 1, 3, 1, 2, 1, 2, 1, 3, 1, 2, 1, 2, 1, 4, 1, 1, 1, 2, 1, 4, 1, 1, 1, 2, 1, 5, 2, 2, 1, 6, 1, 41, 
258, 111, 10, 18,  0, 33, 4, 5, 1, 4, 1, 3, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 3, 1, 4, 1, 5, 4, 43, 
258, 112, 9, 18,  0, 28, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 3, 1, 8, 1, 8, 1, 8, 1, 43, 
258, 113, 10, 18,  0, 33, 4, 5, 1, 4, 1, 3, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 4, 1, 1, 1, 3, 1, 4, 2, 4, 4, 1, 1, 41, 
258, 114, 9, 18,  0, 28, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 3, 1, 2, 1, 5, 1, 3, 1, 4, 1, 4, 1, 3, 1, 5, 1, 37, 
258, 115, 9, 18,  0, 30, 3, 5, 1, 3, 1, 3, 1, 8, 1, 9, 1, 9, 3, 9, 1, 9, 1, 2, 1, 5, 1, 3, 1, 3, 1, 5, 3, 39, 
258, 116, 8, 18,  0, 25, 7, 4, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 35, 
258, 117, 10, 18,  0, 31, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 3, 1, 4, 1, 5, 4, 43, 
258, 118, 9, 18,  0, 27, 1, 6, 1, 1, 1, 6, 1, 2, 1, 4, 1, 3, 1, 4, 1, 3, 1, 4, 1, 4, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 2, 8, 1, 40, 
258, 119, 14, 18,  0, 42, 1, 11, 1, 1, 1, 11, 1, 1, 1, 5, 1, 5, 1, 2, 1, 4, 1, 4, 1, 3, 1, 3, 1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1, 3, 1, 4, 1, 1, 1, 3, 1, 1, 1, 5, 1, 1, 1, 3, 1, 1, 1, 5, 1, 1, 1, 3, 1, 1, 1, 5, 2, 5, 2, 6, 1, 5, 1, 60, 
258, 120, 8, 18,  0, 25, 1, 5, 1, 2, 1, 3, 1, 3, 1, 3, 1, 4, 1, 1, 1, 5, 1, 1, 1, 6, 1, 6, 1, 1, 1, 5, 1, 1, 1, 4, 1, 3, 1, 3, 1, 3, 1, 2, 1, 5, 1, 32, 
258, 121, 8, 18,  0, 24, 1, 8, 1, 5, 1, 2, 1, 4, 1, 2, 1, 3, 1, 4, 1, 1, 1, 5, 1, 1, 1, 6, 1, 7, 1, 7, 1, 7, 1, 7, 1, 35, 
258, 122, 8, 18,  0, 25, 7, 7, 1, 6, 1, 6, 1, 7, 1, 6, 1, 6, 1, 7, 1, 6, 1, 6, 1, 7, 7, 32, 
258, 123, 4, 18,  0, 11, 1, 2, 1, 3, 1, 3, 1, 3, 1, 3, 1, 2, 1, 2, 2, 4, 1, 3, 1, 3, 1, 3, 1, 3, 1, 4, 1, 8, 
258, 124, 3, 18,  0, 10, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 4, 
258, 125, 4, 18,  0, 9, 1, 4, 1, 3, 1, 3, 1, 3, 1, 3, 1, 4, 1, 3, 1, 2, 1, 3, 1, 3, 1, 3, 1, 3, 1, 2, 1, 10, 
258, 126, 8, 18,  0, 58, 1, 3, 1, 2, 1, 1, 2, 1, 1, 6, 1, 66, 
258, 127, 4, 18,  0, 16, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 12, 
258, 128, 4, 18,  0, 72, 
258, 129, 4, 18,  0, 72, 
258, 130, 3, 18,  0, 43, 1, 2, 1, 7, 
258, 131, 4, 18,  0, 72, 
258, 132, 5, 18,  0, 71, 1, 1, 1, 2, 1, 1, 1, 11, 
258, 133, 9, 18,  0, 118, 1, 2, 1, 2, 1, 37, 
258, 134, 7, 18,  0, 24, 1, 6, 1, 6, 1, 3, 7, 3, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 6, 1, 17, 
258, 135, 8, 18,  0, 28, 1, 7, 1, 7, 1, 4, 7, 4, 1, 7, 1, 7, 1, 7, 1, 7, 1, 4, 7, 4, 1, 7, 1, 7, 1, 19, 
258, 136, 9, 18,  0, 30, 4, 4, 1, 4, 1, 2, 1, 8, 1, 7, 6, 4, 1, 7, 6, 4, 1, 8, 1, 9, 1, 4, 1, 4, 4, 38, 
258, 137, 15, 18,  0, 46, 3, 4, 1, 6, 1, 3, 1, 2, 1, 7, 1, 3, 1, 1, 1, 8, 1, 3, 1, 1, 1, 8, 1, 3, 2, 10, 3, 1, 1, 1, 2, 2, 3, 5, 1, 1, 1, 2, 2, 3, 1, 3, 1, 2, 1, 2, 2, 3, 1, 3, 1, 2, 1, 2, 2, 3, 1, 2, 1, 3, 1, 2, 2, 3, 1, 2, 1, 4, 2, 2, 3, 2, 1, 58, 
258, 138, 4, 18,  0, 72, 
258, 139, 4, 18,  0, 30, 1, 2, 1, 3, 1, 3, 1, 4, 1, 25, 
258, 140, 4, 18,  0, 72, 
258, 141, 4, 18,  0, 72, 
258, 142, 4, 18,  0, 72, 
258, 143, 4, 18,  0, 72, 
258, 144, 4, 18,  0, 72, 
258, 145, 3, 18,  0, 10, 1, 2, 1, 2, 1, 37, 
258, 146, 3, 18,  0, 10, 1, 2, 1, 2, 1, 37, 
258, 147, 5, 18,  0, 16, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 61, 
258, 148, 5, 18,  0, 16, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 61, 
258, 149, 5, 18,  0, 37, 1, 3, 3, 3, 1, 42, 
258, 150, 9, 18,  0, 49, 1, 8, 1, 8, 1, 5, 7, 5, 1, 8, 1, 8, 1, 58, 
258, 151, 15, 18,  0, 136, 13, 121, 
258, 152, 1, 18,  0, 18, 
258, 153, 12, 18,  0, 36, 5, 1, 1, 3, 1, 3, 1, 3, 2, 1, 2, 3, 1, 3, 2, 1, 2, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 3, 1, 109, 
258, 154, 4, 18,  0, 72, 
258, 155, 4, 18,  0, 29, 1, 4, 1, 3, 1, 3, 1, 2, 1, 26, 
258, 156, 4, 18,  0, 72, 
258, 157, 4, 18,  0, 72, 
258, 158, 4, 18,  0, 72, 
258, 159, 4, 18,  0, 72, 
258, 160, 4, 18,  0, 72, 
258, 161, 4, 18,  0, 72, 
258, 162, 4, 18,  0, 72, 
258, 163, 4, 18,  0, 72, 
258, 164, 9, 18,  0, 46, 1, 1, 3, 1, 1, 3, 1, 3, 1, 3, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 3, 1, 3, 1, 4, 1, 3, 1, 3, 1, 1, 3, 1, 1, 46, 
258, 165, 4, 18,  0, 72, 
258, 166, 3, 18,  0, 13, 1, 2, 1, 2, 1, 2, 1, 2, 1, 8, 1, 2, 1, 2, 1, 2, 1, 2, 1, 7, 
258, 167, 7, 18,  0, 24, 2, 3, 2, 2, 1, 2, 1, 6, 1, 7, 2, 4, 1, 2, 1, 3, 1, 3, 1, 3, 1, 2, 1, 4, 2, 7, 1, 6, 1, 2, 1, 3, 1, 3, 3, 16, 
258, 168, 8, 18,  0, 26, 5, 2, 1, 7, 1, 7, 1, 7, 1, 7, 6, 2, 1, 7, 1, 7, 1, 7, 1, 7, 6, 33, 
258, 169, 12, 18,  0, 40, 5, 6, 1, 5, 1, 4, 1, 2, 3, 2, 1, 2, 1, 2, 1, 3, 1, 1, 1, 2, 1, 1, 1, 7, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 7, 1, 1, 1, 2, 1, 2, 2, 1, 1, 3, 1, 2, 2, 3, 1, 4, 1, 4, 2, 6, 4, 52, 
258, 170, 4, 18,  0, 72, 
258, 171, 6, 18,  0, 43, 1, 2, 1, 2, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 2, 1, 37, 
258, 172, 9, 18,  0, 73, 7, 8, 1, 8, 1, 8, 1, 55, 
258, 173, 5, 18,  0, 46, 3, 41, 
258, 174, 12, 18,  0, 40, 5, 6, 1, 5, 1, 4, 1, 2, 3, 2, 1, 2, 1, 2, 1, 3, 1, 2, 1, 1, 1, 2, 1, 3, 1, 2, 1, 1, 1, 2, 4, 3, 1, 1, 1, 2, 1, 2, 1, 3, 1, 2, 1, 1, 1, 2, 1, 2, 1, 3, 1, 4, 1, 2, 1, 4, 1, 5, 1, 6, 5, 51, 
258, 175, 4, 18,  0, 72, 
258, 176, 5, 18,  0, 17, 1, 3, 1, 1, 1, 2, 1, 1, 1, 3, 1, 57, 
258, 177, 9, 18,  0, 40, 1, 8, 1, 8, 1, 5, 7, 5, 1, 8, 1, 8, 1, 14, 7, 46, 
258, 178, 4, 18,  0, 72, 
258, 179, 4, 18,  0, 72, 
258, 180, 4, 18,  0, 72, 
258, 181, 8, 18,  0, 49, 1, 4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 1, 4, 1, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 2, 1, 7, 1, 7, 1, 14, 
258, 182, 8, 18,  0, 27, 4, 3, 3, 1, 1, 2, 4, 1, 1, 2, 4, 1, 1, 2, 4, 1, 1, 2, 4, 1, 1, 4, 2, 1, 1, 5, 1, 1, 1, 5, 1, 1, 1, 5, 1, 1, 1, 5, 1, 1, 1, 5, 1, 1, 1, 5, 1, 1, 1, 17, 
258, 183, 3, 18,  0, 28, 1, 25, 
258, 184, 8, 18,  0, 26, 5, 2, 1, 7, 1, 7, 1, 7, 1, 7, 6, 2, 1, 7, 1, 7, 1, 7, 1, 7, 6, 33, 
258, 185, 4, 18,  0, 72, 
258, 186, 4, 18,  0, 72, 
258, 187, 6, 18,  0, 43, 1, 2, 1, 3, 1, 1, 1, 3, 1, 1, 1, 3, 1, 1, 1, 2, 1, 2, 1, 37, 
258, 188, 4, 18,  0, 72, 
258, 189, 4, 18,  0, 72, 
258, 190, 4, 18,  0, 72, 
258, 191, 4, 18,  0, 72, 
258, 192, 9, 18,  0, 30, 1, 8, 2, 7, 1, 1, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 4, 1, 4, 1, 4, 4, 4, 1, 4, 1, 2, 1, 6, 1, 1, 1, 6, 1, 37, 
258, 193, 9, 18,  0, 28, 7, 2, 1, 8, 1, 8, 1, 8, 1, 8, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 38, 
258, 194, 9, 18,  0, 28, 5, 4, 1, 4, 1, 3, 1, 5, 1, 2, 1, 5, 1, 2, 1, 4, 1, 3, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 38, 
258, 195, 8, 18,  0, 25, 7, 1, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 38, 
258, 196, 10, 18,  0, 33, 6, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 3, 1, 5, 1, 3, 1, 5, 1, 3, 1, 5, 1, 3, 1, 5, 1, 1, 11, 9, 1, 29, 
258, 197, 8, 18,  0, 25, 7, 1, 1, 7, 1, 7, 1, 7, 1, 7, 6, 2, 1, 7, 1, 7, 1, 7, 1, 7, 7, 32, 
258, 198, 13, 18,  0, 39, 1, 5, 1, 5, 1, 1, 1, 4, 1, 4, 1, 3, 1, 3, 1, 3, 1, 5, 1, 2, 1, 2, 1, 7, 1, 1, 1, 1, 1, 8, 5, 7, 1, 2, 1, 2, 1, 6, 1, 2, 1, 2, 1, 5, 1, 3, 1, 3, 1, 3, 1, 4, 1, 4, 1, 1, 1, 5, 1, 5, 1, 52, 
258, 199, 8, 18,  0, 26, 3, 4, 1, 3, 1, 8, 1, 6, 1, 7, 1, 5, 2, 8, 1, 8, 1, 7, 1, 1, 1, 4, 1, 3, 4, 35, 
258, 200, 10, 18,  0, 31, 1, 6, 1, 2, 1, 5, 2, 2, 1, 4, 1, 1, 1, 2, 1, 4, 1, 1, 1, 2, 1, 3, 1, 2, 1, 2, 1, 3, 1, 2, 1, 2, 1, 2, 1, 3, 1, 2, 1, 1, 1, 4, 1, 2, 1, 1, 1, 4, 1, 2, 2, 5, 1, 2, 1, 6, 1, 41, 
258, 201, 10, 18,  0, 3, 1, 2, 1, 7, 2, 15, 1, 6, 1, 2, 1, 5, 2, 2, 1, 4, 1, 1, 1, 2, 1, 4, 1, 1, 1, 2, 1, 3, 1, 2, 1, 2, 1, 3, 1, 2, 1, 2, 1, 2, 1, 3, 1, 2, 1, 1, 1, 4, 1, 2, 1, 1, 1, 4, 1, 2, 2, 5, 1, 2, 1, 6, 1, 41, 
258, 202, 9, 18,  0, 28, 1, 6, 1, 1, 1, 5, 1, 2, 1, 4, 1, 3, 1, 3, 1, 4, 1, 2, 1, 5, 1, 1, 1, 6, 2, 1, 1, 5, 1, 3, 1, 4, 1, 4, 1, 3, 1, 5, 1, 2, 1, 6, 1, 36, 
258, 203, 10, 18,  0, 33, 6, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 3, 1, 5, 1, 3, 1, 5, 1, 3, 1, 5, 1, 3, 1, 5, 1, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 7, 1, 41, 
258, 204, 12, 18,  0, 37, 1, 8, 1, 2, 2, 6, 2, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 3, 1, 1, 1, 2, 1, 2, 1, 3, 2, 3, 1, 2, 1, 4, 1, 3, 1, 2, 1, 8, 1, 49, 
258, 205, 10, 18,  0, 31, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 8, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 41, 
258, 206, 10, 18,  0, 33, 4, 5, 1, 4, 1, 3, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 3, 1, 4, 1, 5, 4, 43, 
258, 207, 10, 18,  0, 31, 8, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 41, 
258, 208, 9, 18,  0, 28, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 3, 1, 8, 1, 8, 1, 8, 1, 43, 
258, 209, 9, 18,  0, 30, 4, 4, 1, 4, 2, 1, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 9, 1, 4, 2, 3, 4, 38, 
258, 210, 8, 18,  0, 25, 7, 4, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 35, 
258, 211, 8, 18,  0, 24, 1, 5, 1, 1, 1, 5, 1, 2, 1, 3, 1, 3, 1, 3, 1, 4, 1, 1, 1, 5, 1, 1, 1, 6, 2, 6, 1, 7, 1, 6, 1, 7, 1, 37, 
258, 212, 11, 18,  0, 38, 1, 8, 5, 5, 1, 2, 1, 2, 1, 3, 1, 3, 1, 3, 1, 2, 1, 3, 1, 3, 1, 2, 1, 3, 1, 3, 1, 2, 1, 3, 1, 3, 1, 2, 1, 3, 1, 3, 1, 3, 1, 2, 1, 2, 1, 5, 5, 8, 1, 49, 
258, 213, 8, 18,  0, 25, 1, 5, 1, 2, 1, 3, 1, 3, 1, 3, 1, 4, 1, 1, 1, 5, 1, 1, 1, 6, 1, 6, 1, 1, 1, 5, 1, 1, 1, 4, 1, 3, 1, 3, 1, 3, 1, 2, 1, 5, 1, 32, 
258, 214, 10, 18,  0, 31, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 9, 40, 
258, 215, 9, 18,  0, 28, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 3, 1, 3, 2, 4, 3, 1, 1, 8, 1, 8, 1, 8, 1, 37, 
258, 216, 13, 18,  0, 40, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 11, 53, 
258, 217, 13, 18,  0, 40, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 12, 52, 
258, 218, 10, 18,  0, 30, 3, 9, 1, 9, 1, 9, 1, 9, 1, 9, 6, 4, 1, 5, 1, 3, 1, 6, 1, 2, 1, 6, 1, 2, 1, 5, 1, 3, 6, 42, 
258, 219, 12, 18,  0, 37, 1, 8, 1, 2, 1, 8, 1, 2, 1, 8, 1, 2, 1, 8, 1, 2, 1, 8, 1, 2, 6, 3, 1, 2, 1, 5, 1, 2, 1, 2, 1, 6, 1, 1, 1, 2, 1, 6, 1, 1, 1, 2, 1, 5, 1, 2, 1, 2, 6, 3, 1, 49, 
258, 220, 9, 18,  0, 28, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 38, 
258, 221, 9, 18,  0, 29, 4, 3, 2, 4, 1, 9, 1, 8, 1, 8, 1, 3, 6, 8, 1, 8, 1, 8, 1, 1, 2, 4, 1, 4, 4, 39, 
258, 222, 14, 18,  0, 43, 1, 5, 3, 5, 1, 3, 2, 3, 2, 3, 1, 2, 1, 7, 1, 2, 1, 2, 1, 7, 1, 2, 1, 2, 1, 7, 1, 2, 4, 7, 1, 2, 1, 2, 1, 7, 1, 2, 1, 2, 1, 7, 1, 2, 1, 2, 1, 7, 1, 2, 1, 3, 1, 4, 2, 3, 1, 4, 4, 60, 
258, 223, 9, 18,  0, 30, 5, 3, 1, 4, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 3, 1, 4, 1, 4, 5, 5, 1, 2, 1, 4, 1, 3, 1, 3, 1, 4, 1, 2, 1, 5, 1, 37, 
258, 224, 9, 18,  0, 30, 1, 8, 2, 7, 1, 1, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 4, 1, 4, 1, 4, 4, 4, 1, 4, 1, 2, 1, 6, 1, 1, 1, 6, 1, 37, 
258, 225, 9, 18,  0, 28, 7, 2, 1, 8, 1, 8, 1, 8, 1, 8, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 38, 
258, 226, 9, 18,  0, 28, 5, 4, 1, 4, 1, 3, 1, 5, 1, 2, 1, 5, 1, 2, 1, 4, 1, 3, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 38, 
258, 227, 8, 18,  0, 25, 7, 1, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 38, 
258, 228, 10, 18,  0, 34, 1, 9, 2, 8, 1, 1, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 5, 1, 4, 1, 4, 1, 4, 1, 4, 1, 4, 1, 3, 1, 6, 1, 1, 11, 8, 2, 8, 1, 20, 
258, 229, 8, 18,  0, 25, 7, 1, 1, 7, 1, 7, 1, 7, 1, 7, 6, 2, 1, 7, 1, 7, 1, 7, 1, 7, 7, 32, 
258, 230, 13, 18,  0, 39, 1, 5, 1, 5, 1, 1, 1, 4, 1, 4, 1, 3, 1, 3, 1, 3, 1, 5, 1, 2, 1, 2, 1, 7, 1, 1, 1, 1, 1, 8, 5, 7, 1, 2, 1, 2, 1, 6, 1, 2, 1, 2, 1, 5, 1, 3, 1, 3, 1, 3, 1, 4, 1, 4, 1, 1, 1, 5, 1, 5, 1, 52, 
258, 231, 8, 18,  0, 26, 3, 4, 1, 3, 1, 8, 1, 6, 1, 7, 1, 5, 2, 8, 1, 8, 1, 7, 1, 1, 1, 4, 1, 3, 4, 35, 
258, 232, 10, 18,  0, 31, 1, 6, 1, 2, 1, 5, 2, 2, 1, 4, 1, 1, 1, 2, 1, 4, 1, 1, 1, 2, 1, 3, 1, 2, 1, 2, 1, 3, 1, 2, 1, 2, 1, 2, 1, 3, 1, 2, 1, 1, 1, 4, 1, 2, 1, 1, 1, 4, 1, 2, 2, 5, 1, 2, 1, 6, 1, 41, 
258, 233, 10, 18,  0, 3, 1, 2, 1, 7, 2, 15, 1, 6, 1, 2, 1, 5, 2, 2, 1, 4, 1, 1, 1, 2, 1, 4, 1, 1, 1, 2, 1, 3, 1, 2, 1, 2, 1, 3, 1, 2, 1, 2, 1, 2, 1, 3, 1, 2, 1, 1, 1, 4, 1, 2, 1, 1, 1, 4, 1, 2, 2, 5, 1, 2, 1, 6, 1, 41, 
258, 234, 9, 18,  0, 28, 1, 6, 1, 1, 1, 5, 1, 2, 1, 4, 1, 3, 1, 3, 1, 4, 1, 2, 1, 5, 1, 1, 1, 6, 2, 1, 1, 5, 1, 3, 1, 4, 1, 4, 1, 3, 1, 5, 1, 2, 1, 6, 1, 36, 
258, 235, 9, 18,  0, 30, 1, 8, 2, 7, 1, 1, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 4, 1, 4, 1, 3, 1, 4, 1, 3, 1, 4, 1, 2, 1, 6, 1, 1, 1, 6, 1, 37, 
258, 236, 12, 18,  0, 37, 1, 8, 1, 2, 2, 6, 2, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 4, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 3, 1, 1, 1, 2, 1, 2, 1, 3, 2, 3, 1, 2, 1, 4, 1, 3, 1, 2, 1, 8, 1, 49, 
258, 237, 10, 18,  0, 31, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 8, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 41, 
258, 238, 10, 18,  0, 33, 4, 5, 1, 4, 1, 3, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 3, 1, 4, 1, 5, 4, 43, 
258, 239, 10, 18,  0, 31, 8, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 41, 
258, 240, 9, 18,  0, 28, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 3, 1, 8, 1, 8, 1, 8, 1, 43, 
258, 241, 9, 18,  0, 30, 4, 4, 1, 4, 2, 1, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 9, 1, 4, 2, 3, 4, 38, 
258, 242, 8, 18,  0, 25, 7, 4, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 1, 35, 
258, 243, 8, 18,  0, 24, 1, 5, 1, 1, 1, 5, 1, 2, 1, 3, 1, 3, 1, 3, 1, 4, 1, 1, 1, 5, 1, 1, 1, 6, 2, 6, 1, 7, 1, 6, 1, 7, 1, 37, 
258, 244, 11, 18,  0, 38, 1, 8, 5, 5, 1, 2, 1, 2, 1, 3, 1, 3, 1, 3, 1, 2, 1, 3, 1, 3, 1, 2, 1, 3, 1, 3, 1, 2, 1, 3, 1, 3, 1, 2, 1, 3, 1, 3, 1, 3, 1, 2, 1, 2, 1, 5, 5, 8, 1, 49, 
258, 245, 8, 18,  0, 25, 1, 5, 1, 2, 1, 3, 1, 3, 1, 3, 1, 4, 1, 1, 1, 5, 1, 1, 1, 6, 1, 6, 1, 1, 1, 5, 1, 1, 1, 4, 1, 3, 1, 3, 1, 3, 1, 2, 1, 5, 1, 32, 
258, 246, 10, 18,  0, 31, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 1, 6, 1, 2, 9, 40, 
258, 247, 9, 18,  0, 28, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 3, 1, 3, 2, 4, 3, 1, 1, 8, 1, 8, 1, 8, 1, 37, 
258, 248, 13, 18,  0, 40, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 11, 53, 
258, 249, 13, 18,  0, 40, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 1, 4, 1, 4, 1, 2, 12, 52, 
258, 250, 10, 18,  0, 30, 3, 9, 1, 9, 1, 9, 1, 9, 1, 9, 6, 4, 1, 5, 1, 3, 1, 6, 1, 2, 1, 6, 1, 2, 1, 5, 1, 3, 6, 42, 
258, 251, 12, 18,  0, 37, 1, 8, 1, 2, 1, 8, 1, 2, 1, 8, 1, 2, 1, 8, 1, 2, 1, 8, 1, 2, 6, 3, 1, 2, 1, 5, 1, 2, 1, 2, 1, 6, 1, 1, 1, 2, 1, 6, 1, 1, 1, 2, 1, 5, 1, 2, 1, 2, 6, 3, 1, 49, 
258, 252, 9, 18,  0, 28, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 6, 3, 1, 5, 1, 2, 1, 6, 1, 1, 1, 6, 1, 1, 1, 5, 1, 2, 6, 38, 
258, 253, 9, 18,  0, 29, 4, 3, 2, 4, 1, 9, 1, 8, 1, 8, 1, 3, 6, 8, 1, 8, 1, 8, 1, 1, 2, 4, 1, 4, 4, 39, 
258, 254, 14, 18,  0, 43, 1, 5, 3, 5, 1, 3, 2, 3, 2, 3, 1, 2, 1, 7, 1, 2, 1, 2, 1, 7, 1, 2, 1, 2, 1, 7, 1, 2, 4, 7, 1, 2, 1, 2, 1, 7, 1, 2, 1, 2, 1, 7, 1, 2, 1, 2, 1, 7, 1, 2, 1, 3, 1, 4, 2, 3, 1, 4, 4, 60, 
258, 255, 9, 18,  0, 30, 5, 3, 1, 4, 1, 2, 1, 5, 1, 2, 1, 5, 1, 2, 1, 5, 1, 3, 1, 4, 1, 4, 5, 5, 1, 2, 1, 4, 1, 3, 1, 3, 1, 4, 1, 2, 1, 5, 1, 37, 
256 };

int BUKVA::paint(SCREEN &screen, int x, int y, uint32_t color) {

    if(x + this->w >= screen.w || x < 0 ||
       y + this->h >= screen.h || y < 0 ) return 0;
            
    int i,j,k;


    unsigned int col;

    i = 0;
    k = 0;
    while(i<h)
    {
      j = 0;
      while(j < w) {
        if(buf[k++] == '1') {  screen.buffer[(i+y)*screen.w +j+x] = color;  } 
        else {   };
        j++;
      };
      i++;
    };

    return w;
}


bool FONT::set_from_buffer_LZ(uint16_t *buf) {
    
  if(buf == NULL) return false;

  int i,j,k, idx, w, h, len, pix, idx_next;

  idx = 0;
  idx_next = 0;

  i = 0;

  while( buf[i] == 258 )
  {
    len = 0;
    if( buf[i] != 258 ) {
      return false;
    };
    i++;
    idx = buf[i];
    if( idx != idx_next)
    {
      return false;
    };


    idx_next++;
    if( idx < 0 || idx >= 256 ) {
      return false;
    };
    i++;
    w = buf[i];
    i++;
    h = buf[i];
    i++;
    pix = buf[i];
    i++;

    if( w == 0 )
    {
      i++;
    }
    else
    {
    //Form1->Memo2->Lines->Add( String(w) + ":"  + String(h) + " " + String(pix) + " - " + String(idx) );

    //printf("bukva init %d %d %d\n", w, h, idx);
    //bukva[idx].init(w, h, idx);

        bukva.insert(std::make_pair(idx, BUKVA(idx, w, h, buf+i)) );

    len = 0;
    while( len < w*h )
    {
      //printf("  %d set_len %d %d\n", idx, len, pix);
      //bukva[idx].set_len(len, buf[i], pix);
        
        
      if(pix == 0) { pix = 1; } else { pix = 0; };
      len += buf[i];


      i++;

    };

    if(len != w*h )
    {
      return false;
    };
    };
  };

  return true;
};


void FONTS::add_new_from_buffer(unsigned short *buf) {
    FONT f{"arial", 12, buf};
    
    list.push_back(std::move(f));
    int i=9;
}

void FONTS::init() {
    add_new_from_buffer(font_);
}

void FONTS::print(SCREEN &screen, int x, int y, const char *font_name, int font_size, std::string& txt, unsigned int color) {
    
    int i, w;
    i = 0;
    w = 0;
    while(txt[i] != 0) {
        w += list[0].bukva.find((int)txt[i])->second.paint(screen, x+w, y, color);
        i++;
    };
}

int FONTS::text_height(const char *font_name, int font_size) {
    return list[0].bukva.find(0x33)->second.h;
}

int FONTS::text_width(const char *font_name, int font_size, std::string& txt) {
    int w, i;
    w = 0;
    i = 0;
    while(txt[i] != 0) {
        w += list[0].bukva.find((int)txt[i])->second.w;
        i++;
    }
    return w;
}