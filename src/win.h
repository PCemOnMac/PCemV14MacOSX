extern HINSTANCE hinstance;
extern HWND ghwnd;
extern int mousecapture;

#ifdef __cplusplus
extern "C" {
#endif

#define szClassName "PCemMainWnd"
#define szSubClassName "PCemSubWnd"

void leave_fullscreen();

#ifdef __cplusplus
}
#endif


void status_open(HWND hwnd);
extern HWND status_hwnd;
extern int status_is_open;

void hdconf_open(HWND hwnd);

void config_open(HWND hwnd);

int config_selection_open(HWND hwnd, int inited);

struct device_t;

void deviceconfig_open(HWND hwnd, struct device_t *device);
void joystickconfig_open(HWND hwnd, int joy_nr, int type);
void networkconfig_open(HWND hwnd);

extern char openfilestring[260];

int getfile(HWND hwnd, char *f, char *fn);
int getsfile(HWND hwnd, char *f, char *fn, char *dir, char *ext);

extern int pause;

extern int has_been_inited;
