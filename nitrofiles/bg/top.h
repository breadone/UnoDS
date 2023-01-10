
//{{BLOCK(top)

//======================================================================
//
//	top, 256x256@8, 
//	Transparent color : FF,00,FF
//	+ palette 256 entries, not compressed
//	+ 22 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 1408 + 2048 = 3968
//
//	Time-stamp: 2023-01-11, 10:42:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TOP_H
#define GRIT_TOP_H

#define topTilesLen 1408
extern const unsigned int topTiles[352];

#define topMapLen 2048
extern const unsigned short topMap[1024];

#define topPalLen 512
extern const unsigned short topPal[256];

#endif // GRIT_TOP_H

//}}BLOCK(top)
