/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-terminus-medium-r-*-*-20-*-*-*-*-*-*-*";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#005577";
// static const char selbgcolor[]      = "#005577";
static const char selfgcolor[]      = "#eeeeee";
static const char normbordercolor[]  = "#282a2e";
static const char normbgcolor[]      = "#282a2e";
static const char selbgcolor[]       = "#1d1f21";
static const char urgentbgcolor[]    = "#f0c674";
static const char floatnormbordercolor[] = "#885599";
static const char floatselbordercolor[]  = "#880000";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool systraypinningfailfirst = True;   /* True: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const Bool showsystray       = True;     /* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class          instance     title       tags mask     isfloating   monitor */
	{ "Gimp",         NULL,        NULL,       0,            True,        -1 },
	{ "MPlayer",      NULL,        NULL,       0,            True,        -1 },
	{ "slack",        NULL,        NULL,       1 << 5,       False,       -1 },
	{ "URxvt",        "float",     NULL,       0,            True,        -1 },
	{ "mplayer2",     NULL,        NULL,       0,            True,        -1 },
	{ "Blueman-manager", NULL,     NULL,       0,            True,        -1 },
	{ "mpv",          NULL,        NULL,       0,            True,        -1 },
	{ "Vlc",          NULL,        NULL,       0,            True,        -1 },
	{ "XFontSel",     NULL,        NULL,       0,            True,        -1 },
	{ "Kcalc",        NULL,        NULL,       0,            True,        -1 },
	{ "XCalc",        NULL,        NULL,       0,            True,        -1 },
	{ "Komodo Edit",  NULL,        NULL,       0,            True,        -1 },
	{ "Xmessage",     NULL,        NULL,       0,            True,        -1 },
	{ "KeePass2",     NULL,        NULL,       1 << 4,       True,        -1 },
	{ "Komodo Edit",  "Komodo",    NULL,       0,            False,       -1 },
	{ "Komodo Edit",  NULL,        "Find",     0,            True,        -1 },
	{ "Chromium",     NULL,        NULL,       1 << 2,       False,       -1 },
	{ "Firefox",      NULL,        NULL,       1 << 2,       True,        -1 },
	{ "Netsurf-gtk",  NULL,        NULL,       1 << 2,       False,       -1 },
	{ "luakit",       NULL,        NULL,       1 << 2,       False,       -1 },
	{ "Dwb",          NULL,        NULL,       1 << 2,       False,       -1 },
	{ "Firefox",      "Navigator", NULL,       1 << 2,       False,       -1 },
	{ "Ktorrent",     NULL,        NULL,       1 << 4,       False,       -1 },
	{ "VirtualBox",   NULL,        NULL,       1 << 4,       False,       -1 },
	{ "Qemu-system-x86_64", NULL,  NULL,       1 << 4,       False,       -1 },
	{ "Idaq64",       NULL,        NULL,       1 << 4,       False,       -1 },
	{ "VBoxSDL",      NULL,        NULL,       1 << 5,       False,       -1 },
	{ "Wine",         NULL,        NULL,       1 << 5,       False,       -1 },
	{ "Xephyr",       NULL,        NULL,       0,            False,       -1 },
	{ "Opera",        NULL,        NULL,       1 << 2,       False,       -1 },
  { "Pidgin",       NULL,        NULL,       1 << 3,       False,       -1 },
  { "Pidgin",       NULL,        "Pidgin",   1 << 3,       True,        -1 },
	{ "Dia",          NULL,        NULL,       1 << 5,       True,        -1 },
	{ "Gyachi",       NULL,        NULL,       1 << 3,       False,       -1 },
	{ "Skype",        NULL,        NULL,       1 << 3,       False,       -1 },
	{ "Zim",          NULL,        NULL,       0,            True,        -1 },
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Kio_uiserver", NULL,   NULL,       0,            True,        -1 },
	{ "Xchat",    NULL,       NULL,       1,            True,        -1 },
	{ "Hexchat",  NULL,       NULL,       1,            True,        -1 },
	{ "Jitsi",    NULL,       NULL,       1,            True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.65; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

#include "gaplessgrid.c"
#include "pidgin.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "+++",      gaplessgrid },
	{ "[P]",      pidgin },
};

static const Tag tags[] = {
    /* name layout mfact nmaster */
    { "1:main", &layouts[0], -1, -1 },
    { "2:term", &layouts[0], -1, -1 },
    { "3:web", &layouts[2], -1, -1 },
    { "4:im", &layouts[4], 0.83, -1 },
    { "5:doc", &layouts[1], -1, -1 },
    { "6:misc", &layouts[2], -1, -1 },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvtc", NULL };

static const char *supermenucmd[] = { "supermenu", NULL };
static const char *vollow[]     = { "amixer", "-q", "set", "Master", "2dB-", NULL };
static const char *volhigh[]    = { "amixer", "-q", "set", "Master", "2dB+",  NULL };
static const char *voltoggle[]  = { "amixer", "set", "Master", "1+", "toggle", NULL };
static const char *brightup[]   = { "light", "-A", "2", NULL };
static const char *brightdown[] = { "light", "-U", "2", NULL };
static const char *playtoggle[] = { "mpc", "toggle", NULL };
static const char *playprev[]   = { "mpc", "prev", NULL };
static const char *playnext[]   = { "mpc", "next", NULL };
static const char *displayswitch[]   = { "togglescreen", NULL };
static const char *rfkill[]     = { "grfkill", NULL };
static const char *slack[]      = { "slack", NULL, NULL, NULL, "slack" };
static const char *keepass[]    = { "keepass", NULL, NULL, NULL, "KeePass2" };
static const char *zim[]        = { "zim", NULL, };

static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "urxvtc", "-pe", "tabbed", "-name", scratchpadname, "-geometry", "150x28", NULL };

