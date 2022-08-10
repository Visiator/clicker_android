/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   tools.h
 * Author: smorodin
 *
 * Created on August 4, 2022, 5:35 PM
 */

#ifndef TOOLS_H
#define TOOLS_H

#define uint16_t unsigned short

void _printf(const char *v);
void memo_counter(int val);
bool my_strcmp(char *v1, char *v2);
void save_textura_to_BMP_file_(FILE *f, unsigned int *bitmap, int w, int h);
bool file_exists(std::string &v);
std::string generate_new_filename_sprite();

#endif /* TOOLS_H */

