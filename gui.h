/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   gui.h
 * Author: smorodin
 *
 * Created on August 3, 2022, 12:41 PM
 */

#ifndef GUI_H
#define GUI_H

#include "font.h"

class SCREEN {
public:
       
    unsigned int *buffer;
    unsigned int w, h;
    void line_h(unsigned int x, unsigned int y, unsigned int ww, unsigned int color) {
        if(x+ww >= w ) return;
        if(y >= h ) return;
        unsigned int *q, i;
        q = buffer + y*w + x;
        for(i = 0;i<ww;i++) *q++ = color;
    }
    void line_v(unsigned int x, unsigned int y, unsigned int hh, unsigned int color) {
        if(x >= w ) return;
        if(y+hh >= h ) return;
        unsigned int *q, i;
        q = buffer + y*w + x;
        for(i = 0;i<hh;i++) {
            *q = color;
            q += w;
        };
    }
    void set_size(unsigned int w_, unsigned int h_) {
        if(w_ == w && h_ == h) return;
        w = w_;
        h = h_;
        if(buffer != nullptr) delete[] buffer;
        buffer = new unsigned int[w*h];
    }
    void fill_all(unsigned int col) {
        if(buffer == nullptr) return;
        int j = w*h;
        for(int i=0;i<j;i++) {
            buffer[i] = col;
        }
    }
    
    void fill(unsigned int xx, unsigned int yy, unsigned int ww, unsigned int hh, unsigned int color) {
        if(xx+ww >= w ) return;
        if(yy+hh >= h ) return;
        
        unsigned int *q;
        unsigned int i, j;
        for(j = 0; j < hh; j++) {
            q = buffer + (yy+j)*w + xx;
            for(i = 0; i < ww; i++) {
                *q++ = color;
            }
        }
        
    }
    
    SCREEN() {
        buffer = nullptr;
        w = 0;
        h = 0;
    }
};

class RECTANGLE {
public:
    std::string label;
    int x, y, w, h;
    unsigned int bg_color, border_color, bg_color_pressed, label_color, label_color_pressed;
    bool is_visible;
    bool is_pressed;
    void(*pfunc_press)(void); 
    
    bool its_me(int xx, int yy) {
        if(x <= xx && x+w > xx && y <= yy && y+h > yy ) {
            return true;
        }
        return false;
    }
    
    void mouse_L_press(int mx, int my) {
        if(its_me(mx, my)) {
            is_pressed = is_pressed == true ? false : true;
            if(pfunc_press != nullptr) {
                pfunc_press();
            }
        }
    }
    
    void set_xy(int x_, int y_, int w_, int h_) {
        x = x_;
        y = y_;
        w = w_;
        h = h_;
    }
    
    void paint(SCREEN &screen);
    
    RECTANGLE& operator=(RECTANGLE&& src) {
        label = std::move(src.label);
        x = src.x;
        y = src.y;
        w = src.w;
        h = src.h;
        bg_color = src.bg_color;
        border_color = src.border_color;
        bg_color_pressed = src.bg_color_pressed;
        label_color = src.label_color;
        label_color_pressed = src.label_color_pressed;
        is_visible = src.is_visible;
        is_pressed = src.is_pressed;
        return *this;
    }
    
    RECTANGLE() {
        x = 0; y = 0; w = 0; h = 0;
        label_color = 0;
        label_color_pressed = 0xff0000;
        bg_color = 0xeeeeee; 
        bg_color_pressed = 0xaaeeaa;
        border_color = 0x0;
        is_visible = true;
        is_pressed = false;
        pfunc_press = nullptr;
    }
};

class GuiBUTTON : public RECTANGLE {
public:
    
    
    
    //void paint(unsigned int *buf);
    
    GuiBUTTON() {
        
    }
};

class GuiFRAME : public RECTANGLE {
public:
    int store_buf_size;
    unsigned int *store_buf;
    
    void save_BMP24(const std::string &s);
    
