
//{{BLOCK(bottom)

//======================================================================
//
//	bottom, 256x256@8, 
//	Transparent color : FF,00,FF
//	+ palette 256 entries, not compressed
//	+ 2 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 128 + 2048 = 2688
//
//	Time-stamp: 2023-01-11, 10:46:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BOTTOM_H
#define GRIT_BOTTOM_H

#define bottomTilesLen 128
extern const unsigned int bottomTiles[32];

#define bottomMapLen 2048
extern const unsigned short bottomMap[1024];

#define bottomPalLen 512
extern const unsigned short bottomPal[256];

#endif // GRIT_BOTTOM_H

//}}BLOCK(bottom)
