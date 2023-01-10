
//{{BLOCK(_)

//======================================================================
//
//	_, 16x16@8, 
//	Transparent color : FF,00,FF
//	+ palette 256 entries, not compressed
//	+ 4 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 256 + 8 = 776
//
//	Time-stamp: 2023-01-11, 11:53:17
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT___H
#define GRIT___H

#define _TilesLen 256
extern const unsigned int _Tiles[64];

#define _MapLen 8
extern const unsigned short _Map[4];

#define _PalLen 512
extern const unsigned short _Pal[256];

#endif // GRIT___H

//}}BLOCK(_)
