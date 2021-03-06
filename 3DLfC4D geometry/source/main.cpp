#include "c4d.h"
#include <string.h>
#include "DL_API.h"
#include "PolygonObjectTranslator.h"
#include "BaseObjectTranslator.h"

Bool PluginStart(void)
{

	return true;
}

void PluginEnd(void)
{

}

Bool PluginMessage(Int32 id, void *data)
{
	switch (id)
	{
	case C4DPL_INIT_SYS:
		if (!g_resource.Init()) return FALSE; // don't start plugin without resource
		return TRUE;
		break;

	case DL_LOAD_PLUGINS:
		DL_PluginManager* pm = (DL_PluginManager*)data;

		pm->RegisterTranslator(Opolygon, AllocateTranslator<PolygonObjectTranslator>);
		pm->RegisterTranslator(Oalembicgenerator, AllocateTranslator<PolygonObjectTranslator>);
		pm->RegisterTranslator(Ocube, AllocateTranslator<PolygonObjectTranslator>);
		pm->RegisterTranslator(Ocylinder, AllocateTranslator<PolygonObjectTranslator>);
		pm->RegisterTranslator(Osphere, AllocateTranslator<PolygonObjectTranslator>);
		pm->RegisterTranslator(Olight, AllocateTranslator<PolygonObjectTranslator>);
		pm->RegisterTranslator(Odisc, AllocateTranslator<PolygonObjectTranslator>);

		break;

	}
	return FALSE;
}
