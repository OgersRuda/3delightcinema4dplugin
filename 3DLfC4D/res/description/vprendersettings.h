#ifndef _VPRENDERSETTINGS_H_
#define _VPRENDERSETTINGS_H_

enum
{
	DL_GROUP_QUALITY			=	1000,
	DL_GENERAL_MODE,
	DL_MODE_SCANLINE,
	DL_MODE_RAYTRACER,
	DL_MODE_PROGRESSIVE,
	DL_PIXELSAMPLES,	
	DL_PIXELSAMPLES_Y,	
	DL_SHADINGRATE,
	DL_PIXELFILTER,
	DL_FILTERWIDTH,
	DL_FILTER_BOX,
	DL_FILTER_TRIANGLE,
	DL_FILTER_CATMULL_ROM,
	DL_FILTER_MITCHELL,
	DL_FILTER_BLACKMANN_HARRIS,
	DL_FILTER_BESSEL,
	DL_FILTER_SINC,
	DL_FILTER_GAUSSIAN,
	DL_GROUP_CAMERA				=	3000,
	DL_USE_MOTION_BLUR,
	DL_MOTION_SAMPLES,
	DL_TRANSFORMATION_SAMPLES,
	DL_DEFORMATION_SAMPLES,
	DL_SHUTTER_ANGLE,
	DL_SHUTTER_OPENING_EFFICIENCY,
	DL_SHUTTER_CLOSING_EFFICIENCY,
	DL_GROUP_OUTPUT				=	4000,
	DL_SAVE_IMAGE,
	DL_RENDERMODE,
	DL_MODE_DIRECT,
	DL_MODE_STREAM,
	DL_SHOW_IMAGE,
	DL_OUTPUTFILE,
	DL_RIBOUT,
	DL_GROUP_RAYTRACING			=	5000,
	DL_TRACE_BIAS				=	5001,
	DL_MAX_SAMPLES				=	5002,
	DL_MIN_SAMPLES				=	5003,
	DL_RAYCACHE				=	5004,
	DL_SHADING_SAMPLES			=	5005,
	DL_MAX_DIFFUSE_DEPTH		=	5007,
	DL_MAX_SPECULAR_DEPTH		=	5008,
	DL_MAX_REFLECTION_DEPTH		=	5009,
	DL_MAX_REFRACTION_DEPTH		=	5010,
	DL_GROUP_LWF				=	6000,
	DL_GAMMA					=	6001
};

#endif