#include "ofMain.h"

extern "C"
{
#include "fitz-internal.h"
}

#define NOT_IMPL() \
ofLogVerbose("ofxPDF") << "not implemented: " << __PRETTY_FUNCTION__;

struct fz_ofpath_device
{
	vector< ofPtr<ofPath> > *paths;
	ofMatrix4x4 mat;
};

static ofPath& get_current_path(fz_device *dev)
{
	fz_ofpath_device *ddev = (fz_ofpath_device*)dev->user;
	return *ddev->paths->back();
}

static ofPath& create_path(fz_device *dev)
{
	fz_ofpath_device *ddev = (fz_ofpath_device*)dev->user;
	ddev->paths->push_back(ofPtr<ofPath>(new ofPath));
	return *ddev->paths->back();
}

static ofMatrix4x4& get_current_matrix(fz_device *dev)
{
	fz_ofpath_device *ddev = (fz_ofpath_device*)dev->user;
	return ddev->mat;
}

static void
ofpath_matrix(fz_device *dev, fz_matrix ctm)
{
	ofMatrix4x4 &mat = get_current_matrix(dev);
	mat.set(ctm.a, ctm.b, 0, 0,
			ctm.c, ctm.d, 0, 0,
			0, 0, 1, 0,
			ctm.e, ctm.f, 0, 1);
}

static void
ofpath_trm(fz_matrix trm)
{
	NOT_IMPL();
}

static ofFloatColor
ofpath_color(fz_device *dev, fz_colorspace *colorspace, float *color, float alpha)
{
	ofPath &p = get_current_path(dev);
	
	float rgb[3];
	colorspace->to_rgb(dev->ctx, colorspace, color, rgb);
	
	return ofFloatColor(rgb[0], rgb[1], rgb[2], alpha);
}

static void
ofpath_path(fz_device *dev, fz_path *path)
{
	ofPath &p = get_current_path(dev);
	ofMatrix4x4 &mat = get_current_matrix(dev);
	ofPoint cp1, cp2, pp;
	
	float x, y;
	int i = 0;
	int n;
	while (i < path->len)
	{
		switch (path->items[i++].k)
		{
			case FZ_MOVETO:
				x = path->items[i++].v;
				y = path->items[i++].v;
				p.moveTo(mat.preMult(ofVec3f(x, y)));
				break;
			case FZ_LINETO:
				x = path->items[i++].v;
				y = path->items[i++].v;
				p.lineTo(mat.preMult(ofVec3f(x, y)));
				break;
			case FZ_CURVETO:
				x = path->items[i++].v;
				y = path->items[i++].v;
				cp1.set(mat.preMult(ofVec3f(x, y)));
				x = path->items[i++].v;
				y = path->items[i++].v;
				cp2.set(mat.preMult(ofVec3f(x, y)));
				x = path->items[i++].v;
				y = path->items[i++].v;
				pp.set(mat.preMult(ofVec3f(x, y)));
				p.bezierTo(cp1, cp2, pp);
				break;
			case FZ_CLOSE_PATH:
				p.close();
				break;
		}
	}
}

static void
ofpath_fill_path(fz_device *dev, fz_path *path, int even_odd, fz_matrix ctm,
				 fz_colorspace *colorspace, float *color, float alpha)
{
	ofPath &p = create_path(dev);
	p.setFilled(true);
	p.setFillColor(ofpath_color(dev, colorspace, color, alpha));
	
	ofpath_matrix(dev, ctm);
	ofpath_path(dev, path);
}

static void
ofpath_stroke_path(fz_device *dev, fz_path *path, fz_stroke_state *stroke, fz_matrix ctm,
				   fz_colorspace *colorspace, float *color, float alpha)
{
	ofPath &p = create_path(dev);
	p.setFilled(false);

	p.setStrokeColor(ofpath_color(dev, colorspace, color, alpha));
	p.setStrokeWidth(stroke->linewidth);
		
	ofpath_matrix(dev, ctm);
	
	ofpath_path(dev, path);
}

static void
ofpath_clip_path(fz_device *dev, fz_path *path, fz_rect *rect, int even_odd, fz_matrix ctm)
{
	NOT_IMPL();
}

