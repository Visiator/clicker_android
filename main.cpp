#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/extensions/XTest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/time.h>
#include <thread>
#include <errno.h>
#include <condition_variable>

#include "gui.h"
#include "font.h"

//------------------------------------------------------------------------------------------------
#define X 0
#define Y 0
#define WIDTH 600
#define HEIGHT 300
#define DISPLAY_WIDTH 1600
#define DISPLAY_HEIGHT 900

SPRITE_LIST sprites;

FONTS fonts;
bool cccc = true;

int memo_counter_ = 0;

GuiBUTTON btn_run, btn_frame, btn_save_frame;
GuiFRAME  frame;

unsigned int find_window_android(int lvl, Display *display, Window w);

void need_refresh(Display *display, Window &window);

//unsigned int scr_buffer[1920/2 * 1080/2];

using namespace std;

SCREEN screen;
SCREEN android_screen_buffer;
int android_screen_x = -1, android_screen_y = -1;
/*
 * 
 */
int tik = 0;
char msg [256]={"test"};

Display     *display = nullptr;
Window      window;
XEvent exppp;
bool timer_show = false;


unsigned int avg(unsigned int v1, unsigned int v2, unsigned int v3, unsigned int v4) {
    unsigned int r, g, b;
    r = ((v1 & 0xff) + (v2 & 0xff) + (v3 & 0xff) + (v4 & 0xff)) / 4;
    g = (((v1 & 0xff00) + (v2 & 0xff00) + (v3 & 0xff00) + (v4 & 0xff00))>>8) / 4;
    b = (((v1 & 0xff0000) + (v2 & 0xff0000) + (v3 & 0xff0000) + (v4 & 0xff0000))>>16) / 4;
    
    return r | (g<<8) | (b<<16);
}


int nnn = 1;

void fake_move(Display* display, Window win, int x, int y) {
    XTestFakeMotionEvent(display, -1, x, y, CurrentTime);
}

void fake_click(Display* display, Window win) {
    
    
    XTestFakeButtonEvent(display, Button1, true, CurrentTime);
    XFlush(display);
    XTestFakeButtonEvent(display, Button1, false, CurrentTime);
    XFlush(display);

 
    
    /*
    XEvent expp;
    memset(&expp, 0, sizeof(expp));
    expp.type = Expose;
    expp.xexpose.window = window;
    XSendEvent(display, window,False,ExposureMask,&expp);
    */
}


void* thread_proc_get_scr(void *q) {
 
    Display     *d = XOpenDisplay(getenv("DISPLAY"));
    Window w = 0;// = DefaultRootWindow(d);
    XImage      *imageS;
    
    
    XWindowAttributes window_attr;
    
    //w = find_window_android(d, DefaultRootWindow(d));        

    
    for(;;) {

        if(w == 0) {
            w = find_window_android(0, d, DefaultRootWindow(d));        
        } else {
            
            if(nnn == 1) {
                nnn = 0;
                //sleep(5);
                //fake_move(d, w);
                //fake_click(d, w);
            }
            
            XGetWindowAttributes(d, w, &window_attr);
            
            if(window_attr.width/2 != android_screen_buffer.w || window_attr.height/2 != android_screen_buffer.h) {
                //g_mutex.lock();
                
                
                android_screen_buffer.set_size(window_attr.width/2, window_attr.height/2);
                //g_mutex.unlock();
            };
            
            imageS = XGetImage(d, w, 0, 0, window_attr.width, window_attr.height, AllPlanes, ZPixmap);

            if(imageS == nullptr) {
                w = 0;
            } else {
            
                if(cccc) {
                    cccc = false;
                    XRaiseWindow(d, w);
                    XFlush(d);
                    
                }
                
                android_screen_x = window_attr.x;
                android_screen_y = window_attr.y; 
                
                unsigned int *qq, *q;
                qq = (unsigned int *)imageS->data;
                q = android_screen_buffer.buffer;
                int k = 0;
                for(int j=0;j<window_attr.height/2;j++) {
                    
                    for(int i=0;i<window_attr.width/2;i++) {
                        *q++ = avg( *qq, *(qq+1) , *(qq+window_attr.width), *(qq+window_attr.width+1));
                        qq+=2;
                    }
                    qq += window_attr.width;
                    //q += window_attr.width/2;
                }
                
                sprites.find_direct(android_screen_buffer);
                
                if(btn_run.is_pressed) {
                    for(auto& a : sprites.list) {
                        if(a.is_detected) {
                            btn_run.is_pressed = false;
                            usleep(1000000);
                            
                            //usleep(1000000);
                            //fake_move(d, w, android_screen_x + a.x*2 + a.w, android_screen_y + a.y*2 + a.h);                            
                            //usleep(1000000);
                            //fake_click(d, w);
                            //usleep(1000000);
                        }
                    }
                }
                
                
                XFree(imageS);
            };
        };
        
        usleep(500000);
    }
}


