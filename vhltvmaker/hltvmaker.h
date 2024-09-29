#include <Windows.h>
#include <stdio.h>

char** GetAnimFNames( char* qc, INT* num_anims );
BOOL ProcessAnimations( char* path, char* anim_entry_str, char** anim_fnames, INT num_anims );
void CopyAnims( char* path, char* anim_src, char* anim_dest, char** anim_fnames, INT num_anims );