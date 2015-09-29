#ifndef DEEPMTCHINFO_H
#define DEEPMTCHINFO_H
#include "std.h"
#include "image.h"
#include "io.h"
#include "deep_matching.h"

#define EXE_OPTIONS 0
#define MATLAB_OPTIONS 1
#define PYTHON_OPTIONS 2

class deepMtchInfo
{
public:
    deepMtchInfo();
    void usage(const int language);
    bool endswith(const char *str, const char *suffix);
    image_t* rescale_image( image_t* im, int width, int height);
    void initialization(dm_params_t *params, \
                 scalerot_params_t *sr_params, bool *use_scalerot, \
                 float *fx, float *fy, int argc, char **argv, \
                 const int language, image_t **im1, image_t **im2,
                 const char* out_filename);
};

#endif // DEEPMTCHINFO_H