//void thread_proc(int tnum) {
void* thread_proc_tik (void* q)
{
    char ss[100];
    
    for(;;) {

        sprintf(ss, "%06d", tik++);

        for(int i=0; i < 15;i++) {
            msg[i] = 0;
            msg[i+1] = 0;
            msg[i] = ss[i];
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}




void save_frame_press() {
    
    std::string s;
    int idx;
    s = generate_new_dirname_sprite(idx);
    frame.nic = std::to_string(idx);
    frame.save_BMP24(s);

    btn_save_frame.is_pressed = false;
}

char* getWindowName( Display* display, Window win ) {
    Atom actualType;
    int format;
    ulong count, bytesAfter;
    unsigned  char* name = NULL;
    Status status = XGetWindowProperty(
                        display,
                        win,
                        XInternAtom( display, "_NET_WM_NAME", False ),
                        0L,
                        ~0L,
                        False,
                        XInternAtom( display, "UTF8_STRING", False ),
                        &actualType,
                        &format,
                        &count,
                        &bytesAfter,
                        &name
                    );

    if( status != Success ) {
        return NULL;
    }

    if( name == NULL ) {
        Status status = XGetWindowProperty(
                            display,
                            win,
                            XInternAtom( display, "WM_NAME", False ),
                            0L,
                            ~0L,
                            False,
                            AnyPropertyType,
                            &actualType,
                            &format,
                            &count,
                            &bytesAfter,
                            &name
                        );

        if( status != Success ) {
            return NULL;
        }
    }

    return reinterpret_cast< char* >( name );
}

unsigned int find_window_android(int lvl, Display *display, Window www) {
    
    int status;
    Window parent, rw;
    Window *children;
    unsigned int nNumChildren, r = 0;
    XWindowAttributes window_attr;
     
    status = XQueryTree(display, www, &rw, &parent, &children, &nNumChildren);
    if (status == 0) return 0;
    if (nNumChildren == 0) return 0;

    for (int i = 0; i < nNumChildren; i++)
    {
        
        char* name  = getWindowName(display, children[i]);
        if(name != nullptr) {
            if(name[0] == 'E' && name[1] == 'M' && name[2] == 'U'  && name[3] == 'L') {
                XFree(name);
                r = children[i];
                XFree((char*) children);
                return r;
            };
        }
        XFree(name);
        
        XGetWindowAttributes(display, children[i], &window_attr);
        if(window_attr.width == 668 && window_attr.height == 1207) {
            r = children[i];
            XFree((char*) children);
            return r;
        }
    }

    XFree((char*) children);
    return 0;
}

int main(int argc, char** argv) {

    sprites.set_xy(560, 140, 200, 600);
    sprites.load();
    
    btn_run.set_xy(560, 20,100, 20);
    btn_run.label = "run";
    
    btn_frame.label = "frame";
    btn_frame.set_xy(560, 60,100, 20);
    
    btn_save_frame.label = "save frame";
    btn_save_frame.set_xy(560, 100,100, 20);
    btn_save_frame.pfunc_press = save_frame_press;
    //btn1.set_label("capture");
    
    frame.set_xy(50, 10,100, 20);
    
    screen.set_size(1080/2+250, 1920/2+20);
    
    /*
     ok
    Display *dis=XOpenDisplay((char *)0);
    Screen *scr = XDefaultScreenOfDisplay(dis);
    Drawable drawable = XDefaultRootWindow(dis);

    XImage *image = XGetImage(dis, drawable, 0, 0, scr->width, scr->height, AllPlanes, ZPixmap);
    //Save_XImage_to_JPG(image, sFilePath_Name.c_str(), 75);
    XDestroyImage(image);

    XCloseDisplay(dis); 
    */
    
    
    
    XEvent      event;
    int         screen_id;
    XImage      *image;
    GC          graph_ctx;
    XGCValues   *gc_values;
    
     // Соединяемся с X сервером
    if ((display = XOpenDisplay(getenv("DISPLAY"))) == NULL)
    {
        printf("Can't connect X server: %s\n", strerror(errno));
        exit(1);
    }
 
    screen_id = XDefaultScreen(display);
    //imageS = XGetImage(display, DefaultRootWindow(display), 0, 0, 500, 500, AllPlanes, ZPixmap);
    
    
    //find_window_android(display, screen_id);
    
    
    // Создаем окно 1920×1080
    window = XCreateSimpleWindow(display, RootWindow(display, screen_id), X, Y, screen.w, screen.h, 10, XBlackPixel(display, screen_id), XWhitePixel(display, screen_id));
 
    // Создаем графический контекст
    graph_ctx=XCreateGC(display, window, 0, gc_values);
 
    // На какие события будем реагировать
    XSelectInput(display, window, ExposureMask | KeyPressMask | PointerMotionMask | ButtonPressMask );
 
    //Показываем окно на экране
    XMapWindow(display, window);
    
    //create_thread_timer();
    //std::thread thr(thread_proc, 0);
    pthread_t thread_tik, thread_get_scr;
    
    bool nnnn = false;
    bool animation_enabled = true;
    //XPostTimeoutEventEvery( 0.3 );
    //Pixmap pm;
    //pm = XCreatePixmap(display, window, 500, 500, 24);
    
    image = XCreateImage(display,DefaultVisual(display,DefaultScreen(display)),24,ZPixmap,0,(char*) screen.buffer,screen.w, screen.h,32,(screen.w)*4);
    
    pthread_create(&thread_tik, NULL, thread_proc_tik, NULL);
    
    pthread_create(&thread_get_scr, NULL, thread_proc_get_scr, NULL);
    
    //XCopyArea(display, imageS, image, graph_ctx, 0, 0, 500, 500, 0, 0);
    
    
    // Бесконечный цикл обработки событий
    while (1)
    {
        if (XPending(display)) {
            
            // XLockDispay и XUnlockDisplay
            try {
                XNextEvent(display, &event);
            } catch(...) {
                printf("catch 1\n");
            }
            if(timer_show == true) timer_show = false;
            //printf("event arrived %d...\n", event.type);
            //g_mutex.lock();
            if (event.type == Expose) // Перерисовываем окно
            {
                //XSetForeground (display, graph_ctx, 0);
                //XFillRectangle (display, window, graph_ctx, 0, 0, 100, 100);

                // Отображаем картинку в окне
                screen.fill_all(0xcccccc);
                unsigned int *ss;
                ss = android_screen_buffer.buffer;
                
                for(int j=0;j<android_screen_buffer.h;j++) {
                    unsigned int *qq;
                    qq = screen.buffer + screen.w * j;
                    for(int i=0;i<android_screen_buffer.w;i++) {
                        *qq++ = *ss++;
                    }
                    
                }
                
                btn_run.paint(screen);
                btn_frame.paint(screen);
                btn_save_frame.paint(screen);
                if(btn_frame.is_pressed) {
                    frame.paint(screen);
                }
                sprites.paint(screen);
                std::string xx;
                xx = std::to_string(android_screen_x) + ":" + std::to_string(android_screen_y);
                fonts.print(screen, 700, 20, "arial", 10, xx, 0xff);
                
                XPutImage(display, window, graph_ctx, image, 0, 0, 0, 0, screen.w, screen.h);//DISPLAY_WIDTH, DISPLAY_HEIGHT);

                
                XSetForeground (display, graph_ctx, 0xffff00);
                XDrawString (display, window, graph_ctx, 50, 50, msg, strlen (msg));
                
                
                
                
                //timer_show = false;
            } else if (event.type == ButtonPress) {
                    printf("ButtonPress\n");
                    btn_run.mouse_L_press(event.xbutton.x, event.xbutton.y);
                    btn_frame.mouse_L_press(event.xbutton.x, event.xbutton.y);
                    btn_save_frame.mouse_L_press(event.xbutton.x, event.xbutton.y);
                    
            } else if (event.type == KeyPress) {
                    printf("KeyPress %d\n", event.xkey.keycode);
                if(btn_frame.is_pressed) {
                    frame.key_press(event.xkey.keycode);
                }
            } else {
                
            }
            nnnn = true;
        }
        else {
            usleep(1000);
            if(nnnn) {
                nnnn = false;
                memset(&exppp, 0, sizeof(exppp));
                exppp.type = Expose;
                exppp.xexpose.window = window;
                XSendEvent(display, window,False,ExposureMask,&exppp);
            };
            
        }
    }
 
    
    //XFreePixmap(display, pm);
    
    // Закрываем соединение с X сервером
    XCloseDisplay(display);
    
    return 0;
}

bool SPRITE_LIST::find(SCREEN& sb) {

    mmutex.lock();
    
    for(int i=0;i<list.size();i++) {
        list[i].find(sb);
    };
    mmutex.unlock();
    
    return false;
}

bool SPRITE::find(SCREEN& sb) {

    
    
    if(w == 0 || h == 0) {
        this->is_detected = false;
        return false;
    };
    
    unsigned int *q1, *q2;
    int xx, yy, ww, hh;
    
    ww = sb.w - this->w;
    hh = sb.h - this->h;
    yy = 0;
    while(yy < hh) {
        
        xx = 0;
        while(xx < ww) {
            
            q2 = this->buf;
            int xxx, yyy, vvv, c1, c2;
            vvv = 0;
            yyy = 0;
            while(yyy < this->h) {
                q1 = sb.buffer + (yy+yyy)*sb.w + xx;
                xxx = 0;
                while(xxx < this->w) {
                    c1 = *q1;
                    c2 = *q2;
                    if(*q1 != *q2) break;
                    q1++;
                    q2++;
                    xxx++;
                    vvv++;
                }
                if(xxx != this->w) {
                    break;
                }
                yyy++;
            };
            if(yyy == this->h) {
                detect_x = xx;
                detect_y = yy;
                this->is_detected = true;
                return true;
            }
            xx++;
        }
        yy++;
    }
    this->is_detected = false;
    return false;
};


bool SPRITE_LIST::find_direct(SCREEN& sb) {
    mmutex.lock();
    
    for(int i=0;i<list.size();i++) {
        list[i].find_direct(sb);
    };
    mmutex.unlock();
    
    return false;
}


bool SPRITE::find_direct(SCREEN& sb) {

    
    
    if(w == 0 || h == 0) {
        this->is_detected = false;
        return false;
    };
    
    unsigned int *q1, *q2;
    int xx, yy, ww, hh;
    
    ww = sb.w - this->w;
    hh = sb.h - this->h;
    yy = y;
    //while(yy < hh) {
        
        xx = x;
        //while(xx < ww) {
            
            q2 = this->buf;
            int xxx, yyy, vvv, c1, c2;
            vvv = 0;
            yyy = 0;
            while(yyy < this->h) {
                q1 = sb.buffer + (yy+yyy)*sb.w + xx;
                xxx = 0;
                while(xxx < this->w) {
                    c1 = *q1;
                    c2 = *q2;
                    if(*q1 != *q2) break;
                    q1++;
                    q2++;
                    xxx++;
                    vvv++;
                }
                if(xxx != this->w) {
                    break;
                }
                yyy++;
            };
            if(yyy == this->h) {
                detect_x = xx;
                detect_y = yy;
                this->is_detected = true;
                return true;
            }
        //    xx++;
        //}
        //yy++;
    //}
    this->is_detected = false;
    return false;
};
