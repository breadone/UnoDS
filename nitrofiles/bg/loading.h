
//{{BLOCK(loading)

//======================================================================
//
//	loading, 256x256@8, 
//	Transparent color : FF,00,FF
//	+ palette 256 entries, not compressed
//	+ 51 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 3264 + 2048 = 5824
//
//	Time-stamp: 2023-01-16, 21:09:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LOADING_H
#define GRIT_LOADING_H

#define loadingTilesLen 3264
extern const unsigned int loadingTiles[816];

#define loadingMapLen 2048
extern const unsigned short loadingMap[1024];

#define loadingPalLen 512
extern const unsigned short loadingPal[256];

#endif // GRIT_LOADING_H

//}}BLOCK(loading)
