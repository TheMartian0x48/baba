#ifndef BABE_GRAPHICS
#define BABE_GRAPHICS

#include "../types.h"

// normalized value i.e. [0, 1]
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
RBGColor color_hsv_to_rgb(HSVColor hsv);
RBGColor color_xyz_to_rgb(XYZColor xyz);
RBGColor color_lab_to_rgb(LABColor lab);

//***** convert to hsv *****
HSVColor color_rgb_to_hsv(RBGColor rgb);
HSVColor color_xyz_to_hsv(XYZColor xyz);
HSVColor color_lab_to_hsv(LABColor lab);

//***** convert to xyz *****
XYZColor color_rbg_to_xyz(RBGColor rgb);
XYZColor color_hsv_to_xyz(HSVColor hsv);
XYZColor color_lab_to_xyz(LABColor lab);

//***** convert to lab *****
LABColor color_rbg_to_lab(RBGColor rgb);
LABColor color_hsv_to_lab(HSVColor hsv);
LABColor color_xyz_to_lab(XYZColor xyz);
#endif
