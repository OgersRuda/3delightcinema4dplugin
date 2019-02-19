//#include "c4d.h"
//#include "c4d_symbols.h"
//#include "myres.h"
//#include "3DelightRenderer.h"
//#include <iostream>
//#include "aovtest.h"
//#include "DL_Render.h"
//#include "DL_SceneParser.h"
//#include "nsi.h"
//
//int val = 55;
//int Values::getValue() {
//	return val;
//}
//
//
//class Modal : public GeDialog {
//	INSTANCEOF(Modal, GeDialog);
//
//public:
//	virtual Bool CreateLayout();
//	virtual Bool Command(Int32 id, const BaseContainer & msg);
//};
//
//class RenderSettings : public VideoPostData
//{
//public:
//	static NodeData *Alloc(void) { return NewObjClear(RenderSettings); }
//	virtual Bool Init(GeListNode *node);
//	virtual Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);
//	virtual Bool Message(GeListNode* node , Int32 type, void* data);
//    virtual RENDERRESULT Execute(BaseVideoPost* node, VideoPostStruct* vps);
//	virtual void fireMe();
//
//};
//
//
//
//
//Bool RenderSettings::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
//{
//
//	BaseContainer* dldata = ((BaseObject*)node)->GetDataInstance();
//	switch (id[0].id)
//	{
//	case DL_FRAME_RANGE: {return dldata->GetBool(DL_FRAME_RANGE_CHECK) == false; break; }
//	case DL_FRAME_RANGE_MAX: {return dldata->GetBool(DL_FRAME_RANGE_CHECK) == false; break; }
//	case DL_FRAME_INCREMENT: {return dldata->GetBool(DL_FRAME_RANGE_CHECK) == false; break; }
//	case DL_CROP_MIN_FROM: {return dldata->GetBool(DL_IMAGE_CROP_CHECK) == false; break; }
//	case DL_CROP_MIN_TO: {return dldata->GetBool(DL_IMAGE_CROP_CHECK) == false; break; }
//	case DL_CROP_MAX_FROM: {return dldata->GetBool(DL_IMAGE_CROP_CHECK) == false; break; }
//	case DL_CROP_MAX_TO: {return dldata->GetBool(DL_IMAGE_CROP_CHECK) == false; break; }
//	}
//	return true;
//}
//
//
//Bool RenderSettings::Message(GeListNode* node, Int32 type, void* data)
//{
//	switch (type)
//	{
//	case MSG_DESCRIPTION_COMMAND:
//	{
//		DescriptionCommand* dc = (DescriptionCommand*)data;
//		BaseContainer* dldata = ((BaseVideoPost*)node)->GetDataInstance();
//	
//		if (dc->_descId[0].id == DL_CREATE_RENDER_SETTINGS)
//		{
//			ApplicationOutput(String::IntToString(dldata->GetInt32(DL_PIXEL_SAMPLES)));
//			/*Modal mdl;
//			mdl.Open(DLG_TYPE::MODAL, delight_aov, -1, -1, 500, 500);*/
//		}
//
//		break;
//	}
//
//	case MSG_DESCRIPTION_CHECKUPDATE:
//	{
//
//		BaseContainer* dldata = ((BaseVideoPost*)node)->GetDataInstance();
//		String ShadingSample = "Shading Sample: " + String::IntToString(dldata->GetInt32(DL_SHADING_SAMPLES));
//		String PixelSample = "\nPixel Sample: " + String::IntToString(dldata->GetInt32(DL_PIXEL_SAMPLES));
//		String VolumeSample = "\nVolume Sample: " + String::IntToString(dldata->GetInt32(DL_VOLUME_SAMPLES));
//		String PixelFilter = "\nPixel Filter: " + String::IntToString(dldata->GetInt32(DL_PIXEL_FILTER));
//
//		dldata->SetString(DL_TEXTEDIT, ShadingSample + PixelSample + VolumeSample+PixelFilter);
//		val = dldata->GetInt32(DL_SHADING_SAMPLES);
//	}
//
//	}
//	return true;
//}
//
//Bool RenderSettings::Init(GeListNode *node) {
//
//
//	BaseContainer* dldata = ((BaseVideoPost*)node)->GetDataInstance();
//	dldata->SetBool(DL_TEXT_CHECKER, false);
// 	dldata->SetInt32(DL_SHADING_SAMPLES, 64);
//	dldata->SetInt32(DL_PIXEL_SAMPLES, 8);
//	dldata->SetInt32(DL_VOLUME_SAMPLES, 16);
//	dldata->SetInt32(DL_PIXEL_FILTER, DL_GAUSSIAN);
//	dldata->SetFloat(DL_FILTER_WIDTH, 2.000);
//	dldata->SetBool(DL_MOTION_BLUR, true);
//	dldata->SetInt32(DL_MAX_DIFFUSE_DEPTH, 2);
//	dldata->SetInt32(DL_MAX_REFLECTION_DEPTH, 2);
//	dldata->SetInt32(DL_MAX_REFRACTION_DEPTH, 4);
//	dldata->SetInt32(DL_MAX_HAIR_DEPTH, 5);
//	dldata->SetFloat(DL_MAX_DISTANCE, 1000.000);
//
//	dldata->SetInt32(DL_CAMERA_VIEW, DL_CAMERA_PERPSHAPE);
//	dldata->SetInt32(DL_ENVIRONMENT_VIEW, DL_ENVIRONMENT_NONE);
//	dldata->SetInt32(DL_ATMOSPHERE_VIEW, DL_ATMOSPHERE_NONE);
//	dldata->SetInt32(DL_OBJECTS_TO_RENDER_VIEW, DL_OBJECTS_TO_RENDER_ALL);
//	dldata->SetInt32(DL_LIGHTS_TO_RENDER_VIEW, DL_LIGHTS_TO_RENDER_ALL);
//
//	dldata->SetBool(DL_FRAME_RANGE_CHECK, true);
//	dldata->SetFloat(DL_FRAME_RANGE, 1.000);
//	dldata->SetFloat(DL_FRAME_RANGE_MAX, 1.000);
//	dldata->SetFloat(DL_FRAME_INCREMENT, 1.000);
//
//	dldata->SetBool(DL_USE_RENDER_IMAGE_SIZE, true);
//	dldata->SetFloat(DL_CROP_MIN_FROM, 0.000);
//	dldata->SetFloat(DL_CROP_MIN_TO, 0.000);
//	dldata->SetFloat(DL_CROP_MAX_FROM, 1.000);
//	dldata->SetFloat(DL_CROP_MAX_TO, 1.000);
//
//	dldata->SetInt32(DL_DEFAULT_IMAGE_FORMAT, DL_FORMAT_OPEN_EXR);
//	dldata->SetInt32(DL_BATCH_OUTPUT_MODE, DL_ENABLE_AS_SELECTED);
//	dldata->SetInt32(DL_INTERACTIVE_OUTPUT_MODE, DL_ENABLE_AS_SELECTED_INTERACTIVE);
//
//	dldata->SetInt32(DL_RESOLUTION, DL_HALF);
//	dldata->SetInt32(DL_SAMPLING, DL_TEN_PERCENT);
//
//	dldata->SetFloat(DL_PIXEL_ASPECT_RATIO, 0);
//	
//
//	return TRUE;
//}
//
//void RenderSettings::fireMe() {
//
//}
//
//void output() {
//
//}
//
//
//Bool Modal::Command(Int32 id, const BaseContainer &msg)
//{
//
//	if (id == 125) {
//
//		BaseContainer* dldata;
//	    dldata->SetInt32(DL_SHADING_SAMPLES, 64);
//		ApplicationOutput(String::IntToString(64));
//		this->Close();
//		LayoutChanged(321);
//		EventAdd();
//	}
//
//	return true;
//}
//
//
//
//RENDERRESULT RenderSettings::Execute(BaseVideoPost* node, VideoPostStruct* vps) {
//	BaseContainer* dldata;
//	dldata = node->GetDataInstance();
//	ApplicationOutput("sdsadsa"+String::IntToString(dldata->GetInt32(DL_SHADING_SAMPLES)));
//	return RENDERRESULT::OK;
//}
//
//
//
//
//Bool My3DelightRenderPlugin(void)
//{
//	//PLUGINFLAG_VIDEOPOST_ISRENDERER
//	return RegisterVideoPostPlugin(4566456, "3Delight Renderer"_s,PLUGINFLAG_VIDEOPOST_ISRENDERER, RenderSettings::Alloc, "myres"_s, 0, 0);
//
//}
//
//Bool PluginsHelpDelegate(const maxon::String& opType, const maxon::String& baseType, const maxon::String& group, const maxon::String& property)
//{
//	if (property == "DL_CAMERA_VIEW"_s)
//		// A MessageDialog is shown. Instead, an URL to online or local help could be opened in a browser
//		MessageDialog("Any Camera or Stereo Camera Rig can be selected. If a Stereo Camera Rig is selected, both the Left and Right cameras will be rendered simultaneously"_s);
//
//	if (property == "DL_MOTION_BLUR"_s)
//		MessageDialog("This enables lienar blur with 2 samples. For motion blur with noticeable curvature, additional samples can be specified per object and set."_s);
//
//	return RegisterPluginHelpDelegate(ID_HELPPLUGIN, PluginsHelpDelegate);
//}
//
//// be sure to use a unique ID obtained from www.plugincafe.com
//
