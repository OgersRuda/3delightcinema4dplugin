// Empty template for C4d plugins, R17

#include "c4d.h"
#include <string.h>

#include "c4d.h"
#include "PluginManager.h"
#include "BitmapDisplayDriver.h"
#include "CameraHook.h"
#include "RenderOptionsHook.h"
#include "DisplayTranslator.h"
#include "VisibilityTagTranslator.h"
#include "IDs.h"

//Global plugin manager, 
//Stores pointers to allocators for translator plugins
PluginManager PM;

Bool RegisterRenderFrame(void);
Bool RegisterRenderSequence(void);
//Bool RegisterInteractiveRenderManager(void);
Bool RegisterDisplay(void);
//Bool RegisterImageLayer(void);
Bool RegisterDL_CameraTag(void);
Bool RegisterDL_MotionBlurTag(void);
Bool RegisterDL_VisibilityTag(void);
Bool Register3DelightPlugin(void);
Bool ShowLight(void);
Bool RegisterCustomListView(void);

Bool PluginStart(void)
{

	//if (!RegisterCustomGUITest()) return FALSE;
	if (!RegisterRenderFrame()) return FALSE;
	if (!RegisterRenderSequence()) return FALSE;
	if (!Register3DelightPlugin()) return FALSE;
	//if (!RegisterInteractiveRenderManager())return FALSE;
	if (!RegisterDisplay()) return FALSE;
	if (!ShowLight()) return FALSE;
	//if (!RegisterDL_CameraTag()) return FALSE;
	//if (!RegisterDL_MotionBlurTag()) return FALSE;
	if (!RegisterDL_VisibilityTag()) return FALSE;
	if (!RegisterCustomListView()) return FALSE;
	//Register 3Delight display driver for rendering to C4D bitmaps
	PtDspyDriverFunctionTable table;
	memset(&table, 0, sizeof(table));
	table.Version = 1;
	table.pOpen = &BmpDspyImageOpen;
	table.pQuery = &BmpDspyImageQuery;
	table.pWrite = &BmpDspyImageData;
	table.pClose = &BmpDspyImageClose;
	
	PtDspyError err = DspyRegisterDriverTable("C4D_bitmap", &table); 
	
	return true;
}

void PluginEnd(void)
{

}

Bool PluginMessage(Int32 id, void* data)
{
	switch (id)
	{
	case C4DPL_INIT_SYS:
		if (!g_resource.Init())
			return false;		// don't start plugin without resource
		return true;

	case C4DPL_STARTACTIVITY:
		//Send message to load translators from other plugins
		GePluginMessage(DL_LOAD_PLUGINS, (void*)&PM);
		break;

	case DL_LOAD_PLUGINS:
		DL_PluginManager* pm = (DL_PluginManager*)data;
		pm->RegisterHook(AllocateHook<CameraHook>);
		pm->RegisterHook(AllocateHook<RenderOptionsHook>);
		pm->RegisterTranslator(ID_DISPLAY, AllocateTranslator<DisplayTranslator>);
		pm->RegisterTranslator(ID_DL_VISIBILITYTAG, AllocateTranslator<VisibilityTagTranslator>);
		//pm->RegisterTranslator(,AllocateTranslator<QualityValuesParser>);
		break;

	}

	return false;
}
