/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <stdio.h>
#include <string>


extern int memo_counter_;

void _printf(const char *v) {
    printf("%s", v);
}

void memo_counter(int val) {
    memo_counter_ += val;
}

bool my_strcmp(char *v1, char *v2) {
    if(v1 == nullptr || v2 == nullptr) return false;
    if(v1[0] == 0 || v2[0] == 0) return false;
    int i;
    i = 0;
    while(v1[i] != 0 && v2[i] != 0) {
        if(v1[i] != v2[i]) return false;
        i++;
    }
    return true;
}


void write2(FILE *f, unsigned short v) {
    fwrite(&v, 1, 2, f);
}
void write4(FILE *f, unsigned int v) {
    fwrite(&v, 1, 4, f);    
}

void write3(FILE *f, unsigned char b, unsigned char g, unsigned char r) {
    fprintf(f, "%c%c%c", b, g, r);
}

void save_textura_to_BMP_file_(FILE *f, unsigned int *bitmap, int w, int h) {
    
    
    int i = 0, sz;
    
    sz = ((w*3) + (w % 4))*h;
    
    unsigned short bfType, bfReserved1, bfReserved2;
    unsigned int bfSize, bfOffBits;
    
    bfType = 0x4d42;
    bfSize = sz + 54;
    bfReserved1 = 0;
    bfReserved2 = 0;
    bfOffBits = 54;
    
    write2(f, bfType);
    write4(f, bfSize);
    write2(f, bfReserved1);
    write2(f, bfReserved2);
    write4(f, bfOffBits);
    
    unsigned int BITMAPINFO_ver = 40;
    
    write4(f, BITMAPINFO_ver);
    
    unsigned int biWidth = w;
    unsigned int biHeight = h;
    unsigned short biBitCount = 24;
    unsigned int biCompression = 0;
    unsigned int biSizeImage = sz;
    unsigned int biClrUsed = 0;
    unsigned int biClrImportant = 0;
    
    write4(f, biWidth);
    write4(f, biHeight);
    write2(f, 1);
    write2(f, biBitCount);
    write4(f, biCompression);
    write4(f, biSizeImage);
    write4(f, 1);
    write4(f, 1);
    write4(f, biClrUsed);
    write4(f, biClrImportant);
    int j, x, y;
    for (y = h - 1; y >= 0; y--) {
            j = 0;
            for (x = 0; x < w; x++) {

                unsigned int r, g, b;
                r = 0;
                g = 0;
                b = 0;
                b = bitmap[y*w+x] & 0xff;
                g = (bitmap[y*w+x] & 0xff00)>>8;
                r = (bitmap[y*w+x] & 0xff0000)>>16;
                
                
                write3(f, b, g, r);
                    
                    //i += 3;
                    j += 3;
            }
            j = w % 4;
            while(j>0) {
                fprintf(f, "%c", 0);
                j--;
            }
            i += j;
    };
}

bool file_exists(std::string &v) {
    FILE *f;
    f = fopen(v.c_str(), "rb");
    if(f == NULL) return false;
    fclose(f);
    return true;
}

std::string generate_new_filename_sprite() {

    std::string s;
    int i;
    i = 0;
    do 
    {
        i++;
        s = "sprite";
        s += std::to_string(i);
        s += ".bmp";
        
    } while(file_exists(s));
    
    return s;
}