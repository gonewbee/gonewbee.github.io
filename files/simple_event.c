/**
 * @brief 测试各类事件
 * 
 * 编译：gcc simple_event.c -lX11
 */
#include <stdio.h>
#include <X11/Xlib.h>

#define MWM_DECOR_ALL           (1L << 0)
#define MWM_FUNC_ALL            (1L << 0)
#define MWM_HINTS_FUNCTIONS     (1L << 0)
#define MWM_HINTS_DECORATIONS   (1L << 1)
#define PROP_MOTIF_WM_HINTS_ELEMENTS	5

struct _PropMotifWmHints
{
	unsigned long flags;
	unsigned long functions;
	unsigned long decorations;
	long inputMode;
	unsigned long status;
};
typedef struct _PropMotifWmHints PropMotifWmHints;

/**
 * 设置完后，建立的窗口就没有Ubuntu自带的关闭、最小化和最大化这三个键了
 */
void setWindowDecorations(Display *dsp, Window window, int show)
{
	PropMotifWmHints hints;
	
	Atom _MOTIF_WM_HINTS = XInternAtom(dsp, "_MOTIF_WM_HINTS", False);
	hints.decorations = (show) ? MWM_DECOR_ALL : 0;
	hints.functions = MWM_FUNC_ALL ;
	hints.flags = MWM_HINTS_DECORATIONS | MWM_HINTS_FUNCTIONS;
	hints.inputMode = 0;
	hints.status = 0;

	XChangeProperty(dsp, window, _MOTIF_WM_HINTS, _MOTIF_WM_HINTS, 32,
			PropModeReplace, (char*) &hints, PROP_MOTIF_WM_HINTS_ELEMENTS);
}

Window create_window(Display *dsp, Screen *screen) {
	Window window;
	int x, y;
	int width, height;
	int depth;
	XSetWindowAttributes winAttrib;
	XWindowAttributes window_attributes;
	
	x = 30;
	y = 60;
	width = 200;
	height = 300;
	winAttrib.background_pixel = BlackPixelOfScreen(screen);
	winAttrib.border_pixel = WhitePixelOfScreen(screen);
	winAttrib.backing_store = Always/*NotUseful*/;
	winAttrib.override_redirect = False;
	winAttrib.bit_gravity = NorthWestGravity;
	winAttrib.win_gravity = NorthWestGravity;
	depth = DefaultDepthOfScreen(screen);
	if (XGetWindowAttributes(dsp, RootWindowOfScreen(screen), &window_attributes) == 0)
	{
		fprintf(stderr, "xf_get_pixmap_info: XGetWindowAttributes failed\n");
		return 1;
	}
	window = XCreateWindow(dsp, RootWindowOfScreen(screen),
						x, y,
						width, height,
						0,
						depth,
						InputOutput, /*window_attributes.visual*/DefaultVisual(dsp, 0),
						0, &winAttrib);
	setWindowDecorations(dsp, window, 0);	//设置后没有Ubuntu自带的关闭、最小和最大这三个键
	return window;
}

int main(int argc, char *argv[]) {
	Display *dsp = NULL;
	Screen *screen;
	Window window;
	
	dsp = XOpenDisplay(NULL);
	screen = DefaultScreenOfDisplay(dsp);
	window = create_window(dsp, screen);
	XMapWindow(dsp, window);
	XFlush(dsp);
	
	getchar();
	XDestroyWindow(dsp, window);
	XCloseDisplay(dsp);
    return 0;
}

