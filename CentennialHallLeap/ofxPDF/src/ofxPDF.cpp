#include "ofxPDF.h"

extern "C"
{
#include "fitz.h"
}

extern fz_device *fz_new_ofpath_device(fz_context *ctx, vector< ofPtr<ofPath> > &paths);

ofxPDF::~ofxPDF()
{
	close();
}

void ofxPDF::loadPDF(string path, int pagenumber)
{
	close();
	
	path = ofToDataPath(path);
	
	fz_context *ctx = fz_new_context(NULL, NULL, FZ_STORE_UNLIMITED);
	fz_document *doc = fz_open_document(ctx, (char*)path.c_str());
	
	int pagecount = fz_count_pages(doc);
	fz_page *page = fz_load_page(doc, pagenumber - 1);
	
	fz_rect rect = fz_bound_page(doc, page);
	
	width = rect.x1 - rect.x0;
	height = rect.y1 - rect.y0;
	
	fz_device *dev = fz_new_ofpath_device(ctx, paths);
	fz_run_page(doc, page, dev, fz_identity, NULL);
	fz_free_device(dev);
	
	fz_free_page(doc, page);
	fz_close_document(doc);
	fz_free_context(ctx);
}

void ofxPDF::close()
{
	paths.clear();
}

void ofxPDF::draw()
{
	for (int i = 0; i < paths.size(); i++)
	{
		paths[i]->draw();
	}
}