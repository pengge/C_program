#ifndef	_DJCVT_H_
#define	_DJCVT_H_

#ifdef __cplusplus
extern "C" {
#endif


int WINAPI PcmtoWave(char* PcmFileName,char* WaveFileName);
int WINAPI WavetoPcm(char* WaveFileName,char* PcmFileName);
int WINAPI AdtoPcm(char* AdpcmFileName,char* PcmFileName);
int WINAPI PcmtoAd(char* PcmFileName,char* AdpcmFileName);
int WINAPI Ad6ktoPcm(char* AdpcmFileName,char* PcmFileName);


#ifdef __cplusplus
}
#endif


#endif