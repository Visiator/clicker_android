/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "gui.h"

extern FONTS fonts;

void RECTANGLE::paint(SCREEN &screen) {
    if(is_visible == false) return;
    if(x < 0 || x+w >= screen.w ||
       y < 0 || y+h >= screen.h) {        
        return;
    }
    
    unsigned int bg = bg_color;
    if(is_pressed) {
        bg = bg_color_pressed;
    }
    
    screen.line_h(x, y, w, border_color);
    screen.line_h(x, y+h-1, w, border_color);
    
    screen.line_v(x, y, h, border_color);
    screen.line_v(x+w-1, y, h, border_color);
    
    screen.fill(x+1, y+1, w-2, h-2, bg);
    
    int ww, hh;
    ww = w/2 - fonts.text_width("arial", 12, label)/2;
    hh = h/2 - fonts.text_height("arial", 12)/2;
    fonts.print(screen,x+ww, y+hh, "arial",12,label, label_color);
}

void GuiFRAME::save_BMP24(const std::string &file_name) {
    FILE *f;
    f = fopen(file_name.c_str(), "wb");
    if(f != NULL) {
        save_textura_to_BMP_file_(f, store_buf, w, h);
        fclose(f);
    }
}


void TEXTURA::save_textura_to_BMP_file(FILE *f) {
    save_textura_to_BMP_file_(f, bitmap, w, h);
}

void load_textura_from_BMP_buffer(unsigned char *buf, unsigned int *&bitmap, unsigned int &w, unsigned int &h) {
        int inverse = 0;

        if (buf == nullptr) return;
        if (bitmap != nullptr) delete[] bitmap;

        bitmap = nullptr;
        w = 0;
        h = 0;


        unsigned short *bfType, *bfReserved1, *bfReserved2;
        unsigned int *bfSize, *bfOffBits;

        bfType = (unsigned short *)&(buf[0]);
        bfSize = (unsigned int *)&(buf[2]);
        bfReserved1 = (unsigned short *)&(buf[6]);
        bfReserved2 = (unsigned short *)&(buf[8]);
        bfOffBits = (unsigned int *)&(buf[10]);


        if (*bfType != 0x4d42) return;


        unsigned int *BITMAPINFO_ver, *biWidth, *biHeight, *biCompression, *biSizeImage, *biClrUsed, *biClrImportant;
        unsigned short *biBitCount;

        int i, j, delta, x, y;
        unsigned int *q;
        delta = *bfOffBits;

        BITMAPINFO_ver = (unsigned int *)&(buf[14]);

        if (*BITMAPINFO_ver == 40) {
                biWidth = (unsigned int *)&(buf[14 + 0x04]);
                biHeight = (unsigned int *)&(buf[14 + 0x08]);
                biBitCount = (unsigned short *)&(buf[14 + 0x0e]);
                biCompression = (unsigned int *)&(buf[14 + 0x10]);
                biSizeImage = (unsigned int *)&(buf[14 + 0x14]);
                biClrUsed = (unsigned int *)&(buf[14 + 0x20]);
                biClrImportant = (unsigned int *)&(buf[14 + 0x24]);
                if (*biCompression == 0 && *biBitCount == 24) {
              w = *biWidth;
                        h = *biHeight;

                        bitmap = new unsigned int[w * h]; //neew(w * h * 4, t->bitmap, "load_textura_from_BMP_buffer()");
                        w = *biWidth;
                        h = *biHeight;
                        
                        q = (unsigned int *)bitmap;
                        char cc[4];
                        unsigned int *qq;
                        qq = (unsigned int *)cc;
                        
                        i = delta;
                        for (y = h - 1; y >= 0; y--) {
                                j = 0;
                                for (x = 0; x < w; x++) {
                                
                                        if (inverse == 0) {
                                
                                                cc[3] = 0;
                                                cc[0] = buf[i];
                                                cc[1] = buf[i + 1];
                                                cc[2] = buf[i + 2];
                                        }
                                        else {
                                                cc[3] = 0;
                                                cc[2] = buf[i];
                                                cc[1] = buf[i + 1];
                                                cc[0] = buf[i + 2];
                                        }
                                        q[y*w + x] = *qq;
                                        i += 3;
                                        j += 3;
                                }
                                j = w % 4;

                                /*
                                if (w == 705) j = 1;
                                if (w == 235) j = 3;
                                if (w == 185) j = 1;
                                if (w == 141) j = 1;
                                if (w == 87) j = 3;
                                if (w == 13) j = 1;
                                if (w == 15) j = 3;
                                if (w == 19) j = 3;
                                if (w == 27) j = 3;
                                if (w == 27) j = 3;
                                */

                                i += j;
                        };
                        return;
                }
                return;
        }
};


/*void SPRITE::SPRITE(std::string file_name) {
    FILE *f;
    f = fopen(file_name.c_str(), "rb");
    
}*/
        
SPRITE::SPRITE(std::string file_name) : buf(nullptr), buf_size(0) {
    unsigned char *b;
    int i,j;
    unsigned int ww, hh;
    b = new unsigned char[100000];
    FILE *f;
    f = fopen(file_name.c_str(), "rb");
    if(f != NULL) {
        
        j = fread(b, 1, 100000, f);
        
        load_textura_from_BMP_buffer(b,buf,ww, hh);
        w = ww;
        h = hh;
        fclose(f);
    }
    delete[] b;
}

void SPRITE_LIST::load() {
    std::string s;
    int i;
    i = 1;
    s = "sprite";
    s += std::to_string(i);
    s += ".bmp";
    while(file_exists(s))
    {
        list.push_back(std::move(s));
        i++;
        s = "sprite";
        s += std::to_string(i);
        s += ".bmp";
    }
}


void SPRITE::paint(SCREEN &screen, int xx, int yy, int ww, int hh) {
    screen.fill(xx, yy, ww, hh, 0xff00ff);
    unsigned int *q, *qq;
    qq = this->buf;
    for(int i=0;i<hh;i++) {
        q = screen.buffer + (yy+i)*screen.w + (xx);
        for(int j=0;j<ww;j++) {
            *q++ = *qq++;
        }
    }
}

void SPRITE_LIST::paint(SCREEN &screen) {
    int hh = 0;
    
    for(auto& a : list ) {
        a.paint(screen, x, y + hh, a.w, a.h);
        hh += a.h+5;
    }
}