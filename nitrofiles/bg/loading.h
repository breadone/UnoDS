
//{{BLOCK(loading)

//======================================================================
//
//	loading, 512x256@8, 
//	Transparent color : FF,00,FF
//	+ palette 256 entries, not compressed
//	+ 58 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 3712 + 4096 = 8320
//
//	Time-stamp: 2023-01-16, 10:20:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LOADING_H
#define GRIT_LOADING_H

#define loadingTilesLen 3712
extern const unsigned int loadingTiles[928];

#define loadingMapLen 4096
extern const unsigned short loadingMap[2048];

#define loadingPalLen 512
extern const unsigned short loadingPal[256];

#endif // GRIT_LOADING_H

//}}BLOCK(loading)
