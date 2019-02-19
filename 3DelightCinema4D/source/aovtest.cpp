#include "c4d.h"
#include "c4d_symbols.h"
#include "../../3DelightCinema4D/project/aovtest.h"

BitmapButtonCustomGui* myButton;
Bool toogle = true;
Bool file1 = true;
Bool file2 = true;

//class Modal : public GeDialog {
//	INSTANCEOF(MODAL, GeDialog);
//	
//public:
//	Bool CreateLayout() {
//		GroupBegin(45, BFH_CENTER | BFV_CENTER, 2, 0, String(), 1, 50, 50);
//
//		BaseContainer customgui;
//
//		AddEditText(124, BFV_CENTER, 100, 0);
//		AddButton(125, BFV_CENTER, 100, 0, "Send Value"_s);
//		return true;
//	}
//
//	Bool Command(Int32 id, const BaseContainer & msg) {
//		if (id == 125) {
//			String text;
//			GetString(124, text);
//			SetString(25, text);
//			ApplicationOutput(text);
//			this->Close();
//		}
//		return true;
//	}
//};


class AOVDIALOG : public GeDialog {
	INSTANCEOF(AOVDIALOG, GeDialog);
public:

	Bool CreateLayout() {
	
		GroupBegin(44, BFH_CENTER | BFV_CENTER, 2, 0, String(), 1,10,10);
	
		BaseContainer customgui;

		GroupBorder(BORDER_BLACK);
		customgui.SetBool(BITMAPBUTTON_TOGGLE, true);
		Filename fn = GeGetC4DPath(C4D_PATH_DESKTOP) + Filename("image.png");
		customgui.SetFilename(3123,fn);
		customgui.SetBool(DESCRIPTION_ALLOWFOLDING, true);
		myButton = (BitmapButtonCustomGui*)AddCustomGui(3123, CUSTOMGUI_BITMAPBUTTON, "3Delight"_s, BFH_CENTER | BFV_CENTER,100, 30, customgui);
		myButton->SetImage(fn, false);
		LayoutChanged(10042);

		AddStaticText(25, BFV_CENTER, 250, 0, "Press button to change me"_s, FONT_MONOSPACED);
		GroupEnd();
		return true;
	}

	Bool Command(Int32 id, const BaseContainer & msg) {
	
		//if (id == 3123) {
		//	ApplicationOutput("Button Pressed");
		//	Filename fn = GeGetC4DPath(C4D_PATH_DESKTOP) + Filename("image.png");
		//	Filename fn2 = GeGetC4DPath(C4D_PATH_DESKTOP) + Filename("image2.jpg");
		//	myButton->SetToggleState(toogle);
		//	toogle = !toogle;
		//	myButton->SetImage(fn, file1);
		//	myButton->SetImage(fn2, !file2);
		//	if (file1 == false) {
		//		SetString(25, "This is the first Image"_s);
		//	}
		//	else {
		//		SetString(25, "This is the second Image"_s);
		//	}
		//	file1 = !file1;
		//	file2 = !file2;
		//	//LayoutChanged(10042);
		//	EventAdd();
		//	

		//}

		//if (id == 123) {
		//	ApplicationOutput("Changed"_s);
		//	Int32 val = -1;
		//	GetInt32(123, val);
		//	if (val < 0)
		//		return false;
		//	ApplicationOutput(String::IntToString(val));
		//	
		//}
		return true;
	
	}
};


class AOV_GROUP : public ObjectData
{
	INSTANCEOF(render_generator, CommandData);
public:
	AOVDIALOG dlg1;
	virtual Bool Init(GeListNode* doc);
	static NodeData* Alloc() {
	return NewObjClear(AOV_GROUP);
	}


};



Bool AOV_GROUP::Init(GeListNode* doc)
{
	if (dlg1.IsOpen() == false)
	{
		dlg1.Open(DLG_TYPE::ASYNC, 12, -1, -1, 600, 400);
	}
	else
		dlg1.Close();

	return true;
}





Bool RegisterAovGroup()
{
	// be sure to use a unique ID obtained from www.plugincafe.com

	return RegisterObjectPlugin(53454367, "Aov Test"_s, 0 ,AOV_GROUP::Alloc ,"klm"_s,AutoBitmap("porcupinemodifier.tif"_s),0); //NewObjClear (gNew in R12)
}