#include "toggleview_focus.c"
#include "moveresize.c"
#include "tagall.c"
#include "maximize.c"
#include "zoomswap.c"
#include "push.c"
#include "focusmaster.c"
#include "shifttags.c"
#include "keepfloatingposition.c"
#include "focusurgent.c"
#include "runorraise.c"
#include "scratchpad.c"
static Key keys[] = {
  { MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd} },
	{ MODKEY,                       XK_s,      runorraise,     {.v = slack} },
	{ MODKEY,                       XK_v,      runorraise,     {.v = keepass} },
	{ MODKEY|ShiftMask,             XK_z,      spawn,          {.v = zim} },
	{ MODKEY,                       XK_u,      focusurgent,    {0} },
  { 0,                            0x1008ff11,spawn,          {.v = vollow } },
  { 0,                            0x1008ff13,spawn,          {.v = volhigh } },
  { 0,                            0x1008ff12,spawn,          {.v = voltoggle } },
  { 0,                            0x1008ff11,spawn,          {.v = vollow } },
  { 0,                            0x1008ff03,spawn,          {.v = brightdown } },
  { 0,                            0x1008ff02,spawn,          {.v = brightup } },
  { 0,                            0x1008ff16,spawn,          {.v = playprev } },
  { 0,                            0x1008ff17,spawn,          {.v = playnext } },
  { 0,                            0x1008ff14,spawn,          {.v = playtoggle } },
  { 0,                            0x1008ff4a,spawn,          {.v = displayswitch } },
  { 0,                            0x1008ff4b,spawn,          {.v = rfkill } },
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = supermenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      pushdown,       {0} },
	{ MODKEY|ShiftMask,             XK_k,      pushup,         {0} },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ Mod1Mask,                     XK_Tab,    swapfocus,      {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  toggleview_focus, {.ui = 1} },
	{ MODKEY|ControlMask,           XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_w,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_v,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_w,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_v,      tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_q,      quit,           {1} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask,           XK_l,      togglehorizontalmax, {0} },
	{ MODKEY|ControlMask,           XK_h,      togglehorizontalmax, {0} },
	{ MODKEY|ControlMask,           XK_j,      toggleverticalmax,   {0} },
	{ MODKEY|ControlMask,           XK_k,      toggleverticalmax,   {0} },
	{ MODKEY|ControlMask,           XK_m,      togglemaximize,      {0} },
	{ MODKEY|ShiftMask,             XK_F1,     tagall,         {.v = "F1" } },
	{ MODKEY|ShiftMask,             XK_F2,     tagall,         {.v = "F2" } },
	{ MODKEY|ShiftMask,             XK_F3,     tagall,         {.v = "F3" } },
	{ MODKEY|ShiftMask,             XK_F4,     tagall,         {.v = "F4" } },
	{ MODKEY|ShiftMask,             XK_F5,     tagall,         {.v = "F5" } },
	{ MODKEY|ShiftMask,             XK_F6,     tagall,         {.v = "F6" } },
	{ MODKEY|ShiftMask,             XK_F7,     tagall,         {.v = "F7" } },
	{ MODKEY|ShiftMask,             XK_F8,     tagall,         {.v = "F8" } },
	{ MODKEY|ShiftMask,             XK_F9,     tagall,         {.v = "F9" } },
	{ MODKEY,                       XK_a,      moveresize,     {.v = "-20x 0y 0w 0h" } },
	{ MODKEY,                       XK_d,      moveresize,     {.v = "20x 0y 0w 0h" } },
	{ MODKEY,                       XK_s,      moveresize,     {.v = "0x 20y 0w 0h" } },
	{ MODKEY,                       XK_w,      moveresize,     {.v = "0x -20y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_a,      moveresize,     {.v = "0X 0y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_d,      moveresize,     {.v = "9000X 0y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_s,      moveresize,     {.v = "0x 9000Y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_w,      moveresize,     {.v = "0x 15Y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_a,      moveresize,     {.v = "0x 0y -20w 0h" } },
	{ MODKEY|ShiftMask,             XK_d,      moveresize,     {.v = "0x 0y 20w 0h" } },
	{ MODKEY|ShiftMask,             XK_s,      moveresize,     {.v = "0x 0y 0w 20h" } },
	{ MODKEY|ShiftMask,             XK_w,      moveresize,     {.v = "0x 0y 0w -20h" } },
	{ MODKEY|ControlMask,           XK_Return, focusmaster,    {0} },
	{ MODKEY,                       XK_Left,   shifttags,      {.i = -1} },
	{ MODKEY,                       XK_Right,  shifttags,      {.i = +1} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

