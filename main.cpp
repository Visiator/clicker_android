#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
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

int memo_counter_ = 0;

GuiBUTTON btn_capture, btn_frame, btn_save_frame;
GuiFRAME  frame;

unsigned int find_window_android(int lvl, Display *display, Window w);

void need_refresh(Display *display, Window &window);

//unsigned int scr_buffer[1920/2 * 1080/2];

using namespace std;

SCREEN screen;
SCREEN android_screen_buffer;

/*
 * 
 */
int tik = 0;
char msg [256]={"test"};

Display     *display = nullptr;
Window      window;
XEvent exppp;
bool timer_show = false;
std::mutex g_mutex;

unsigned int avg(unsigned int v1, unsigned int v2, unsigned int v3, unsigned int v4) {
    unsigned int r, g, b;
    r = ((v1 & 0xff) + (v2 & 0xff) + (v3 & 0xff) + (v4 & 0xff)) / 4;
    g = (((v1 & 0xff00) + (v2 & 0xff00) + (v3 & 0xff00) + (v4 & 0xff00))>>8) / 4;
    b = (((v1 & 0xff0000) + (v2 & 0xff0000) + (v3 & 0xff0000) + (v4 & 0xff0000))>>16) / 4;
    
    return r | (g<<8) | (b<<16);
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
            XGetWindowAttributes(d, w, &window_attr);
            
            if(window_attr.width/2 != android_screen_buffer.w || window_attr.height/2 != android_screen_buffer.h) {
                g_mutex.lock();
                android_screen_buffer.set_size(window_attr.width/2, window_attr.height/2);
                g_mutex.unlock();
            };
            
            imageS = XGetImage(d, w, 0, 0, window_attr.width, window_attr.height, AllPlanes, ZPixmap);

            if(imageS == nullptr) {
                w = 0;
            } else {
            
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
    
    s = generate_new_filename_sprite();
    frame.save_BMP24(s);
    
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
    
    btn_capture.set_xy(560, 20,100, 20);
    btn_capture.label = "capture";
    
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
                
                btn_capture.paint(screen);
                btn_frame.paint(screen);
                btn_save_frame.paint(screen);
                if(btn_frame.is_pressed) {
                    frame.paint(screen);
                }
                sprites.paint(screen);
                
                
                XPutImage(display, window, graph_ctx, image, 0, 0, 0, 0, screen.w, screen.h);//DISPLAY_WIDTH, DISPLAY_HEIGHT);

                
                XSetForeground (display, graph_ctx, 0xffff00);
                XDrawString (display, window, graph_ctx, 50, 50, msg, strlen (msg));
                
                
                
                
                //timer_show = false;
            } else if (event.type == ButtonPress) {
                    printf("ButtonPress\n");
                    btn_capture.mouse_L_press(event.xbutton.x, event.xbutton.y);
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

