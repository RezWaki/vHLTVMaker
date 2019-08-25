#include "hltv.h"

void CHLTVMaker::PerformSMD( String^ smd_file ) {
	array<String^, 1>^ smd_contents = IO::File::ReadAllLines( smd_file );
	array<String^, 1>^ smd_hltv = gcnew array<String^, 1>(smd_contents->Length);
	INT i = 0, iFalseLines = 0;
	for(i = 0; i < smd_contents->Length; i++){
		smd_hltv[i] = smd_contents[i];
		if( smd_contents[i] == "time 1" ) {
			i--;
			break;
		}
	}
	smd_hltv[i+1] = "end";
	IO::File::WriteAllLines( smd_file, smd_hltv);
	array<String^, 1>^ smd_fmt_contents = IO::File::ReadAllLines( smd_file );
	for(i = 0; i < smd_fmt_contents->Length; i++){
		if( smd_fmt_contents[i] == "" ) {
			iFalseLines++;
		}
		else{
			smd_hltv[i] = smd_fmt_contents[i];
		}
	}
	array<String^, 1>^ smd_clear_contents = gcnew array<String^, 1>(smd_hltv->Length-iFalseLines);
	smd_fmt_contents = IO::File::ReadAllLines( smd_file );
	for(i = 0; i < smd_fmt_contents->Length; i++){
		if( smd_fmt_contents[i] == "" ) {
			i++; //skip line
		}
		else{
			smd_clear_contents[i] = smd_fmt_contents[i];
		}
	}
	IO::File::WriteAllLines( smd_file, smd_clear_contents);
}