    void paint(SCREEN &screen) {
        unsigned int *q, *qq;
        int x1, x2, y1, y2;
        x1 = x;
        x2 = x1 + w;
        if(x1 < 0) x1 = 0;
        if(x2 < 0) x2 = 0;
        if(x1 > screen.w-1) x1 = screen.w-1;
        if(x2 > screen.w-1) x2 = screen.w-1;

        y1 = y;
        y2 = y1 + h;
        if(y1 < 0) y1 = 0;
        if(y2 < 0) y2 = 0;
        if(y1 > screen.h-1) y1 = screen.h-1;
        if(y2 > screen.h-1) y2 = screen.h-1;
        
        if(store_buf_size != w*h) {
            if(store_buf != nullptr) delete[] store_buf;
            store_buf_size = w*h;
            store_buf = new unsigned int[store_buf_size];
        }
        
        unsigned col;
        col = is_pressed == false ? bg_color : bg_color_pressed;
        qq = store_buf;
        for(int j = y1; j < y2; j++) {
            q = screen.buffer + j*screen.w + x1;
            for(int i = x1; i < x2; i++) {
                *qq++ = *q;
                col = *q;
                col = col & 0x00ff00;
                *q++ = col;
            }
        }
        
        ////////////////////////////////////////////
        
        x1 = screen.w-w*2-10;
        
        if(x1 < 0) return;
        x2 = x1 + w;
        
        y1 = screen.h-h*2-10;
        //y1 = 50;
        if(y1 < 0) return;
        y2 = y1 + h;
        qq = store_buf;
        for(int j=0; j < h; j++) {
            q = screen.buffer + (j*2+y1)*screen.w + x1;
            for(int i=x1;i < x2;i++) {
                col = *qq++;
                *q = col;
                *(q+1) = col;
                *(q+screen.w) = col;
                *(q+screen.w+1) = col;
                q+=2;
            }
        }
        
    }
    
    void key_press(int key) {
        if(key == 38) {
            if(x >= 5) x-= 5;
        }
        if(key == 40) {
            if(x+w < 1080/2) x+= 5;
        }
        if(key == 25) {
            if(y >= 5) y-= 5;
        }
        if(key == 39) {
            if(y+h < 1920/2) y+= 5;
        }
        if(key == 26) {
            if(w+5 < 250 && x+w < 1080/2) w += 5;
        }
        if(key == 24) {
            if(w > 15) w -= 5;
        }
        if(key == 54) {
            if(h+5 < 150 && y+h < 1920/2) h += 5;
        }
        if(key == 52) {
            if(h > 15) h -= 5;
        }
        
        
    }
    
    GuiFRAME() {
        store_buf_size = 0;
        store_buf = nullptr;
    }
};

class TEXTURA
{
public:
        unsigned int *bitmap = nullptr;
        int w = 0, h = 0;
        void load_textura_from_BMP_buffer(unsigned char *buf);
        void save_textura_to_BMP_file(FILE *f);
        //void load_from_resource(int resource_id);
        //void Paint(GUI_low_level *low_level, int x, int y);
        //void paint_transparent_green(GUI_low_level *low_level, int dx, int dy);
        //void paint_mono(GUI_low_level *low_level, int dx, int dy, unsigned int color);
        TEXTURA(){};
};

class SPRITE : public RECTANGLE {
public:
    unsigned int *buf;
    unsigned int buf_size;
    
    SPRITE& operator=(const SPRITE& src) {
        if (this != &src) {
            
        };
        return *this;
    }
    void paint(SCREEN &screen, int x, int y, int w, int h);
    SPRITE& operator=(SPRITE&& src) {
        if(this->buf != nullptr) delete[] buf;
        this->buf = src.buf;
        this->buf_size = src.buf_size;
        w = src.w;
        h = src.h;
        src.buf = nullptr;
        src.buf_size = 0;
        
        
        
        return *this;
    }
    
    SPRITE(const SPRITE& src) noexcept : buf(nullptr), buf_size(0) {
                
    }
    SPRITE(SPRITE&& src) noexcept : buf(nullptr), buf_size(0) {
        *this = std::move(src);
    }
    SPRITE(std::string file_name);
    
    ~SPRITE() {
        if(buf != nullptr) { delete[] buf; buf = nullptr; };
        buf_size = 0;
    }
};

class SPRITE_LIST : public RECTANGLE {
public:
    std::vector<SPRITE> list;
    void paint(SCREEN &screen);
    void load();
    
    SPRITE_LIST() {
        
    };
};

#endif /* GUI_H */

