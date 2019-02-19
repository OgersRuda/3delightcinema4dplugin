DIALOG delight_aov
{
	NAME DelightAovDialog;
    FIT_H; FIT_V; SCALE_V; SCALE_H;

     GROUP DL_AOV_IMAGE_DIALOG
      {
         COLUMNS 1;
         FIT_H; SCALE_H;

         GROUP
         {
            COLUMNS 3;
            FIT_H; SCALE_H;
            BORDERSIZE 0,0,0,4;

            STATICTEXT {NAME DL_AOV_IMAGE_MENU; SIZE -60,10; ALIGN_TOP;}
            TREEVIEW DL_AOV_IMAGE_MENU {
			FIT_H; SCALE_H; SIZE -400,-80; BORDER; FIXED_LAYOUT;		
			}
            BUTTON DL_ADD_IMAGE_LAYER {NAME DL_ADD_IMAGE_LAYER; ALIGN_TOP;}
         }

         SEPARATOR {SCALE_H;}
      }

}