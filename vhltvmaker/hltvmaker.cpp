#include "hltvmaker.h"

char** GetAnimFNames( char* qc, INT* num_anims ) {
	FILE* pQcFile;
	char** fnames;
	char szTempStr[10];
	char* seq_str;
	INT iQcFileSize, iStartLookPos, iNumAnims;
	BYTE bByte;

	fnames = NULL;
	iStartLookPos = iNumAnims = 0;
	pQcFile = fopen( qc, "rb" );
	fseek( pQcFile, 0, SEEK_END );
	iQcFileSize = ftell( pQcFile );
	fseek( pQcFile, 0, 0 );

	for( INT i = 0; i < iQcFileSize-9; i++ ) {
		fread( szTempStr, 1, 9, pQcFile );
		szTempStr[9] = '\0';
		if( !stricmp("$sequence", szTempStr) ) {
			iStartLookPos = ftell( pQcFile );
			for( INT x = iStartLookPos; x < iQcFileSize-9; x++ ) {
				fread( &bByte, 1, 1, pQcFile );
				if( bByte == '\"' ) {
					fnames = (char**)realloc( fnames, (iNumAnims+1)*4 );
					fnames[iNumAnims] = (char*)malloc( 256 );
					for( INT c = 0; c < 64; c++ ) {
						fread( &bByte, 1, 1, pQcFile );
						if( bByte == '\"' ) {
							bByte = 0x00;
							fnames[iNumAnims][c] = bByte;
							while( bByte != '\n' ) fread( &bByte, 1, 1, pQcFile );
							break;
						}
						fnames[iNumAnims][c] = bByte;
					}
					iNumAnims++;
				}
			}
		}
		fseek( pQcFile, -8, SEEK_CUR );
	}

	fclose( pQcFile );

	*num_anims = iNumAnims;

	return fnames;
}

BOOL ProcessAnimations( char* path, char* anim_entry_str, char** anim_fnames, INT num_anims ) {
	FILE* pAnimFile;
	FILE* pNewFile;
	char szFilename[256];
	BYTE bByte;
	INT iCutAmount;
	BOOL bFoundEntry;
	char szTempStr[7];

	bByte = 0;
	iCutAmount = 0;
	bFoundEntry = FALSE;

	for( INT i = 0; i < num_anims; i++ ) {
		if( strstr(anim_fnames[i], anim_entry_str) > 0 ) {
			bFoundEntry = TRUE;
			sprintf( szFilename, "%s%s.smd", path, anim_fnames[i] );
			pAnimFile = fopen( szFilename, "rb" );
			pNewFile = fopen( "nf.tmp", "wb" );
			while( TRUE ) {
				fread( szTempStr, 1, 6, pAnimFile );
				szTempStr[6] = '\0';
				if( !stricmp("time 1", szTempStr) ) {
					iCutAmount = ftell( pAnimFile )-6;
					break;
				}
				fseek( pAnimFile, -5, SEEK_CUR );
			}
			fseek( pAnimFile, 0, 0 );

			for( INT b = 0; b < iCutAmount; b++ ) {
				fread( &bByte, 1, 1, pAnimFile );
				fwrite( &bByte, 1, 1, pNewFile );
			}

			fputs( "end\n", pNewFile );

			fclose( pAnimFile );
			fclose( pNewFile );

			remove( szFilename );
			rename( "nf.tmp", szFilename );
		}
	}

	if( !bFoundEntry ) {
		sprintf( szFilename, "Couldn't find a %s animation in the selected model-file", anim_entry_str );
		MessageBoxA( NULL, szFilename, "Error", MB_ICONERROR );
		return FALSE;
	}

	return TRUE;
}

void CopyAnims( char* path, char* anim_src, char* anim_dest, char** anim_fnames, INT num_anims ) {
	char szSrcFilename[256];
	char szFilename[256];

	for( INT i = 0; i < num_anims; i++ ) {
		if( strstr(anim_fnames[i], anim_src) > 0 ) {
			sprintf( szSrcFilename, "%s%s.smd", path, anim_fnames[i] );
			break;
		}
	}

	for( INT i = 0; i < num_anims; i++ ) {
		if( strstr(anim_fnames[i], anim_dest) > 0 ) {
			sprintf( szFilename, "%s%s.smd", path, anim_fnames[i] );
			remove( szFilename );
			CopyFileA( szSrcFilename, szFilename, TRUE );
		}
	}
}