static void
ofpath_clip_stroke_path(fz_device *dev, fz_path *path, fz_rect *rect, fz_stroke_state *stroke, fz_matrix ctm)
{
	NOT_IMPL();
}

static void
ofpath_fill_text(fz_device *dev, fz_text *text, fz_matrix ctm,
				 fz_colorspace *colorspace, float *color, float alpha)
{
	NOT_IMPL();
}

static void
ofpath_stroke_text(fz_device *dev, fz_text *text, fz_stroke_state *stroke, fz_matrix ctm,
				   fz_colorspace *colorspace, float *color, float alpha)
{
	NOT_IMPL();
}

static void
ofpath_clip_text(fz_device *dev, fz_text *text, fz_matrix ctm, int accumulate)
{
	NOT_IMPL();
}

static void
ofpath_clip_stroke_text(fz_device *dev, fz_text *text, fz_stroke_state *stroke, fz_matrix ctm)
{
	NOT_IMPL();
}

static void
ofpath_ignore_text(fz_device *dev, fz_text *text, fz_matrix ctm)
{
	NOT_IMPL();
}

static void
ofpath_fill_image(fz_device *dev, fz_image *image, fz_matrix ctm, float alpha)
{
	NOT_IMPL();
}

static void
ofpath_fill_shade(fz_device *dev, fz_shade *shade, fz_matrix ctm, float alpha)
{
	NOT_IMPL();
}

static void
ofpath_fill_image_mask(fz_device *dev, fz_image *image, fz_matrix ctm,
					   fz_colorspace *colorspace, float *color, float alpha)
{
	NOT_IMPL();
}

static void
ofpath_clip_image_mask(fz_device *dev, fz_image *image, fz_rect *rect, fz_matrix ctm)
{
	NOT_IMPL();
}

static void
ofpath_pop_clip(fz_device *dev)
{
	NOT_IMPL();
}

static void
ofpath_begin_mask(fz_device *dev, fz_rect bbox, int luminosity, fz_colorspace *colorspace, float *color)
{
	NOT_IMPL();
}

static void
ofpath_end_mask(fz_device *dev)
{
	NOT_IMPL();
}

static void
ofpath_begin_group(fz_device *dev, fz_rect bbox, int isolated, int knockout, int blendmode, float alpha)
{
	NOT_IMPL();
}

static void
ofpath_end_group(fz_device *dev)
{
	NOT_IMPL();
}

static void
ofpath_begin_tile(fz_device *dev, fz_rect area, fz_rect view, float xstep, float ystep, fz_matrix ctm)
{
	NOT_IMPL();
}

static void
ofpath_end_tile(fz_device *dev)
{
	NOT_IMPL();
}

fz_device *fz_new_ofpath_device(fz_context *ctx, vector< ofPtr<ofPath> > &paths)
{
	fz_ofpath_device *ddev = fz_malloc_struct(ctx, fz_ofpath_device);
	ddev->paths = &paths;
	
	fz_device *dev = fz_new_device(ctx, ddev);
	
	dev->fill_path = ofpath_fill_path;
	dev->stroke_path = ofpath_stroke_path;
	dev->clip_path = ofpath_clip_path;
	dev->clip_stroke_path = ofpath_clip_stroke_path;
	
	dev->fill_text = ofpath_fill_text;
	dev->stroke_text = ofpath_stroke_text;
	dev->clip_text = ofpath_clip_text;
	dev->clip_stroke_text = ofpath_clip_stroke_text;
	dev->ignore_text = ofpath_ignore_text;
	
	dev->fill_shade = ofpath_fill_shade;
	dev->fill_image = ofpath_fill_image;
	dev->fill_image_mask = ofpath_fill_image_mask;
	dev->clip_image_mask = ofpath_clip_image_mask;
	
	dev->pop_clip = ofpath_pop_clip;
	
	dev->begin_mask = ofpath_begin_mask;
	dev->end_mask = ofpath_end_mask;
	dev->begin_group = ofpath_begin_group;
	dev->end_group = ofpath_end_group;
	
	dev->begin_tile = ofpath_begin_tile;
	dev->end_tile = ofpath_end_tile;
	
	return dev;
}
