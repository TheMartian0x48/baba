#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>

//***** convert to rgb *****
RBGColor color_hsv_to_rgb(HSVColor hsv)
{
    fprintf(stderr, "[%s : %d] color_hsv_to_rgb is not implemented", __FILE__, __LINE__);
    exit(-1);
}
RBGColor color_xyz_to_rgb(XYZColor xyz)
{
    fprintf(stderr, "[%s : %d] color_xyz_to_rgb is not implemented", __FILE__, __LINE__);
    exit(-1);
}
RBGColor color_lab_to_rgb(LABColor lab)
{
    fprintf(stderr, "[%s : %d] color_lab_to_rgb is not implemented", __FILE__, __LINE__);
    exit(-1);
}

//***** convert to hsv *****
HSVColor color_rgb_to_hsv(const RBGColor rgb)
{
    const f32 mx = Max(rgb.r, Max(rgb.b, rgb.g));
    const f32 mi = Min(rgb.r, Min(rgb.b, rgb.g));

    HSVColor result = {0};
    if (mx == 0) {
        return result;
    }
    result.v = mx;
    result.s = (mx - mi) / mx;

    if (mx == rgb.r) {
        result.h = (2.0f - (rgb.b - rgb.r) / (mx - mi)) / 6.0f;
    } else if (mx == rgb.g) {
        result.h = (2.0f + (rgb.b - rgb.r) / (mx - mi)) / 6.0f;
    } else {
        result.h = (4.0f - (rgb.r - rgb.g) / (mx - mi)) / 6.0f;
    }

    return result;
}

HSVColor color_xyz_to_hsv(XYZColor xyz)
{
    fprintf(stderr, "[%s : %d] color_xyz_to_hsv is not implemented", __FILE__, __LINE__);
    exit(-1);
}
HSVColor color_lab_to_hsv(LABColor lab)
{
    fprintf(stderr, "[%s : %d] color_lab_to_hsv is not implemented", __FILE__, __LINE__);
    exit(-1);
}

//***** convert to xyz *****
XYZColor color_rbg_to_xyz(RBGColor rgb)
{
    fprintf(stderr, "[%s : %d] color_rbg_to_xyz is not implemented", __FILE__, __LINE__);
    exit(-1);
}
XYZColor color_hsv_to_xyz(HSVColor hsv)
{
    fprintf(stderr, "[%s : %d] color_hsv_to_xyz is not implemented", __FILE__, __LINE__);
    exit(-1);
}
XYZColor color_lab_to_xyz(LABColor lab)
{
    fprintf(stderr, "[%s : %d] color_lab_to_xyz is not implemented", __FILE__, __LINE__);
    exit(-1);
}

//***** convert to lab *****
LABColor color_rbg_to_lab(RBGColor rgb)
{
    fprintf(stderr, "[%s : %d] color_rbg_to_lab is not implemented", __FILE__, __LINE__);
    exit(-1);
}
LABColor color_hsv_to_lab(HSVColor hsv)
{
    fprintf(stderr, "[%s : %d] color_hsv_to_lab is not implemented", __FILE__, __LINE__);
    exit(-1);
}
LABColor color_xyz_to_lab(XYZColor xyz)
{
    fprintf(stderr, "[%s : %d] color_xyz_to_lab is not implemented", __FILE__, __LINE__);
    exit(-1);
}
