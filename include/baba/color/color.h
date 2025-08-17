#ifndef BABA_COLOR
#define BABA_COLOR

#include "../types.h"

typedef struct {
    f32 r;
    f32 g;
    f32 b;
} RBGColor;

typedef struct {
    f32 h;
    f32 s;
    f32 v;
} HSVColor;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} XYZColor;

typedef struct {
    f32 l;
    f32 a;
    f32 b;
} LABColor;

//***** convert to rgb *****
RBGColor color_hsv_to_rgb(HSVColor hsv_color);
RBGColor color_xyz_to_rgb(XYZColor xyz_color);
RBGColor color_lab_to_rgb(LABColor lab_color);

//***** convert to hsv *****
HSVColor color_rgb_to_hsv(RBGColor rgb_color);
HSVColor color_xyz_to_hsv(XYZColor xyz_color);
HSVColor color_lab_to_hsv(LABColor lab_color);

//***** convert to xyz *****
XYZColor color_rbg_to_xyz(RBGColor rgb_color);
XYZColor color_hsv_to_xyz(HSVColor hsv_color);
XYZColor color_lab_to_xyz(LABColor lab_color);

//***** convert to lab *****
LABColor color_rbg_to_lab(RBGColor rgb_color);
LABColor color_hsv_to_lab(HSVColor hsv_color);
LABColor color_xyz_to_lab(XYZColor xyz_color);
#endif
